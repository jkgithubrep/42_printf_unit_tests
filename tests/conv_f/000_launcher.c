#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_f.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_f_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_f_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_f";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", 0., 0., 0., 0., 0., 0.",
			&conv_f_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", -0., -0., -0., -0., -0., -0.",
			&conv_f_minus_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_f_nan_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_f_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_f_minus_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", 42., 42., 42., 42., 42., 42.",
			&conv_f_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lf|%-lf|%+lf|% lf|%#lf|%0lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5lf|%-5lf|%+5lf|% 5lf|%#5lf|%05lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_and_5_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lf|%-1lf|%+1lf|% 1lf|%#1lf|%01lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_and_1_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lf|%-.lf|%+.lf|% .lf|%#.lf|%0.lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_and_dot_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8lf|%-.8lf|%+.8lf|% .8lf|%#.8lf|%0.8lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8lf|%-5.8lf|%+5.8lf|% 5.8lf|%#5.8lf|%05.8lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_and_5_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8lf|%-15.8lf|%+15.8lf|% 15.8lf|%#15.8lf|%015.8lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_and_15_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14lf|%- 8.14lf|%-#8.14lf|%-08.14lf|%-+#8.14lf|%-+ #08.14lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_combined_with_minus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14lf|%+ 8.14lf|%+-8.14lf|%+#8.14lf|%+08.14lf|%+ -#08.14lf\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_f_double_various_flags_combined_with_plus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", -42., -42., -42., -42., -42., -42.",
			&conv_f_negative_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_f_double_max_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%-f|%+f|% f|%#f|%0f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5f|%-5f|%+5f|% 5f|%#5f|%05f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1f|%-1f|%+1f|% 1f|%#1f|%01f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%-.f|%+.f|% .f|%#.f|%0.f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8f|%-.8f|%+.8f|% .8f|%#.8f|%0.8f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8f|%-5.8f|%+5.8f|% 5.8f|%#5.8f|%05.8f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14f|%- 8.14f|%-#8.14f|%-08.14f|%-+#8.14f|%-+ #08.14f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14f|%+ 8.14f|%+-8.14f|%+#8.14f|%+08.14f|%+ -#08.14f\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_f_double_min_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Lf|%-Lf|%+Lf|% Lf|%#Lf|%0Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5Lf|%-5Lf|%+5Lf|% 5Lf|%#5Lf|%05Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1Lf|%-1Lf|%+1Lf|% 1Lf|%#1Lf|%01Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.Lf|%-.Lf|%+.Lf|% .Lf|%#.Lf|%0.Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8Lf|%-.8Lf|%+.8Lf|% .8Lf|%#.8Lf|%0.8Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8Lf|%-5.8Lf|%+5.8Lf|% 5.8Lf|%#5.8Lf|%05.8Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8Lf|%-15.8Lf|%+15.8Lf|% 15.8Lf|%#15.8Lf|%015.8Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14Lf|%- 8.14Lf|%-#8.14Lf|%-08.14Lf|%-+#8.14Lf|%-+ #08.14Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14Lf|%+ 8.14Lf|%+-8.14Lf|%+#8.14Lf|%+08.14Lf|%+ -#08.14Lf\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_f_long_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Lf\", LDBL_MAX",
			&conv_f_long_double_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Lf\", LDBL_MIN",
			&conv_f_long_double_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.1f|%.2f|%.5f|%.12f\", 0.000099, 0.000099, 0.000099, 0.000099, 0.000099",
			&conv_f_rounding_only_nines_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.1f|%.2f|%.5f|%.12f\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_f_rounding_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.1f|%.2f|%.5f|%.12f\", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999",
			&conv_f_rounding_not_only_nines, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.1f|%.2f|%.5f|%.12f\", 899.9999999, 899.9999999, 899.9999999, 899.9999999, 899.9999999",
			&conv_f_rounding_not_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.1f|%.2f|%.5f|%.12f\", 42.974234687, 42.974234687, 42.974234687, 42.974234687, 42.974234687",
			&conv_f_rounding_normal, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%2.f|%2.1f|%2.2f|%2.5f|%2.12f\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_f_rounding_only_nines_width_small, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.f|%15.1f|%15.2f|%15.5f|%15.12f\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_f_rounding_only_nines_width_large, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.f|%.f|%.f|%.f\", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52",
			&conv_f_rounding_middle_down, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.f|%.f|%.f|%.f|%.f\", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52",
			&conv_f_rounding_middle_up, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%f|%f|%f|%f|%f\", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201",
			&conv_f_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.350f|%.350f|%.350f|%.350f|%.350f\", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201",
			&conv_f_negative_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1150f|%.1150f|%.1150f|%.1150f\", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037",
			&conv_f_denormalized_numbers, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.2147483649f|%2147483649f\", 1.0, 1.0",
			&conv_f_errors, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
