#!/bin/sh

# Colors
RED='\033[0;31;01m'
GREEN='\033[0;32;01m'
YELLOW='\033[0;33;01m'
BLUE='\033[0;34;01m'
MAGENTA='\033[0;35;01m'
NC='\033[0m'

# Parameters
TMPL_FOLDER_PATH=../templates
TMPL_LAUNCHER_FILE_NAME=000_launcher_template.c
TMPL_LAUNCHER=$TMPL_FOLDER_PATH/$TMPL_LAUNCHER_FILE_NAME
TMPL_TEST_FILE_NAME=XXX_test_template.c
TMPL_TEST=$TMPL_FOLDER_PATH/$TMPL_TEST_FILE_NAME
TMPL_HEADER_FILE_NAME=header_template.h
TMPL_HEADER=$TMPL_FOLDER_PATH/$TMPL_HEADER_FILE_NAME
TMPL_MAIN_FILE_NAME=main_template.h
TMPL_MAIN=$TMPL_FOLDER_PATH/$TMPL_MAIN_FILE_NAME
INCLUDES_PATH=includes
MAKEFILE_FILE=file_paths;
TESTS_FILE=tests.txt
BAK_FOLDER=backup

# Print error message
print_err(){
    printf "${RED}%s${NC}\n" "$1"
}

# Print message ok
print_ok(){
    printf "${GREEN}%s${NC}\n" "$1"
}

# Print warning message
print_warn(){
    printf "${YELLOW}%s${NC}\n" "$1"
}

# Check if folder given as argument exits
folder_exists(){
	[ -d "$1" ] && return 1 || return 0
}

# Save folder content in the backup folder
save_folder(){
#	echo "Saving ${BLUE}$1${NC} folder in ${BLUE}$BAK_FOLDER${NC} folder..."
	cp -R $1 $BAK_FOLDER
	if [ $? -ne 0 ]; then
		print_err "Error: could not save $1 folder."
		return -1;
	fi
}

create_folder(){
	echo "Making ${BLUE}$1${NC} folder..."
	mkdir $1
	folder_exists $1
	if [ "$?" -eq 1 ]; then
		print_ok "$1 folder succesfully created" 
	else
		print_err "Error: could not create $1."
		return -1
	fi
	return 0
}

remove_folder(){
	if [ -d $1 ]; then
		save_folder $1
		[ $? -ne 0 ] && return -1
		echo "Removing ${BLUE}$1${NC} folder..."
		rm -rf $1
		return 0;
	else
		echo "${BLUE}$1${NC} already removed."
		return -1
	fi
}

remove_all(){
#	echo "Removing all folders..."
	create_folder $BAK_FOLDER
	[ "$?" -ne 0 ] && return -1
	for fct in "$@"
	do
		remove_folder $fct
	done
}

replace_fct_name(){
	local fct_name="$1"
	sed "s/TMPL_FCT_NAME/${fct_name}/" $fct_name/000_launcher.c > $fct_name/000_launcher_tmp.c
	rm -f $fct_name/000_launcher.c
	mv $fct_name/000_launcher_tmp.c $fct_name/000_launcher.c
}

load_test(){
	local fct_name="$1"
	local test_fct="$2"
	local test_name=`echo "$3" | sed 's/"/\\\\\\\"/g'`
	sed "s/\/\*LOAD_TEST_HERE\*\//if ((err = load_test(\&test_list, \"${test_name}\","$'\\\n\\\t\\\t\\\t'"\&${fct_name}_${test_fct}, SUCCESS)))"$'\\\n\\\t\\\t'"return (err);"$'\\\n\\\t'"&/" \
		$fct_name/000_launcher.c > $fct_name/000_launcher_tmp.c
	if [ "$?" -ne 0 ]; then
		print_err "Sed error with ${fct_name}/${test_fct}.c"
		exit
	fi
	rm -f $fct_name/000_launcher.c
	mv $fct_name/000_launcher_tmp.c $fct_name/000_launcher.c
}

add_template_to_folder(){
	local fct_name=$1
	echo "Adding 000_launcher.c template to ${BLUE}$fct_name${NC} folder..."
	cp $TMPL_LAUNCHER $fct_name/000_launcher.c
}

create_test(){
	local fct_name="$1"
	local test_fct="$2"
	local args="$3"
	local index="$4"

	echo "Creating test file ${BLUE}${index}_${test_fct}.c${NC} in ${BLUE}${fct_name}${NC} folder..."
	cp ${TMPL_TEST} ${fct_name}/${index}_${test_fct}.c
	sed -e "s/TMPL_FCT_NAME/${fct_name}/" -e "s/TMPL_TEST_FCT_NAME/${test_fct}/" -e "s/TMPL_ARGS/${args}/" ${fct_name}/${index}_${test_fct}.c > ${fct_name}/${index}_${test_fct}_tmp.c
	rm -f ${fct_name}/${index}_${test_fct}.c
	mv ${fct_name}/${index}_${test_fct}_tmp.c ${fct_name}/${index}_${test_fct}.c
}

