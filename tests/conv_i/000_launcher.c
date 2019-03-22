#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_i.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_i_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_i_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_i";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", 0, 0, 0, 0, 0, 0, 0",
			&conv_i_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", -0, -0, -0, -0, -0, -0, -0",
			&conv_i_minus_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX",
			&conv_i_int_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN",
			&conv_i_int_min_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_i_uint_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX, LONG_MAX",
			&conv_i_long_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN, LONG_MIN",
			&conv_i_long_min_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhi|%-hhi|%+hhi|% hhi|%0hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhi|%-1hhi|%+1hhi|% 1hhi|%01hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhi|%-23hhi|%+23hhi|% 23hhi|%023hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhi|%-.hhi|%+.hhi|% .hhi|%0.hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhi|%-.5hhi|%+.5hhi|% .5hhi|%0.5hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhi|%-1.hhi|%+1.hhi|% 1.hhi|%01.hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhi|%-23.hhi|%+23.hhi|% 23.hhi|%023.hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhi|%-1.5hhi|%+1.5hhi|% 1.5hhi|%01.5hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhi|%-23.5hhi|%+23.5hhi|% 23.5hhi|%023.5hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hhi|%- hhi|%-0hhi|%+ hhi|%+0hhi|% 0hhi|%-+ 0hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hhi|%- 1hhi|%-01hhi|%+ 1hhi|%+01hhi|% 01hhi|%-+ 01hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hhi|%- 23hhi|%-023hhi|%+ 23hhi|%+023hhi|% 023hhi|%-+ 023hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hhi|%- .hhi|%-0.hhi|%+ .hhi|%+0.hhi|% 0.hhi|%-+ 0.hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hhi|%- .5hhi|%-0.5hhi|%+ .5hhi|%+0.5hhi|% 0.5hhi|%-+ 0.5hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hhi|%- 1.hhi|%-01.hhi|%+ 1.hhi|%+01.hhi|% 01.hhi|%-+ 01.hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hhi|%- 1.5hhi|%-01.5hhi|%+ 1.5hhi|%+01.5hhi|% 01.5hhi|%-+ 01.5hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hhi|%- 23.hhi|%-023.hhi|%+ 23.hhi|%+023.hhi|% 023.hhi|%-+ 023.hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hhi|%- 23.5hhi|%-023.5hhi|%+ 23.5hhi|%+023.5hhi|% 023.5hhi|%-+ 023.5hhi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hi|%-hi|%+hi|% hi|%0hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hi|%-1hi|%+1hi|% 1hi|%01hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hi|%-23hi|%+23hi|% 23hi|%023hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hi|%-.hi|%+.hi|% .hi|%0.hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hi|%-.5hi|%+.5hi|% .5hi|%0.5hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hi|%-1.hi|%+1.hi|% 1.hi|%01.hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hi|%-23.hi|%+23.hi|% 23.hi|%023.hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hi|%-1.5hi|%+1.5hi|% 1.5hi|%01.5hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hi|%-23.5hi|%+23.5hi|% 23.5hi|%023.5hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hi|%- hi|%-0hi|%+ hi|%+0hi|% 0hi|%-+ 0hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hi|%- 1hi|%-01hi|%+ 1hi|%+01hi|% 01hi|%-+ 01hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hi|%- 23hi|%-023hi|%+ 23hi|%+023hi|% 023hi|%-+ 023hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hi|%- .hi|%-0.hi|%+ .hi|%+0.hi|% 0.hi|%-+ 0.hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hi|%- .5hi|%-0.5hi|%+ .5hi|%+0.5hi|% 0.5hi|%-+ 0.5hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hi|%- 1.hi|%-01.hi|%+ 1.hi|%+01.hi|% 01.hi|%-+ 01.hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hi|%- 1.5hi|%-01.5hi|%+ 1.5hi|%+01.5hi|% 01.5hi|%-+ 01.5hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hi|%- 23.hi|%-023.hi|%+ 23.hi|%+023.hi|% 023.hi|%-+ 023.hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hi|%- 23.5hi|%-023.5hi|%+ 23.5hi|%+023.5hi|% 023.5hi|%-+ 023.5hi\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%li|%-li|%+li|% li|%0li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1li|%-1li|%+1li|% 1li|%01li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23li|%-23li|%+23li|% 23li|%023li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.li|%-.li|%+.li|% .li|%0.li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5li|%-.5li|%+.5li|% .5li|%0.5li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.li|%-1.li|%+1.li|% 1.li|%01.li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.li|%-23.li|%+23.li|% 23.li|%023.li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5li|%-1.5li|%+1.5li|% 1.5li|%01.5li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5li|%-23.5li|%+23.5li|% 23.5li|%023.5li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+li|%- li|%-0li|%+ li|%+0li|% 0li|%-+ 0li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1li|%- 1li|%-01li|%+ 1li|%+01li|% 01li|%-+ 01li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23li|%- 23li|%-023li|%+ 23li|%+023li|% 023li|%-+ 023li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.li|%- .li|%-0.li|%+ .li|%+0.li|% 0.li|%-+ 0.li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5li|%- .5li|%-0.5li|%+ .5li|%+0.5li|% 0.5li|%-+ 0.5li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.li|%- 1.li|%-01.li|%+ 1.li|%+01.li|% 01.li|%-+ 01.li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5li|%- 1.5li|%-01.5li|%+ 1.5li|%+01.5li|% 01.5li|%-+ 01.5li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.li|%- 23.li|%-023.li|%+ 23.li|%+023.li|% 023.li|%-+ 023.li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5li|%- 23.5li|%-023.5li|%+ 23.5li|%+023.5li|% 023.5li|%-+ 023.5li\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lli|%-lli|%+lli|% lli|%0lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lli|%-1lli|%+1lli|% 1lli|%01lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lli|%-23lli|%+23lli|% 23lli|%023lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lli|%-.lli|%+.lli|% .lli|%0.lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lli|%-.5lli|%+.5lli|% .5lli|%0.5lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lli|%-1.lli|%+1.lli|% 1.lli|%01.lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lli|%-23.lli|%+23.lli|% 23.lli|%023.lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lli|%-1.5lli|%+1.5lli|% 1.5lli|%01.5lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lli|%-23.5lli|%+23.5lli|% 23.5lli|%023.5lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+lli|%- lli|%-0lli|%+ lli|%+0lli|% 0lli|%-+ 0lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1lli|%- 1lli|%-01lli|%+ 1lli|%+01lli|% 01lli|%-+ 01lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23lli|%- 23lli|%-023lli|%+ 23lli|%+023lli|% 023lli|%-+ 023lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.lli|%- .lli|%-0.lli|%+ .lli|%+0.lli|% 0.lli|%-+ 0.lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5lli|%- .5lli|%-0.5lli|%+ .5lli|%+0.5lli|% 0.5lli|%-+ 0.5lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.lli|%- 1.lli|%-01.lli|%+ 1.lli|%+01.lli|% 01.lli|%-+ 01.lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5lli|%- 1.5lli|%-01.5lli|%+ 1.5lli|%+01.5lli|% 01.5lli|%-+ 01.5lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.lli|%- 23.lli|%-023.lli|%+ 23.lli|%+023.lli|% 023.lli|%-+ 023.lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5lli|%- 23.5lli|%-023.5lli|%+ 23.5lli|%+023.5lli|% 023.5lli|%-+ 023.5lli\", LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX",
			&conv_i_long_long_max_and_various_flags_combined_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i|%-i|%+i|% i|%0i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i|%-1i|%+1i|% 1i|%01i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23i|%-23i|%+23i|% 23i|%023i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i|%-.i|%+.i|% .i|%0.i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5i|%-.5i|%+.5i|% .5i|%0.5i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.i|%-1.i|%+1.i|% 1.i|%01.i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.i|%-23.i|%+23.i|% 23.i|%023.i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5i|%-1.5i|%+1.5i|% 1.5i|%01.5i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5i|%-23.5i|%+23.5i|% 23.5i|%023.5i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+i|%- i|%-0i|%+ i|%+0i|% 0i|%-+ 0i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1i|%- 1i|%-01i|%+ 1i|%+01i|% 01i|%-+ 01i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23i|%- 23i|%-023i|%+ 23i|%+023i|% 023i|%-+ 023i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.i|%- .i|%-0.i|%+ .i|%+0.i|% 0.i|%-+ 0.i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5i|%- .5i|%-0.5i|%+ .5i|%+0.5i|% 0.5i|%-+ 0.5i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.i|%- 1.i|%-01.i|%+ 1.i|%+01.i|% 01.i|%-+ 01.i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5i|%- 1.5i|%-01.5i|%+ 1.5i|%+01.5i|% 01.5i|%-+ 01.5i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.i|%- 23.i|%-023.i|%+ 23.i|%+023.i|% 023.i|%-+ 023.i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5i|%- 23.5i|%-023.5i|%+ 23.5i|%+023.5i|% 023.5i|%-+ 023.5i\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhi|%-hhi|%+hhi|% hhi|%0hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhi|%-1hhi|%+1hhi|% 1hhi|%01hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhi|%-23hhi|%+23hhi|% 23hhi|%023hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhi|%-.hhi|%+.hhi|% .hhi|%0.hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhi|%-.5hhi|%+.5hhi|% .5hhi|%0.5hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhi|%-1.hhi|%+1.hhi|% 1.hhi|%01.hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhi|%-23.hhi|%+23.hhi|% 23.hhi|%023.hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhi|%-1.5hhi|%+1.5hhi|% 1.5hhi|%01.5hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhi|%-23.5hhi|%+23.5hhi|% 23.5hhi|%023.5hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hhi|%- hhi|%-0hhi|%+ hhi|%+0hhi|% 0hhi|%-+ 0hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hhi|%- 1hhi|%-01hhi|%+ 1hhi|%+01hhi|% 01hhi|%-+ 01hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hhi|%- 23hhi|%-023hhi|%+ 23hhi|%+023hhi|% 023hhi|%-+ 023hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hhi|%- .hhi|%-0.hhi|%+ .hhi|%+0.hhi|% 0.hhi|%-+ 0.hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hhi|%- .5hhi|%-0.5hhi|%+ .5hhi|%+0.5hhi|% 0.5hhi|%-+ 0.5hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hhi|%- 1.hhi|%-01.hhi|%+ 1.hhi|%+01.hhi|% 01.hhi|%-+ 01.hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hhi|%- 1.5hhi|%-01.5hhi|%+ 1.5hhi|%+01.5hhi|% 01.5hhi|%-+ 01.5hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hhi|%- 23.hhi|%-023.hhi|%+ 23.hhi|%+023.hhi|% 023.hhi|%-+ 023.hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hhi|%- 23.5hhi|%-023.5hhi|%+ 23.5hhi|%+023.5hhi|% 023.5hhi|%-+ 023.5hhi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hi|%-hi|%+hi|% hi|%0hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hi|%-1hi|%+1hi|% 1hi|%01hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hi|%-23hi|%+23hi|% 23hi|%023hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hi|%-.hi|%+.hi|% .hi|%0.hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hi|%-.5hi|%+.5hi|% .5hi|%0.5hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hi|%-1.hi|%+1.hi|% 1.hi|%01.hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hi|%-23.hi|%+23.hi|% 23.hi|%023.hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hi|%-1.5hi|%+1.5hi|% 1.5hi|%01.5hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hi|%-23.5hi|%+23.5hi|% 23.5hi|%023.5hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+hi|%- hi|%-0hi|%+ hi|%+0hi|% 0hi|%-+ 0hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1hi|%- 1hi|%-01hi|%+ 1hi|%+01hi|% 01hi|%-+ 01hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23hi|%- 23hi|%-023hi|%+ 23hi|%+023hi|% 023hi|%-+ 023hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.hi|%- .hi|%-0.hi|%+ .hi|%+0.hi|% 0.hi|%-+ 0.hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5hi|%- .5hi|%-0.5hi|%+ .5hi|%+0.5hi|% 0.5hi|%-+ 0.5hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.hi|%- 1.hi|%-01.hi|%+ 1.hi|%+01.hi|% 01.hi|%-+ 01.hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5hi|%- 1.5hi|%-01.5hi|%+ 1.5hi|%+01.5hi|% 01.5hi|%-+ 01.5hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.hi|%- 23.hi|%-023.hi|%+ 23.hi|%+023.hi|% 023.hi|%-+ 023.hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5hi|%- 23.5hi|%-023.5hi|%+ 23.5hi|%+023.5hi|% 023.5hi|%-+ 023.5hi\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%li|%-li|%+li|% li|%0li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1li|%-1li|%+1li|% 1li|%01li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23li|%-23li|%+23li|% 23li|%023li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.li|%-.li|%+.li|% .li|%0.li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5li|%-.5li|%+.5li|% .5li|%0.5li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.li|%-1.li|%+1.li|% 1.li|%01.li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.li|%-23.li|%+23.li|% 23.li|%023.li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5li|%-1.5li|%+1.5li|% 1.5li|%01.5li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5li|%-23.5li|%+23.5li|% 23.5li|%023.5li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+li|%- li|%-0li|%+ li|%+0li|% 0li|%-+ 0li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1li|%- 1li|%-01li|%+ 1li|%+01li|% 01li|%-+ 01li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23li|%- 23li|%-023li|%+ 23li|%+023li|% 023li|%-+ 023li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.li|%- .li|%-0.li|%+ .li|%+0.li|% 0.li|%-+ 0.li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5li|%- .5li|%-0.5li|%+ .5li|%+0.5li|% 0.5li|%-+ 0.5li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.li|%- 1.li|%-01.li|%+ 1.li|%+01.li|% 01.li|%-+ 01.li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5li|%- 1.5li|%-01.5li|%+ 1.5li|%+01.5li|% 01.5li|%-+ 01.5li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.li|%- 23.li|%-023.li|%+ 23.li|%+023.li|% 023.li|%-+ 023.li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5li|%- 23.5li|%-023.5li|%+ 23.5li|%+023.5li|% 023.5li|%-+ 023.5li\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lli|%-lli|%+lli|% lli|%0lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lli|%-1lli|%+1lli|% 1lli|%01lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lli|%-23lli|%+23lli|% 23lli|%023lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lli|%-.lli|%+.lli|% .lli|%0.lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lli|%-.5lli|%+.5lli|% .5lli|%0.5lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lli|%-1.lli|%+1.lli|% 1.lli|%01.lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lli|%-23.lli|%+23.lli|% 23.lli|%023.lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lli|%-1.5lli|%+1.5lli|% 1.5lli|%01.5lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lli|%-23.5lli|%+23.5lli|% 23.5lli|%023.5lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+lli|%- lli|%-0lli|%+ lli|%+0lli|% 0lli|%-+ 0lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1lli|%- 1lli|%-01lli|%+ 1lli|%+01lli|% 01lli|%-+ 01lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23lli|%- 23lli|%-023lli|%+ 23lli|%+023lli|% 023lli|%-+ 023lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.lli|%- .lli|%-0.lli|%+ .lli|%+0.lli|% 0.lli|%-+ 0.lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+.5lli|%- .5lli|%-0.5lli|%+ .5lli|%+0.5lli|% 0.5lli|%-+ 0.5lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.lli|%- 1.lli|%-01.lli|%+ 1.lli|%+01.lli|% 01.lli|%-+ 01.lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+1.5lli|%- 1.5lli|%-01.5lli|%+ 1.5lli|%+01.5lli|% 01.5lli|%-+ 01.5lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_1_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.lli|%- 23.lli|%-023.lli|%+ 23.lli|%+023.lli|% 023.lli|%-+ 023.lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_dot_precision_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+23.5lli|%- 23.5lli|%-023.5lli|%+ 23.5lli|%+023.5lli|% 023.5lli|%-+ 023.5lli\", LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN, LLONG_MIN",
			&conv_i_long_long_min_and_various_flags_combined_and_23_width_and_5_precision_and_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
