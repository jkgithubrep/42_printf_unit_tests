#include "libunit.h"
#include "ft_printf.h"
#include "conv_cap_e.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_cap_e_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_cap_e_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_cap_e";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", 0., 0., 0., 0., 0., 0.",
			&conv_cap_e_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", -0., -0., -0., -0., -0., -0.",
			&conv_cap_e_minus_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_cap_e_nan_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_cap_e_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_cap_e_minus_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", 42., 42., 42., 42., 42., 42.",
			&conv_cap_e_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lE|%-lE|%+lE|% lE|%#lE|%0lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5lE|%-5lE|%+5lE|% 5lE|%#5lE|%05lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_and_5_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lE|%-1lE|%+1lE|% 1lE|%#1lE|%01lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_and_1_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lE|%-.lE|%+.lE|% .lE|%#.lE|%0.lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_and_dot_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8lE|%-.8lE|%+.8lE|% .8lE|%#.8lE|%0.8lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8lE|%-5.8lE|%+5.8lE|% 5.8lE|%#5.8lE|%05.8lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_and_5_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8lE|%-15.8lE|%+15.8lE|% 15.8lE|%#15.8lE|%015.8lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_and_15_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14lE|%- 8.14lE|%-#8.14lE|%-08.14lE|%-+#8.14lE|%-+ #08.14lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_combined_with_minus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14lE|%+ 8.14lE|%+-8.14lE|%+#8.14lE|%+08.14lE|%+ -#08.14lE\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_cap_e_double_various_flags_combined_with_plus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", -42., -42., -42., -42., -42., -42.",
			&conv_cap_e_negative_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_cap_e_double_max_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%-E|%+E|% E|%#E|%0E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5E|%-5E|%+5E|% 5E|%#5E|%05E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1E|%-1E|%+1E|% 1E|%#1E|%01E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%-.E|%+.E|% .E|%#.E|%0.E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8E|%-.8E|%+.8E|% .8E|%#.8E|%0.8E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8E|%-5.8E|%+5.8E|% 5.8E|%#5.8E|%05.8E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8E|%-15.8E|%+15.8E|% 15.8E|%#15.8E|%015.8E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14E|%- 8.14E|%-#8.14E|%-08.14E|%-+#8.14E|%-+ #08.14E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14E|%+ 8.14E|%+-8.14E|%+#8.14E|%+08.14E|%+ -#08.14E\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_cap_e_double_min_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LE|%-LE|%+LE|% LE|%#LE|%0LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5LE|%-5LE|%+5LE|% 5LE|%#5LE|%05LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1LE|%-1LE|%+1LE|% 1LE|%#1LE|%01LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.LE|%-.LE|%+.LE|% .LE|%#.LE|%0.LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8LE|%-.8LE|%+.8LE|% .8LE|%#.8LE|%0.8LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8LE|%-5.8LE|%+5.8LE|% 5.8LE|%#5.8LE|%05.8LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8LE|%-15.8LE|%+15.8LE|% 15.8LE|%#15.8LE|%015.8LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14LE|%- 8.14LE|%-#8.14LE|%-08.14LE|%-+#8.14LE|%-+ #08.14LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14LE|%+ 8.14LE|%+-8.14LE|%+#8.14LE|%+08.14LE|%+ -#08.14LE\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_cap_e_long_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LE\", LDBL_MAX",
			&conv_cap_e_long_double_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%LE\", LDBL_MIN",
			&conv_cap_e_long_double_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.1E|%.2E|%.5E|%.12E\", 0.000099, 0.000099, 0.000099, 0.000099, 0.000099",
			&conv_cap_e_rounding_only_nines_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.1E|%.2E|%.5E|%.12E\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_e_rounding_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.1E|%.2E|%.5E|%.12E\", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999",
			&conv_cap_e_rounding_not_only_nines, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.1E|%.2E|%.5E|%.12E\", 899.9999999, 899.9999999, 899.9999999, 899.9999999, 899.9999999",
			&conv_cap_e_rounding_not_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.1E|%.2E|%.5E|%.12E\", 42.974234687, 42.974234687, 42.974234687, 42.974234687, 42.974234687",
			&conv_cap_e_rounding_normal, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%2.E|%2.1E|%2.2E|%2.5E|%2.12E\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_e_rounding_only_nines_width_small, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.E|%15.1E|%15.2E|%15.5E|%15.12E\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_cap_e_rounding_only_nines_width_large, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.E|%.E|%.E|%.E\", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52",
			&conv_cap_e_rounding_middle_down, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.E|%.E|%.E|%.E|%.E\", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52",
			&conv_cap_e_rounding_middle_up, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%E|%E|%E|%E|%E\", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201",
			&conv_cap_e_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.350E|%.350E|%.350E|%.350E|%.350E\", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201",
			&conv_cap_e_negative_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1150E|%.1150E|%.1150E|%.1150E\", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037",
			&conv_cap_e_denormalized_numbers, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.2147483649E|%2147483649E\", 1.0, 1.0",
			&conv_cap_e_errors, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