add_prototypes(){
	local fct_name="$1"
	local test_fct="$2"

	if [ ! -f ${fct_name}/${fct_name}.h ]; then
#		echo "Adding ${BLUE}${fct_name}.h${NC} from template file..."
		cp ${TMPL_HEADER} ${fct_name}/${fct_name}.h
		sed "s/TMPL_FCT_NAME/${fct_name}/" ${fct_name}/${fct_name}.h > ${fct_name}/${fct_name}_tmp.h
		rm -rf ${fct_name}/${fct_name}.h
		mv ${fct_name}/${fct_name}_tmp.h ${fct_name}/${fct_name}.h
	fi
#	echo "Adding prototype for ${BLUE}${test_fct}${NC} test in ${BLUE}${fct_name}.h${NC}..."
	sed "s/\/\*PROTOTYPES_HERE\*\//int"$'\\\t'"${fct_name}_${test_fct}(void);"$'\\\n'"&/" ${fct_name}/${fct_name}.h > ${fct_name}/${fct_name}_tmp.h
	rm -f ${fct_name}/${fct_name}.h
	mv ${fct_name}/${fct_name}_tmp.h ${fct_name}/${fct_name}.h
}

save_file_path(){
	local fct_name="$1"
	local file_name="$2"
#	echo "Adding ${BLUE}${fct_name}/${file_name}${NC} to ${BLUE}${MAKEFILE_FILE}${NC}..."
	echo "${fct_name}/${file_name} \\" >> $MAKEFILE_FILE
}

add_fct_in_main(){
	local fct_name="$1"
	sed -e "s/\/\*FCTS_HERE\*\//{\"${fct_name}\", ${fct_name}_launcher},"$'\\\n\\\t'"&/" -e "s/\/\*PROTOTYPES_HERE\*\//int"$'\\\t'"${fct_name}_launcher(void);"$'\\\n'"&/" $INCLUDES_PATH/main.h > $INCLUDES_PATH/main_tmp.h
	rm -f $INCLUDES_PATH/main.h
	mv $INCLUDES_PATH/main_tmp.h $INCLUDES_PATH/main.h
}

test_exists(){
	[ -f "$1" ] && return 1 || return 0
}

is_in_list(){
	haystack="$1"
	shift
	local list="$@"
	for elm in $list
	do
		if [ "$haystack" = ${elm} ]; then
			return 1;
		fi
	done
	return 0;
}

is_test_list_ok(){
	TEST_LIST_ERRORS=""
	list_ref=`cat $TESTS_FILE | cut -d';' -f1 | uniq`
	for elm in "$@"
	do
		local save_elm=$elm
		is_in_list $elm $list_ref
		if [ "$?" -ne 1 ]; then
			TEST_LIST_ERRORS=`echo $TEST_LIST_ERRORS $save_elm`
		fi
	done
}

# Remove the file given in argument and rename the temporary version with the
# name of the deleted file.

update_file(){
	if [ "$#" -ne 1 ]; then
		print_err "Wrong number of arguments"
	else
		rm -rf "$1"
		mv "$1_tmp" "$1"
	fi
}

generate_tests(){
	local no_makefile=false
	local fcts="$@"
	if $CREATE || [ ! -f ${MAKEFILE_FILE} ]; then
		no_makefile=true
		printf "" > ${MAKEFILE_FILE}
		cp ${TMPL_MAIN} ./$INCLUDES_PATH/main.h
	else
		sed '$ s/$/ \\/' ${MAKEFILE_FILE} > ${MAKEFILE_FILE}_tmp
		update_file ${MAKEFILE_FILE}
	fi
	for fct in $fcts
	do
		if [ ! -d $fct ]; then
			create_folder $fct
		fi
		if [ ! -f ${fct}/000_launcher.c ] || $CREATE; then
			add_template_to_folder $fct
			replace_fct_name $fct
		fi
		launcher_added=`cat ${MAKEFILE_FILE} | grep ${fct}/000_launcher | wc -l | bc`
		if [ "$launcher_added" -eq 0 ]; then
			save_file_path "$fct" "000_launcher"
			add_fct_in_main "$fct"
		fi
		tests=`grep -w $fct ${TESTS_FILE} | cut -d';' -f2`
		nb_existing_tests=`ls $fct | grep .c$ | grep -v 000_ | wc -l | bc`
		if [ "$nb_existing_tests" -eq 0 ] || $CREATE; then
			local index=1
		else
			local index=`ls $fct | grep .c$ | cut -c -3 | tail -1`
		fi
		for test_fct in $tests
		do
			local index_pref=`printf %03d $index`
			test_exist=`ls $fct | grep .c$ | cut -c 5- | grep -w ${test_fct}\.c | wc -l | bc`
			if  [ $test_exist -eq 0 ] || $CREATE; then
				test_name=`grep -w $fct ${TESTS_FILE} | grep -w $test_fct |  cut -d';' -f3`	
				create_test "$fct" "$test_fct" "$test_name" "$index_pref"
				load_test "$fct" "$test_fct" "$test_name"
				add_prototypes "$fct" "$test_fct"
			else
				echo "${BLUE}${test_fct}.c${NC} already exists."
			fi
			test_added=`cat ${MAKEFILE_FILE} | grep -w ${fct}/....${test_fct} | wc -l | bc`
			if [ "$test_added" -eq 0 ]; then
				if $no_makefile && [ $test_exist -ne 0 ]; then
					index_pref=`ls $fct | grep -w ....${test_fct}\.c | cut -c -3`
				fi
				save_file_path "$fct" "${index_pref}_${test_fct}"
			fi
			((index++))
		done
	done
	if $CREATE || $no_makefile; then
		sed -e "1s/^/SRC_NAME += /" ${MAKEFILE_FILE} > ${MAKEFILE_FILE}_tmp
		update_file ${MAKEFILE_FILE}
	fi	
	sed "$ s/ \\\//" ${MAKEFILE_FILE} > ${MAKEFILE_FILE}_tmp
	update_file ${MAKEFILE_FILE}
}

