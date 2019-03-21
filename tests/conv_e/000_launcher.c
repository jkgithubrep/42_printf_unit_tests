#include "libunit.h"
#include "ft_printf.h"
#include "conv_e.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_e_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_e_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_e";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", 0., 0., 0., 0., 0., 0.",
			&conv_e_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", -0., -0., -0., -0., -0., -0.",
			&conv_e_minus_zero_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0., 0. / 0.",
			&conv_e_nan_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY",
			&conv_e_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY, -INFINITY",
			&conv_e_minus_infinity_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", 42., 42., 42., 42., 42., 42.",
			&conv_e_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%le|%-le|%+le|% le|%#le|%0le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5le|%-5le|%+5le|% 5le|%#5le|%05le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_and_5_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1le|%-1le|%+1le|% 1le|%#1le|%01le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_and_1_width_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.le|%-.le|%+.le|% .le|%#.le|%0.le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_and_dot_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8le|%-.8le|%+.8le|% .8le|%#.8le|%0.8le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8le|%-5.8le|%+5.8le|% 5.8le|%#5.8le|%05.8le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_and_5_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8le|%-15.8le|%+15.8le|% 15.8le|%#15.8le|%015.8le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_and_15_width_and_8_precision_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14le|%- 8.14le|%-#8.14le|%-08.14le|%-+#8.14le|%-+ #08.14le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_combined_with_minus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14le|%+ 8.14le|%+-8.14le|%+#8.14le|%+08.14le|%+ -#08.14le\", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849",
			&conv_e_double_various_flags_combined_with_plus_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", -42., -42., -42., -42., -42., -42.",
			&conv_e_negative_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX",
			&conv_e_double_max_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%-e|%+e|% e|%#e|%0e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5e|%-5e|%+5e|% 5e|%#5e|%05e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1e|%-1e|%+1e|% 1e|%#1e|%01e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%-.e|%+.e|% .e|%#.e|%0.e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8e|%-.8e|%+.8e|% .8e|%#.8e|%0.8e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8e|%-5.8e|%+5.8e|% 5.8e|%#5.8e|%05.8e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8e|%-15.8e|%+15.8e|% 15.8e|%#15.8e|%015.8e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14e|%- 8.14e|%-#8.14e|%-08.14e|%-+#8.14e|%-+ #08.14e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14e|%+ 8.14e|%+-8.14e|%+#8.14e|%+08.14e|%+ -#08.14e\", DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN, DBL_MIN",
			&conv_e_double_min_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Le|%-Le|%+Le|% Le|%#Le|%0Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5Le|%-5Le|%+5Le|% 5Le|%#5Le|%05Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1Le|%-1Le|%+1Le|% 1Le|%#1Le|%01Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.Le|%-.Le|%+.Le|% .Le|%#.Le|%0.Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.8Le|%-.8Le|%+.8Le|% .8Le|%#.8Le|%0.8Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.8Le|%-5.8Le|%+5.8Le|% 5.8Le|%#5.8Le|%05.8Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_and_5_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.8Le|%-15.8Le|%+15.8Le|% 15.8Le|%#15.8Le|%015.8Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_and_15_width_and_8_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+8.14Le|%- 8.14Le|%-#8.14Le|%-08.14Le|%-+#8.14Le|%-+ #08.14Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_combined_with_minus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+8.14Le|%+ 8.14Le|%+-8.14Le|%+#8.14Le|%+08.14Le|%+ -#08.14Le\", 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L, 12.847e451L",
			&conv_e_long_double_various_flags_combined_with_plus, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Le\", LDBL_MAX",
			&conv_e_long_double_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%Le\", LDBL_MIN",
			&conv_e_long_double_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.1e|%.2e|%.5e|%.12e\", 0.000099, 0.000099, 0.000099, 0.000099, 0.000099",
			&conv_e_rounding_only_nines_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.1e|%.2e|%.5e|%.12e\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_e_rounding_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.1e|%.2e|%.5e|%.12e\", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999",
			&conv_e_rounding_not_only_nines, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.1e|%.2e|%.5e|%.12e\", 899.9999999, 899.9999999, 899.9999999, 899.9999999, 899.9999999",
			&conv_e_rounding_not_only_nines_2, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.1e|%.2e|%.5e|%.12e\", 42.974234687, 42.974234687, 42.974234687, 42.974234687, 42.974234687",
			&conv_e_rounding_normal, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%2.e|%2.1e|%2.2e|%2.5e|%2.12e\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_e_rounding_only_nines_width_small, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15.e|%15.1e|%15.2e|%15.5e|%15.12e\", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999",
			&conv_e_rounding_only_nines_width_large, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.e|%.e|%.e|%.e\", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52",
			&conv_e_rounding_middle_down, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.e|%.e|%.e|%.e|%.e\", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52",
			&conv_e_rounding_middle_up, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%e|%e|%e|%e|%e\", 1.e1, 1.e2, 1.e18, 1.e57, 1.e201",
			&conv_e_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.350e|%.350e|%.350e|%.350e|%.350e\", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201",
			&conv_e_negative_powers_of_10, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1150e|%.1150e|%.1150e|%.1150e\", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037",
			&conv_e_denormalized_numbers, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.2147483649e|%2147483649e\", 1.0, 1.0",
			&conv_e_errors, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
