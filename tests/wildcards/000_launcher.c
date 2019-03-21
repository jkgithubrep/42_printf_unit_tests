#include "libunit.h"
#include "ft_printf.h"
#include "wildcards.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&wildcards_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					wildcards_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "wildcards";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",
			&wildcards_zero_and_zero_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", -34, 0, -34, 0, -34, 0, -34, 0, -34, 0",
			&wildcards_zero_and_minus_34_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", 34, 0, 34, 0, 34, 0, 34, 0, 34, 0",
			&wildcards_zero_and_34_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0",
			&wildcards_zero_and_int_min_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0",
			&wildcards_zero_and_int_max_plus_1_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",
			&wildcards_zero_and_zero_asterisk_width_type_d_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", -34, 0, -34, 0, -34, 0, -34, 0, -34, 0",
			&wildcards_zero_and_minus_34_asterisk_width_type_d_various_flags_dot_precision_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", 34, 0, 34, 0, 34, 0, 34, 0, 34, 0",
			&wildcards_zero_and_34_asterisk_width_type_d_various_flags_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0",
			&wildcards_zero_and_int_min_asterisk_width_type_d_various_flags_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0",
			&wildcards_zero_and_int_max_plus_1_asterisk_width_type_d_various_flags_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",
			&wildcards_zero_and_zero_asterisk_width_type_d_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", -34, 0, -34, 0, -34, 0, -34, 0, -34, 0",
			&wildcards_zero_and_minus_34_asterisk_width_type_d_various_flags_5_precision_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", 34, 0, 34, 0, 34, 0, 34, 0, 34, 0",
			&wildcards_zero_and_34_asterisk_width_type_d_various_flags_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0",
			&wildcards_zero_and_int_min_asterisk_width_type_d_various_flags_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0",
			&wildcards_zero_and_int_max_plus_1_asterisk_width_type_d_various_flags_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",
			&wildcards_zero_and_zero_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", -34, 0, -34, 0, -34, 0, -34, 0, -34, 0, -34, 0, -34, 0",
			&wildcards_zero_and_minus_34_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0",
			&wildcards_zero_and_34_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0",
			&wildcards_zero_and_int_min_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0",
			&wildcards_zero_and_int_max_plus_1_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",
			&wildcards_zero_and_zero_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", -34, 0, -34, 0, -34, 0, -34, 0, -34, 0, -34, 0, -34, 0",
			&wildcards_zero_and_minus_34_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0",
			&wildcards_zero_and_34_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0",
			&wildcards_zero_and_int_min_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0",
			&wildcards_zero_and_int_max_plus_1_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0",
			&wildcards_zero_and_zero_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", -34, 0, -34, 0, -34, 0, -34, 0, -34, 0, -34, 0, -34, 0",
			&wildcards_zero_and_minus_34_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0, 34, 0",
			&wildcards_zero_and_34_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0, INT_MIN, 0",
			&wildcards_zero_and_int_min_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0, INT_MAX + 1, 0",
			&wildcards_zero_and_int_max_plus_1_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX",
			&wildcards_int_max_and_int_min_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*d|%-*d|%+*d|% *d|%0*d\", INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX",
			&wildcards_int_max_and_int_max_plus_1_asterisk_width_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_type_d_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_width_type_d_various_flags_dot_precision_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_width_type_d_various_flags_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX",
			&wildcards_int_max_and_int_min_asterisk_width_type_d_various_flags_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.d|%-*.d|%+*.d|% *.d|%0*.d\", INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX",
			&wildcards_int_max_and_int_max_plus_1_asterisk_width_type_d_various_flags_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_type_d_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_width_type_d_various_flags_5_precision_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_width_type_d_various_flags_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX",
			&wildcards_int_max_and_int_min_asterisk_width_type_d_various_flags_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.5d|%-*.5d|%+*.5d|% *.5d|%0*.5d\", INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX",
			&wildcards_int_max_and_int_max_plus_1_asterisk_width_type_d_various_flags_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX",
			&wildcards_int_max_and_int_min_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX",
			&wildcards_int_max_and_int_max_plus_1_asterisk_width_type_d_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX",
			&wildcards_int_max_and_int_min_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX",
			&wildcards_int_max_and_int_max_plus_1_asterisk_width_type_d_various_flags_combined_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX",
			&wildcards_int_max_and_int_min_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX, INT_MAX + 1, INT_MAX",
			&wildcards_int_max_and_int_max_plus_1_asterisk_width_type_d_various_flags_combined_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.*d|%-*.*d|%+*.*d|% *.*d|%0*.*d\", 0, 0, INT_MAX, 0, 0, INT_MAX, 0, 0, INT_MAX, 0, 0, INT_MAX, 0, 0, INT_MAX",
			&wildcards_int_max_and_zero_asterisk_width_and_zero_asterisk_prec_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.*d|%-*.*d|%+*.*d|% *.*d|%0*.*d\", -34, -34, INT_MAX, -34, -34, INT_MAX, -34, -34, INT_MAX, -34, -34, INT_MAX, -34, -34, INT_MAX",
			&wildcards_int_max_and_minus_34_asterisk_minus_34_and_zero_asterisk_prec_type_d_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%*.*d|%-*.*d|%+*.*d|% *.*d|%0*.*d\", 34, 34, INT_MAX, 34, 34, INT_MAX, 34, 34, INT_MAX, 34, 34, INT_MAX, 34, 34, INT_MAX",
			&wildcards_int_max_and_34_asterisk_34_and_zero_asterisk_prec_type_d_various_flags, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