clean_tests(){
#	echo "Removing ${BLUE}$BAK_FOLDER${NC}..."
	rm -rf $BAK_FOLDER
	remove_all "$@"
#	echo "Removing ${BLUE}${MAKEFILE_FILE}${NC}"
	rm -f ${MAKEFILE_FILE}
	rm -f ${INCLUDES_PATH}/main.h
}

launch_tests(){
	echo "Compiling all the tests... This might take up to 1 minute."
	make test
}

parse_args(){
	if [ "$#" -lt 2 ]; then
		ERR=true
		return -1
	fi
	local action=$1
	if [ $action = "create" ]; then
		CREATE=true
	elif [ $action = "update" ]; then
		UPDATE=true
	elif [ $action = "clean" ]; then
		CLEAN=true
	else
		ERR=true
		return -1
	fi
	shift
	while [ "$#" -gt 0 ]
	do
		if [ "$1" = "all" ]; then
			ALL=true
			return 0
		elif [ "$1" = "mandatory" ]; then
			MANDATORY=true
			return 0
		else
			TESTS_LIST=`echo $TESTS_LIST $1`
		fi
		shift
	done
	return 0
}

display_usage(){
	printf "Usage: ./generator.sh [action] [type]\n"
	printf "   > actions:\n"
	printf "   %s\n" "    - create                  Create tests."
	printf "   %s\n" "    - update                  Update tests (add new ones)."
	printf "   %s\n" "    - clean                   Clean tests."
	printf "   > type:\n"
	printf "   %s\n" "    - all                     All tests are affected."
	printf "   %s\n" "    - mandatory               All mandatory tests (cspdiouxXf) are affected."
	printf "   %s\n" "    - types                   Only named types after action keyword are affected."
	printf "Examples:\n" 
	printf " 1) %s\n" "./generator.sh create all > create all the tests for all the types"
	printf " 2) %s\n" "./generator.sh create mandatory > create all the tests for the mandatory types"
	printf " 3) %s\n" "./generator.sh create mix no_type conv_d > create the tests for the types mix, no_type and conv_d"
}

# Checks that the names of the tests are all unique.

check_test_file(){
	nb_duplicates=`cat $TESTS_FILE | cut -d';' -f-2 | uniq -d | wc -l | bc`
	if [ "$nb_duplicates" -gt 0 ]; then
		print_err "Error: duplicated tests found:"
		echo "  >" `cat $TESTS_FILE | cut -d';' -f-2 | uniq -d`
		print_err "Change one of the test name or delete it."
		exit
	fi
}

# ----- SCRIPT -----

ARGS_LIST="$@"
ERR=false
ALL=false
CREATE=false
CLEAN=false
UPDATE=false
MANDATORY=false

parse_args $ARGS_LIST

if $ERR; then
	display_usage
	exit
fi

if $ALL; then
	TESTS_LIST=`cat $TESTS_FILE | cut -d';' -f1 | uniq`
elif $MANDATORY; then
	TESTS_LIST="no_type conv_d conv_i conv_u conv_o conv_x conv_cap_x conv_c conv_s conv_p conv_f mix"
fi

check_test_file

is_test_list_ok $TESTS_LIST
if [ "$TEST_LIST_ERRORS" != "" ]; then
	echo "The following tests could not be found in ${BLUE}${TESTS_FILE}${NC}:"
	echo $TEST_LIST_ERRORS
	exit
fi

if $CREATE || $CLEAN; then
	make fclean
	clean_tests $TESTS_LIST
fi

if $CREATE || $UPDATE; then
	generate_tests $TESTS_LIST
	launch_tests
fi
