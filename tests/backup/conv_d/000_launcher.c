#include "libunit.h"
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
	if ((err = load_test(&test_list, "\"%d\", 0",
			&conv_d_zero, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d\", 0",
			&conv_d_zero_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3d\", 0",
			&conv_d_zero_and_dot_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", -0",
			&conv_d_negative_zero, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d\", -0",
			&conv_d_negative_zero_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3d\", -0",
			&conv_d_negative_zero_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", -42",
			&conv_d_negative_int, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.d\", -42",
			&conv_d_negative_int_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3d\", -42",
			&conv_d_negative_int_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", 42",
			&conv_d_random_int, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", 2147483647",
			&conv_d_int_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", 2147483648",
			&conv_d_int_max_plus_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", -2147483648",
			&conv_d_int_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d\", 4294967295",
			&conv_d_unsigned_int_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1d\", 42",
			&conv_d_random_int_and_1_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.4d\", 42",
			&conv_d_random_int_and_4_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%3.5d\", 42",
			&conv_d_random_int_and_3_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.3d\", 42",
			&conv_d_random_int_and_5_width_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%0d\", 42",
			&conv_d_random_int_and_0_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%05d\", 42",
			&conv_d_random_int_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%00005d\", 42",
			&conv_d_random_int_and_multiple_0_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+d\", 42",
			&conv_d_random_int_and_plus_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%++++d\", 42",
			&conv_d_random_int_and_multiple_plus_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"% 05d\", 42",
			&conv_d_random_int_and_space_flag_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+05d\", 42",
			&conv_d_random_int_and_plus_flag_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+++++000005d\", 42",
			&conv_d_random_int_and_multiple_plus_flags_and_multiple_0_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"% d\", 42",
			&conv_d_random_int_and_space_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%     d\", 42",
			&conv_d_random_int_and_multiple_space_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5d\", 42",
			&conv_d_random_int_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+5d\", 42",
			&conv_d_random_int_and_plus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1d\", 42",
			&conv_d_random_int_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5d\", 42",
			&conv_d_random_int_and_minus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%------5d\", 42",
			&conv_d_random_int_and_multiple_minus_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+5d\", 42",
			&conv_d_random_int_and_minus_flag_and_plus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%---++++---5d\", 42",
			&conv_d_random_int_and_multiple_minus_flag_and_plus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%- 5d\", 42",
			&conv_d_random_int_and_minus_flag_and_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-1d\", 42",
			&conv_d_random_int_and_minus_flag_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhd\", 42",
			&conv_d_random_char_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hd\", 32767",
			&conv_d_short_max_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hd\", 32767",
			&conv_d_short_max_and_1_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%ld\", 9223372036854775807",
			&conv_d_long_max_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lld\", 9223372036854775807",
			&conv_d_long_long_max_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%ld\", 9223372036854775807",
			&conv_d_long_long_max_and_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"before %d after\", 42",
			&conv_d_random_int_with_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%d%d%d%d\", 42, -42, 0, -0",
			&conv_d_only_multiple_ints, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"first%dsecond%dthird%dfourth%d\", 42, -42, 0, -0",
			&conv_d_multiple_ints_with_string, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
