#include "libunit.h"
#include "ft_printf.h"
#include "conv_g.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_g_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_g_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_g";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", 0., 0., 0., 0., 0., 0.",
			&conv_g_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", -0., -0., -0., -0., -0., -0.",
			&conv_g_minus_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_g_nan_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_g_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_g_minus_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", 42., 42., 42., 42., 42., 42.",
			&conv_g_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lg|%-lg|%+lg|% lg|%#lg|%0lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5lg|%-5lg|%+5lg|% 5lg|%#5lg|%05lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_and_5_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lg|%-1lg|%+1lg|% 1lg|%#1lg|%01lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_and_1_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lg|%-.lg|%+.lg|% .lg|%#.lg|%0.lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_and_dot_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8lg|%-.8lg|%+.8lg|% .8lg|%#.8lg|%0.8lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8lg|%-5.8lg|%+5.8lg|% 5.8lg|%#5.8lg|%05.8lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_and_5_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8lg|%-15.8lg|%+15.8lg|% 15.8lg|%#15.8lg|%015.8lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_and_15_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14lg|%- 8.14lg|%-#8.14lg|%-08.14lg|%-+#8.14lg|%-+ #08.14lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_combined_with_minus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14lg|%+ 8.14lg|%+-8.14lg|%+#8.14lg|%+08.14lg|%+ -#08.14lg\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_g_double_various_flags_combined_with_plus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", -42., -42., -42., -42., -42., -42.",
			&conv_g_negative_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_g_double_max_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%-g|%+g|% g|%#g|%0g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5g|%-5g|%+5g|% 5g|%#5g|%05g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1g|%-1g|%+1g|% 1g|%#1g|%01g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%-.g|%+.g|% .g|%#.g|%0.g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8g|%-.8g|%+.8g|% .8g|%#.8g|%0.8g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8g|%-5.8g|%+5.8g|% 5.8g|%#5.8g|%05.8g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8g|%-15.8g|%+15.8g|% 15.8g|%#15.8g|%015.8g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14g|%- 8.14g|%-#8.14g|%-08.14g|%-+#8.14g|%-+ #08.14g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14g|%+ 8.14g|%+-8.14g|%+#8.14g|%+08.14g|%+ -#08.14g\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_g_double_min_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Lg|%-Lg|%+Lg|% Lg|%#Lg|%0Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5Lg|%-5Lg|%+5Lg|% 5Lg|%#5Lg|%05Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1Lg|%-1Lg|%+1Lg|% 1Lg|%#1Lg|%01Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.Lg|%-.Lg|%+.Lg|% .Lg|%#.Lg|%0.Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8Lg|%-.8Lg|%+.8Lg|% .8Lg|%#.8Lg|%0.8Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8Lg|%-5.8Lg|%+5.8Lg|% 5.8Lg|%#5.8Lg|%05.8Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8Lg|%-15.8Lg|%+15.8Lg|% 15.8Lg|%#15.8Lg|%015.8Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14Lg|%- 8.14Lg|%-#8.14Lg|%-08.14Lg|%-+#8.14Lg|%-+ #08.14Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14Lg|%+ 8.14Lg|%+-8.14Lg|%+#8.14Lg|%+08.14Lg|%+ -#08.14Lg\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_g_long_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Lg\", LDBL_MAX",
			&conv_g_long_double_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Lg\", LDBL_MIN",
			&conv_g_long_double_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.1g|%.2g|%.5g|%.12g\", 0.000099, 0.000099, 0.000099, 0.000099, 0.000099",
			&conv_g_rounding_only_nines_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.1g|%.2g|%.5g|%.12g\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_g_rounding_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.1g|%.2g|%.5g|%.12g\", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999",
			&conv_g_rounding_not_only_nines, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.1g|%.2g|%.5g|%.12g\", 899.9999999, 899.9999999, 899.9999999, 899.9999999, 899.9999999",
			&conv_g_rounding_not_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.1g|%.2g|%.5g|%.12g\", 42.974234687, 42.974234687, 42.974234687, 42.974234687, 42.974234687",
			&conv_g_rounding_normal, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%2.g|%2.1g|%2.2g|%2.5g|%2.12g\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_g_rounding_only_nines_width_small, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.g|%15.1g|%15.2g|%15.5g|%15.12g\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_g_rounding_only_nines_width_large, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.g|%.g|%.g|%.g\", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52",
			&conv_g_rounding_middle_down, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.g|%.g|%.g|%.g|%.g\", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52",
			&conv_g_rounding_middle_up, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%g|%g|%g|%g|%g\", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201",
			&conv_g_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.350g|%.350g|%.350g|%.350g|%.350g\", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201",
			&conv_g_negative_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1150g|%.1150g|%.1150g|%.1150g\", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037",
			&conv_g_denormalized_numbers, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
