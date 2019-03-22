# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkettani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 14:15:50 by jkettani          #+#    #+#              #
#    Updated: 2019/03/22 13:53:01 by jkettani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- LIBFTPRINTF PATH -----
#
LIBFTPRINTF_PATH =      ../../ft_printf

# ----- VARIABLES -----

NC =                    \x1b[0m
OK_COLOR =              \x1b[32;01m
ERR_COLOR =             \x1b[31;01m
WARN_COLOR =            \x1b[34;01m
QUIET :=                @
ECHO :=                 @echo
ifneq ($(QUIET),@)
ECHO :=                 @true
endif
SHELL =                 /bin/sh
MAKEFLAGS +=            --warn-undefined-variables
RM =                    rm -f
RMDIR =                 rmdir -p
AR =                    ar
ARFLAGS =               -rcs
CC =                    gcc
CFLAGS =                -w #-g3 #-Wall -Wextra #-Werror
NAME =                  tests
TRACE =                 trace.txt
SRC_PATH =              .
INCLUDE_PATH =          includes
OBJ_PATH =              .obj

LIBUNIT_PATH =          ../framework
LIBUNIT = 				$(LIBUNIT_PATH)/libunit.a
LIBUNIT_INC_PATH =      $(LIBUNIT_PATH)/includes
LIBUNIT_FLAGS =         -L$(LIBUNIT_PATH) -lunit

ASSETS_DIR =            assets
TMP_DIR_FTPRINTF = 		$(ASSETS_DIR)/tmp
LIBFTPRINTF_NAME =      libftprintf.a
LIBFTPRINTF =           $(LIBFTPRINTF_PATH)/$(LIBFTPRINTF_NAME)
LIBFTPRINTF_SO_PATH =   .
LIBFTPRINTF_SO_NAME =   libftprintf.so
LIBFTPRINTF_SO =         $(LIBFTPRINTF_SO_PATH)/$(LIBFTPRINTF_SO_NAME)
LIBFTPRINTF_FLAGS =     -L$(LIBFTPRINTF_PATH) -lftprintf
LIBS =                  $(LIBFTPRINTF) $(LIBUNIT)
LIBS_PATH =             $(LIBFTPRINTF_PATH) $(LIBUNIT_PATH)
CPPFLAGS =              -I$(INCLUDE_PATH) -I$(LIBUNIT_INC_PATH)
COMPILE.c =             $(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c
DEPFLAGS =              -MT $@ -MMD -MP -MF $(OBJ_PATH)/$*.Td
POSTCOMPILE =           @mv -f $(OBJ_PATH)/$*.Td $(OBJ_PATH)/$*.d && touch $@
PRINTF_SRC_NAME =       00_launcher 01_basic_test
SRC_NAME =              srcs/main srcs/tests
-include file_paths
#                        $(addprefix printf/, $(PRINTF_SRC_NAME))
SRC =                   $(addprefix $(SRC_PATH)/, $(addsuffix .c, $(SRC_NAME)))
OBJ =                   $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
DEP =                   $(addprefix $(OBJ_PATH)/, $(SRC:.c=.d))
#OBJ_TREE =              $(shell find $(OBJ_PATH) -type d -print 2> /dev/null)


.SUFFIXES:
.SUFFIXES: .c .o .h

# ----- RULES -----

.PHONY: all
all: $(NAME)

.PRECIOUS: $(OBJ_PATH)%/. $(OBJ_PATH)/.
$(OBJ_PATH)/. $(OBJ_PATH)%/.: 
	@true $(ECHO) "Making directory $@..."
	$(QUIET) mkdir -p $@

$(OBJ_PATH)/%.d: ;

.SECONDEXPANSION:

$(OBJ): $(OBJ_PATH)/%.o: %.c $(OBJ_PATH)/%.d | $$(@D)/.
	$(ECHO) "Compiling $(WARN_COLOR)$<$(NC)..."
	$(QUIET) $(COMPILE.c) $< -o $@ 
	$(QUIET) $(POSTCOMPILE)

.PHONY: libs
$(LIBS) libs:
	$(ECHO) "Updating $(WARN_COLOR)libunit$(NC) library if necessary..."
	$(QUIET) make -C $(LIBUNIT_PATH)
	$(ECHO) "Updating $(WARN_COLOR)libftprintf$(NC) library if necessary..."
	$(QUIET) make -C $(LIBFTPRINTF_PATH)

$(NAME): $(OBJ) $(LIBS) | libs libftprintf
	$(ECHO) "Compiling executable file $(WARN_COLOR)$(NAME)$(NC)..."
	$(QUIET) $(CC) -o $@ $(CPPFLAGS) $(LIBFTPRINTF_SO) $(LIBUNIT_FLAGS) $^

.PHONY: libftprintf
libftprintf:
	$(QUIET) mkdir -p $(ASSETS_DIR)
	$(QUIET) make -C $(LIBFTPRINTF_PATH)
	$(QUIET) cp $(LIBFTPRINTF) $(ASSETS_DIR)
	$(QUIET) rm -rf $(TMP_DIR_FTPRINTF)
	$(QUIET) mkdir -p $(TMP_DIR_FTPRINTF)
	$(ECHO) "Creating $(LIBFTPRINTF_SO_NAME)..."
	$(QUIET) cd $(TMP_DIR_FTPRINTF) && ar -x ../$(LIBFTPRINTF_NAME) \
		&& $(CC) -shared -fPIC *.o -o $(LIBFTPRINTF_SO_NAME) \
		&& cp $(LIBFTPRINTF_SO_NAME) ../..

.PHONY: test
test: all
	@echo "--------------"
	@echo "Starting tests...\n"
	@./$(NAME)
	@fail=`grep -e '\[KO\]' -e '\[SEGV\]' -e '\[BUSE\]' -e '\[SIGA\]'\
			trace.txt | wc -l | bc`; \
		if [ $$fail -gt 0 ]; \
			then echo "$(ERR_COLOR)/!\ $$fail test(s) failed /!\\ $(NC)\\n"; \
			else echo "$(OK_COLOR)All tests passed, good job!$(NC)\\n"; \
			fi

.PHONY: clean
clean:
	$(ECHO) "Cleaning object files..."
	$(QUIET) $(RM) -rf $(OBJ_PATH)
	$(ECHO) "Cleaning dependency files..."
	$(QUIET) $(RM) $(DEP)
#	$(ECHO) "Cleaning obj tree..."
#	$(QUIET) echo $(OBJ_TREE) | xargs $(RMDIR) 2> /dev/null || true
	@if [ -d $(OBJ_PATH) ]; \
		then echo "$(ERR_COLOR)-> Could not clean obj directory.$(NC)"; \
		else echo "$(OK_COLOR)-> Obj directory succesfully cleaned.$(NC)"; fi

.PHONY: fclean
fclean: clean
	$(ECHO) "Cleaning $(WARN_COLOR)$(NAME)$(NC)..."
	$(QUIET) $(RM) $(NAME)
	$(ECHO) "Cleaning $(WARN_COLOR)$(LIBFTPRINTF_SO)$(NC)..."
	$(QUIET) $(RM) $(LIBFTPRINTF_SO)
	@if [ -f $(NAME) ]; \
		then echo "$(ERR_COLOR)-> Could not clean executable file.$(NC)";\
		else echo "$(OK_COLOR)-> Executable file succesfully cleaned.$(NC)"; fi
	$(ECHO) "Cleaning $(WARN_COLOR)$(TRACE)$(NC)..."
	$(QUIET) $(RM) $(TRACE)


.PHONY: re
re: fclean all

# ----- INCLUDES -----

.PRECIOUS: $(OBJ_PATH)/%.d
-include $(DEP)
