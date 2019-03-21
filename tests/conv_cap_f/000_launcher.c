#include "libunit.h"
#include "ft_printf.h"
#include "conv_cap_f.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_cap_f_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_cap_f_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_cap_f";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_f_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_f_minus_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_f_nan_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_f_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_f_minus_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_f_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lF|%-lF|%+lF|% lF|%#lF|%0lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5lF|%-5lF|%+5lF|% 5lF|%#5lF|%05lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_and_5_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lF|%-1lF|%+1lF|% 1lF|%#1lF|%01lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_and_1_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lF|%-.lF|%+.lF|% .lF|%#.lF|%0.lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_and_dot_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8lF|%-.8lF|%+.8lF|% .8lF|%#.8lF|%0.8lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8lF|%-5.8lF|%+5.8lF|% 5.8lF|%#5.8lF|%05.8lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_and_5_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8lF|%-15.8lF|%+15.8lF|% 15.8lF|%#15.8lF|%015.8lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_and_15_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14lF|%- 8.14lF|%-#8.14lF|%-08.14lF|%-+#8.14lF|%-+ #08.14lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_combined_with_minus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14lF|%+ 8.14lF|%+-8.14lF|%+#8.14lF|%+08.14lF|%+ -#08.14lF\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_f_double_various_flags_combined_with_plus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_f_negative_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_f_double_max_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%-F|%+F|% F|%#F|%0F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5F|%-5F|%+5F|% 5F|%#5F|%05F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1F|%-1F|%+1F|% 1F|%#1F|%01F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%-.F|%+.F|% .F|%#.F|%0.F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8F|%-.8F|%+.8F|% .8F|%#.8F|%0.8F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8F|%-5.8F|%+5.8F|% 5.8F|%#5.8F|%05.8F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8F|%-15.8F|%+15.8F|% 15.8F|%#15.8F|%015.8F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14F|%- 8.14F|%-#8.14F|%-08.14F|%-+#8.14F|%-+ #08.14F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14F|%+ 8.14F|%+-8.14F|%+#8.14F|%+08.14F|%+ -#08.14F\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_f_double_min_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LF|%-LF|%+LF|% LF|%#LF|%0LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5LF|%-5LF|%+5LF|% 5LF|%#5LF|%05LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1LF|%-1LF|%+1LF|% 1LF|%#1LF|%01LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.LF|%-.LF|%+.LF|% .LF|%#.LF|%0.LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8LF|%-.8LF|%+.8LF|% .8LF|%#.8LF|%0.8LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8LF|%-5.8LF|%+5.8LF|% 5.8LF|%#5.8LF|%05.8LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8LF|%-15.8LF|%+15.8LF|% 15.8LF|%#15.8LF|%015.8LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14LF|%- 8.14LF|%-#8.14LF|%-08.14LF|%-+#8.14LF|%-+ #08.14LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14LF|%+ 8.14LF|%+-8.14LF|%+#8.14LF|%+08.14LF|%+ -#08.14LF\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_f_long_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LF\", LDBL_MAX",
			&conv_cap_f_long_double_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LF\", LDBL_MIN",
			&conv_cap_f_long_double_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.1F|%.2F|%.5F|%.12F\", 0.000099, 0.000099, 0.000099, 0.000099, 0.000099",
			&conv_cap_f_rounding_only_nines_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.1F|%.2F|%.5F|%.12F\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_f_rounding_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.1F|%.2F|%.5F|%.12F\", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999",
			&conv_cap_f_rounding_not_only_nines, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.1F|%.2F|%.5F|%.12F\", 899.9999999, 899.9999999, 899.9999999, 899.9999999, 899.9999999",
			&conv_cap_f_rounding_not_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.1F|%.2F|%.5F|%.12F\", 42.974234687, 42.974234687, 42.974234687, 42.974234687, 42.974234687",
			&conv_cap_f_rounding_normal, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%2.F|%2.1F|%2.2F|%2.5F|%2.12F\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_f_rounding_only_nines_width_small, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.F|%15.1F|%15.2F|%15.5F|%15.12F\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_f_rounding_only_nines_width_large, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.F|%.F|%.F|%.F\", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52",
			&conv_cap_f_rounding_middle_down, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.F|%.F|%.F|%.F|%.F\", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52",
			&conv_cap_f_rounding_middle_up, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%F|%F|%F|%F|%F\", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201",
			&conv_cap_f_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.350F|%.350F|%.350F|%.350F|%.350F\", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201",
			&conv_cap_f_negative_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1150F|%.1150F|%.1150F|%.1150F\", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037",
			&conv_cap_f_denormalized_numbers, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.2147483649F|%2147483649F\", 1.0, 1.0",
			&conv_cap_f_errors, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
