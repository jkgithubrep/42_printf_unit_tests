#include "libunit.h"
#include "ft_printf.h"
#include "conv_cap_g.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_cap_g_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_cap_g_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_cap_g";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_g_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_g_minus_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_g_nan_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_g_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_g_minus_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_g_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lG|%-lG|%+lG|% lG|%#lG|%0lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5lG|%-5lG|%+5lG|% 5lG|%#5lG|%05lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_and_5_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lG|%-1lG|%+1lG|% 1lG|%#1lG|%01lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_and_1_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lG|%-.lG|%+.lG|% .lG|%#.lG|%0.lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_and_dot_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8lG|%-.8lG|%+.8lG|% .8lG|%#.8lG|%0.8lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8lG|%-5.8lG|%+5.8lG|% 5.8lG|%#5.8lG|%05.8lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_and_5_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8lG|%-15.8lG|%+15.8lG|% 15.8lG|%#15.8lG|%015.8lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_and_15_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14lG|%- 8.14lG|%-#8.14lG|%-08.14lG|%-+#8.14lG|%-+ #08.14lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_combined_with_minus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14lG|%+ 8.14lG|%+-8.14lG|%+#8.14lG|%+08.14lG|%+ -#08.14lG\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_g_double_various_flags_combined_with_plus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_g_negative_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_g_double_max_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%-G|%+G|% G|%#G|%0G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5G|%-5G|%+5G|% 5G|%#5G|%05G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1G|%-1G|%+1G|% 1G|%#1G|%01G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%-.G|%+.G|% .G|%#.G|%0.G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8G|%-.8G|%+.8G|% .8G|%#.8G|%0.8G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8G|%-5.8G|%+5.8G|% 5.8G|%#5.8G|%05.8G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8G|%-15.8G|%+15.8G|% 15.8G|%#15.8G|%015.8G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14G|%- 8.14G|%-#8.14G|%-08.14G|%-+#8.14G|%-+ #08.14G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14G|%+ 8.14G|%+-8.14G|%+#8.14G|%+08.14G|%+ -#08.14G\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_g_double_min_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LG|%-LG|%+LG|% LG|%#LG|%0LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5LG|%-5LG|%+5LG|% 5LG|%#5LG|%05LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1LG|%-1LG|%+1LG|% 1LG|%#1LG|%01LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.LG|%-.LG|%+.LG|% .LG|%#.LG|%0.LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8LG|%-.8LG|%+.8LG|% .8LG|%#.8LG|%0.8LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8LG|%-5.8LG|%+5.8LG|% 5.8LG|%#5.8LG|%05.8LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8LG|%-15.8LG|%+15.8LG|% 15.8LG|%#15.8LG|%015.8LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14LG|%- 8.14LG|%-#8.14LG|%-08.14LG|%-+#8.14LG|%-+ #08.14LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14LG|%+ 8.14LG|%+-8.14LG|%+#8.14LG|%+08.14LG|%+ -#08.14LG\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_g_long_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LG\", LDBL_MAX",
			&conv_cap_g_long_double_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LG\", LDBL_MIN",
			&conv_cap_g_long_double_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.1G|%.2G|%.5G|%.12G\", 0.000099, 0.000099, 0.000099, 0.000099, 0.000099",
			&conv_cap_g_rounding_only_nines_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.1G|%.2G|%.5G|%.12G\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_g_rounding_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.1G|%.2G|%.5G|%.12G\", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999",
			&conv_cap_g_rounding_not_only_nines, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.1G|%.2G|%.5G|%.12G\", 899.9999999, 899.9999999, 899.9999999, 899.9999999, 899.9999999",
			&conv_cap_g_rounding_not_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.1G|%.2G|%.5G|%.12G\", 42.974234687, 42.974234687, 42.974234687, 42.974234687, 42.974234687",
			&conv_cap_g_rounding_normal, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%2.G|%2.1G|%2.2G|%2.5G|%2.12G\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_g_rounding_only_nines_width_small, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.G|%15.1G|%15.2G|%15.5G|%15.12G\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_g_rounding_only_nines_width_large, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.G|%.G|%.G|%.G\", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52",
			&conv_cap_g_rounding_middle_down, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.G|%.G|%.G|%.G|%.G\", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52",
			&conv_cap_g_rounding_middle_up, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%G|%G|%G|%G|%G\", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201",
			&conv_cap_g_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.350G|%.350G|%.350G|%.350G|%.350G\", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201",
			&conv_cap_g_negative_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1150G|%.1150G|%.1150G|%.1150G\", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037",
			&conv_cap_g_denormalized_numbers, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.2147483649G|%2147483649G\", 1.0, 1.0",
			&conv_cap_g_errors, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
