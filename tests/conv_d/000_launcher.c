#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_d.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_d_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_d_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_d";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", 0, 0, 0, 0, 0, 0, 0",
			&conv_d_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", -0, -0, -0, -0, -0, -0, -0",
			&conv_d_minus_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_d_int_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_d_int_min_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_d_uint_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_d_long_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_d_long_min_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhd|%-hhd|%+hhd|% hhd|%0hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhd|%-1hhd|%+1hhd|% 1hhd|%01hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhd|%-23hhd|%+23hhd|% 23hhd|%023hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhd|%-.hhd|%+.hhd|% .hhd|%0.hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhd|%-.5hhd|%+.5hhd|% .5hhd|%0.5hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhd|%-1.hhd|%+1.hhd|% 1.hhd|%01.hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhd|%-23.hhd|%+23.hhd|% 23.hhd|%023.hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhd|%-1.5hhd|%+1.5hhd|% 1.5hhd|%01.5hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhd|%-23.5hhd|%+23.5hhd|% 23.5hhd|%023.5hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hhd|%- hhd|%-0hhd|%+ hhd|%+0hhd|% 0hhd|%-+ 0hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hhd|%- 1hhd|%-01hhd|%+ 1hhd|%+01hhd|% 01hhd|%-+ 01hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hhd|%- 23hhd|%-023hhd|%+ 23hhd|%+023hhd|% 023hhd|%-+ 023hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hhd|%- .hhd|%-0.hhd|%+ .hhd|%+0.hhd|% 0.hhd|%-+ 0.hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hhd|%- .5hhd|%-0.5hhd|%+ .5hhd|%+0.5hhd|% 0.5hhd|%-+ 0.5hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hhd|%- 1.hhd|%-01.hhd|%+ 1.hhd|%+01.hhd|% 01.hhd|%-+ 01.hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hhd|%- 1.5hhd|%-01.5hhd|%+ 1.5hhd|%+01.5hhd|% 01.5hhd|%-+ 01.5hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hhd|%- 23.hhd|%-023.hhd|%+ 23.hhd|%+023.hhd|% 023.hhd|%-+ 023.hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hhd|%- 23.5hhd|%-023.5hhd|%+ 23.5hhd|%+023.5hhd|% 023.5hhd|%-+ 023.5hhd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hd|%-hd|%+hd|% hd|%0hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hd|%-1hd|%+1hd|% 1hd|%01hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hd|%-23hd|%+23hd|% 23hd|%023hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hd|%-.hd|%+.hd|% .hd|%0.hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hd|%-.5hd|%+.5hd|% .5hd|%0.5hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hd|%-1.hd|%+1.hd|% 1.hd|%01.hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hd|%-23.hd|%+23.hd|% 23.hd|%023.hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hd|%-1.5hd|%+1.5hd|% 1.5hd|%01.5hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hd|%-23.5hd|%+23.5hd|% 23.5hd|%023.5hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hd|%- hd|%-0hd|%+ hd|%+0hd|% 0hd|%-+ 0hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hd|%- 1hd|%-01hd|%+ 1hd|%+01hd|% 01hd|%-+ 01hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hd|%- 23hd|%-023hd|%+ 23hd|%+023hd|% 023hd|%-+ 023hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hd|%- .hd|%-0.hd|%+ .hd|%+0.hd|% 0.hd|%-+ 0.hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hd|%- .5hd|%-0.5hd|%+ .5hd|%+0.5hd|% 0.5hd|%-+ 0.5hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hd|%- 1.hd|%-01.hd|%+ 1.hd|%+01.hd|% 01.hd|%-+ 01.hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hd|%- 1.5hd|%-01.5hd|%+ 1.5hd|%+01.5hd|% 01.5hd|%-+ 01.5hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hd|%- 23.hd|%-023.hd|%+ 23.hd|%+023.hd|% 023.hd|%-+ 023.hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hd|%- 23.5hd|%-023.5hd|%+ 23.5hd|%+023.5hd|% 023.5hd|%-+ 023.5hd\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%ld|%-ld|%+ld|% ld|%0ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1ld|%-1ld|%+1ld|% 1ld|%01ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23ld|%-23ld|%+23ld|% 23ld|%023ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.ld|%-.ld|%+.ld|% .ld|%0.ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5ld|%-.5ld|%+.5ld|% .5ld|%0.5ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.ld|%-1.ld|%+1.ld|% 1.ld|%01.ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.ld|%-23.ld|%+23.ld|% 23.ld|%023.ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5ld|%-1.5ld|%+1.5ld|% 1.5ld|%01.5ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5ld|%-23.5ld|%+23.5ld|% 23.5ld|%023.5ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+ld|%- ld|%-0ld|%+ ld|%+0ld|% 0ld|%-+ 0ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1ld|%- 1ld|%-01ld|%+ 1ld|%+01ld|% 01ld|%-+ 01ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23ld|%- 23ld|%-023ld|%+ 23ld|%+023ld|% 023ld|%-+ 023ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.ld|%- .ld|%-0.ld|%+ .ld|%+0.ld|% 0.ld|%-+ 0.ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5ld|%- .5ld|%-0.5ld|%+ .5ld|%+0.5ld|% 0.5ld|%-+ 0.5ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.ld|%- 1.ld|%-01.ld|%+ 1.ld|%+01.ld|% 01.ld|%-+ 01.ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5ld|%- 1.5ld|%-01.5ld|%+ 1.5ld|%+01.5ld|% 01.5ld|%-+ 01.5ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.ld|%- 23.ld|%-023.ld|%+ 23.ld|%+023.ld|% 023.ld|%-+ 023.ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5ld|%- 23.5ld|%-023.5ld|%+ 23.5ld|%+023.5ld|% 023.5ld|%-+ 023.5ld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lld|%-lld|%+lld|% lld|%0lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lld|%-1lld|%+1lld|% 1lld|%01lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lld|%-23lld|%+23lld|% 23lld|%023lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lld|%-.lld|%+.lld|% .lld|%0.lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lld|%-.5lld|%+.5lld|% .5lld|%0.5lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lld|%-1.lld|%+1.lld|% 1.lld|%01.lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lld|%-23.lld|%+23.lld|% 23.lld|%023.lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lld|%-1.5lld|%+1.5lld|% 1.5lld|%01.5lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lld|%-23.5lld|%+23.5lld|% 23.5lld|%023.5lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+lld|%- lld|%-0lld|%+ lld|%+0lld|% 0lld|%-+ 0lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1lld|%- 1lld|%-01lld|%+ 1lld|%+01lld|% 01lld|%-+ 01lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23lld|%- 23lld|%-023lld|%+ 23lld|%+023lld|% 023lld|%-+ 023lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.lld|%- .lld|%-0.lld|%+ .lld|%+0.lld|% 0.lld|%-+ 0.lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5lld|%- .5lld|%-0.5lld|%+ .5lld|%+0.5lld|% 0.5lld|%-+ 0.5lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.lld|%- 1.lld|%-01.lld|%+ 1.lld|%+01.lld|% 01.lld|%-+ 01.lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5lld|%- 1.5lld|%-01.5lld|%+ 1.5lld|%+01.5lld|% 01.5lld|%-+ 01.5lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.lld|%- 23.lld|%-023.lld|%+ 23.lld|%+023.lld|% 023.lld|%-+ 023.lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5lld|%- 23.5lld|%-023.5lld|%+ 23.5lld|%+023.5lld|% 023.5lld|%-+ 023.5lld\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_d_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d|%-d|%+d|% d|%0d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d|%-1d|%+1d|% 1d|%01d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23d|%-23d|%+23d|% 23d|%023d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d|%-.d|%+.d|% .d|%0.d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5d|%-.5d|%+.5d|% .5d|%0.5d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.d|%-1.d|%+1.d|% 1.d|%01.d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.d|%-23.d|%+23.d|% 23.d|%023.d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5d|%-1.5d|%+1.5d|% 1.5d|%01.5d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5d|%-23.5d|%+23.5d|% 23.5d|%023.5d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+d|%- d|%-0d|%+ d|%+0d|% 0d|%-+ 0d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1d|%- 1d|%-01d|%+ 1d|%+01d|% 01d|%-+ 01d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23d|%- 23d|%-023d|%+ 23d|%+023d|% 023d|%-+ 023d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.d|%- .d|%-0.d|%+ .d|%+0.d|% 0.d|%-+ 0.d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5d|%- .5d|%-0.5d|%+ .5d|%+0.5d|% 0.5d|%-+ 0.5d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.d|%- 1.d|%-01.d|%+ 1.d|%+01.d|% 01.d|%-+ 01.d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5d|%- 1.5d|%-01.5d|%+ 1.5d|%+01.5d|% 01.5d|%-+ 01.5d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.d|%- 23.d|%-023.d|%+ 23.d|%+023.d|% 023.d|%-+ 023.d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5d|%- 23.5d|%-023.5d|%+ 23.5d|%+023.5d|% 023.5d|%-+ 023.5d\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhd|%-hhd|%+hhd|% hhd|%0hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhd|%-1hhd|%+1hhd|% 1hhd|%01hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhd|%-23hhd|%+23hhd|% 23hhd|%023hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhd|%-.hhd|%+.hhd|% .hhd|%0.hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhd|%-.5hhd|%+.5hhd|% .5hhd|%0.5hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhd|%-1.hhd|%+1.hhd|% 1.hhd|%01.hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhd|%-23.hhd|%+23.hhd|% 23.hhd|%023.hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhd|%-1.5hhd|%+1.5hhd|% 1.5hhd|%01.5hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhd|%-23.5hhd|%+23.5hhd|% 23.5hhd|%023.5hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hhd|%- hhd|%-0hhd|%+ hhd|%+0hhd|% 0hhd|%-+ 0hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hhd|%- 1hhd|%-01hhd|%+ 1hhd|%+01hhd|% 01hhd|%-+ 01hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hhd|%- 23hhd|%-023hhd|%+ 23hhd|%+023hhd|% 023hhd|%-+ 023hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hhd|%- .hhd|%-0.hhd|%+ .hhd|%+0.hhd|% 0.hhd|%-+ 0.hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hhd|%- .5hhd|%-0.5hhd|%+ .5hhd|%+0.5hhd|% 0.5hhd|%-+ 0.5hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hhd|%- 1.hhd|%-01.hhd|%+ 1.hhd|%+01.hhd|% 01.hhd|%-+ 01.hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hhd|%- 1.5hhd|%-01.5hhd|%+ 1.5hhd|%+01.5hhd|% 01.5hhd|%-+ 01.5hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hhd|%- 23.hhd|%-023.hhd|%+ 23.hhd|%+023.hhd|% 023.hhd|%-+ 023.hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hhd|%- 23.5hhd|%-023.5hhd|%+ 23.5hhd|%+023.5hhd|% 023.5hhd|%-+ 023.5hhd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hd|%-hd|%+hd|% hd|%0hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hd|%-1hd|%+1hd|% 1hd|%01hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hd|%-23hd|%+23hd|% 23hd|%023hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hd|%-.hd|%+.hd|% .hd|%0.hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hd|%-.5hd|%+.5hd|% .5hd|%0.5hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hd|%-1.hd|%+1.hd|% 1.hd|%01.hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hd|%-23.hd|%+23.hd|% 23.hd|%023.hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hd|%-1.5hd|%+1.5hd|% 1.5hd|%01.5hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hd|%-23.5hd|%+23.5hd|% 23.5hd|%023.5hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hd|%- hd|%-0hd|%+ hd|%+0hd|% 0hd|%-+ 0hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hd|%- 1hd|%-01hd|%+ 1hd|%+01hd|% 01hd|%-+ 01hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hd|%- 23hd|%-023hd|%+ 23hd|%+023hd|% 023hd|%-+ 023hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hd|%- .hd|%-0.hd|%+ .hd|%+0.hd|% 0.hd|%-+ 0.hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hd|%- .5hd|%-0.5hd|%+ .5hd|%+0.5hd|% 0.5hd|%-+ 0.5hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hd|%- 1.hd|%-01.hd|%+ 1.hd|%+01.hd|% 01.hd|%-+ 01.hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hd|%- 1.5hd|%-01.5hd|%+ 1.5hd|%+01.5hd|% 01.5hd|%-+ 01.5hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hd|%- 23.hd|%-023.hd|%+ 23.hd|%+023.hd|% 023.hd|%-+ 023.hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hd|%- 23.5hd|%-023.5hd|%+ 23.5hd|%+023.5hd|% 023.5hd|%-+ 023.5hd\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%ld|%-ld|%+ld|% ld|%0ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1ld|%-1ld|%+1ld|% 1ld|%01ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23ld|%-23ld|%+23ld|% 23ld|%023ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.ld|%-.ld|%+.ld|% .ld|%0.ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5ld|%-.5ld|%+.5ld|% .5ld|%0.5ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.ld|%-1.ld|%+1.ld|% 1.ld|%01.ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.ld|%-23.ld|%+23.ld|% 23.ld|%023.ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5ld|%-1.5ld|%+1.5ld|% 1.5ld|%01.5ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5ld|%-23.5ld|%+23.5ld|% 23.5ld|%023.5ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+ld|%- ld|%-0ld|%+ ld|%+0ld|% 0ld|%-+ 0ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1ld|%- 1ld|%-01ld|%+ 1ld|%+01ld|% 01ld|%-+ 01ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23ld|%- 23ld|%-023ld|%+ 23ld|%+023ld|% 023ld|%-+ 023ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.ld|%- .ld|%-0.ld|%+ .ld|%+0.ld|% 0.ld|%-+ 0.ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5ld|%- .5ld|%-0.5ld|%+ .5ld|%+0.5ld|% 0.5ld|%-+ 0.5ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.ld|%- 1.ld|%-01.ld|%+ 1.ld|%+01.ld|% 01.ld|%-+ 01.ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5ld|%- 1.5ld|%-01.5ld|%+ 1.5ld|%+01.5ld|% 01.5ld|%-+ 01.5ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.ld|%- 23.ld|%-023.ld|%+ 23.ld|%+023.ld|% 023.ld|%-+ 023.ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5ld|%- 23.5ld|%-023.5ld|%+ 23.5ld|%+023.5ld|% 023.5ld|%-+ 023.5ld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lld|%-lld|%+lld|% lld|%0lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lld|%-1lld|%+1lld|% 1lld|%01lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lld|%-23lld|%+23lld|% 23lld|%023lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lld|%-.lld|%+.lld|% .lld|%0.lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lld|%-.5lld|%+.5lld|% .5lld|%0.5lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lld|%-1.lld|%+1.lld|% 1.lld|%01.lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lld|%-23.lld|%+23.lld|% 23.lld|%023.lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lld|%-1.5lld|%+1.5lld|% 1.5lld|%01.5lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lld|%-23.5lld|%+23.5lld|% 23.5lld|%023.5lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+lld|%- lld|%-0lld|%+ lld|%+0lld|% 0lld|%-+ 0lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1lld|%- 1lld|%-01lld|%+ 1lld|%+01lld|% 01lld|%-+ 01lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23lld|%- 23lld|%-023lld|%+ 23lld|%+023lld|% 023lld|%-+ 023lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.lld|%- .lld|%-0.lld|%+ .lld|%+0.lld|% 0.lld|%-+ 0.lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5lld|%- .5lld|%-0.5lld|%+ .5lld|%+0.5lld|% 0.5lld|%-+ 0.5lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.lld|%- 1.lld|%-01.lld|%+ 1.lld|%+01.lld|% 01.lld|%-+ 01.lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5lld|%- 1.5lld|%-01.5lld|%+ 1.5lld|%+01.5lld|% 01.5lld|%-+ 01.5lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.lld|%- 23.lld|%-023.lld|%+ 23.lld|%+023.lld|% 023.lld|%-+ 023.lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5lld|%- 23.5lld|%-023.5lld|%+ 23.5lld|%+023.5lld|% 023.5lld|%-+ 023.5lld\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_d_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
