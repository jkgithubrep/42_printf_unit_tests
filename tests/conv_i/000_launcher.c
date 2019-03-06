#include "libunit.h"
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

	if ((err = load_test(&test_list, "\"%i\", 0",
			&conv_i_zero, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i\", 0",
			&conv_i_zero_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3i\", 0",
			&conv_i_zero_and_dot_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", -0",
			&conv_i_negative_zero, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i\", -0",
			&conv_i_negative_zero_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3i\", -0",
			&conv_i_negative_zero_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", -42",
			&conv_i_negative_int, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.i\", -42",
			&conv_i_negative_int_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3i\", -42",
			&conv_i_negative_int_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", 42",
			&conv_i_random_int, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", 2147483647",
			&conv_i_int_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", 2147483648",
			&conv_i_int_max_plus_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", -2147483648",
			&conv_i_int_min, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i\", 4294967295",
			&conv_i_unsigned_int_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1i\", 42",
			&conv_i_random_int_and_1_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.4i\", 42",
			&conv_i_random_int_and_4_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%3.5i\", 42",
			&conv_i_random_int_and_3_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.3i\", 42",
			&conv_i_random_int_and_5_width_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%0i\", 42",
			&conv_i_random_int_and_0_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%05i\", 42",
			&conv_i_random_int_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%00005i\", 42",
			&conv_i_random_int_and_multiple_0_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+i\", 42",
			&conv_i_random_int_and_plus_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%++++i\", 42",
			&conv_i_random_int_and_multiple_plus_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"% 05i\", 42",
			&conv_i_random_int_and_space_flag_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+05i\", 42",
			&conv_i_random_int_and_plus_flag_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+++++000005i\", 42",
			&conv_i_random_int_and_multiple_plus_flags_and_multiple_0_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"% i\", 42",
			&conv_i_random_int_and_space_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%     i\", 42",
			&conv_i_random_int_and_multiple_space_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5i\", 42",
			&conv_i_random_int_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%+5i\", 42",
			&conv_i_random_int_and_plus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1i\", 42",
			&conv_i_random_int_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5i\", 42",
			&conv_i_random_int_and_minus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%------5i\", 42",
			&conv_i_random_int_and_multiple_minus_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-+5i\", 42",
			&conv_i_random_int_and_minus_flag_and_plus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%---++++---5i\", 42",
			&conv_i_random_int_and_multiple_minus_flag_and_plus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%- 5i\", 42",
			&conv_i_random_int_and_minus_flag_and_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-1i\", 42",
			&conv_i_random_int_and_minus_flag_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhi\", 42",
			&conv_i_random_char_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hi\", 32767",
			&conv_i_short_max_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hi\", 32767",
			&conv_i_short_max_and_1_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%li\", 9223372036854775807",
			&conv_i_long_max_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lli\", 9223372036854775807",
			&conv_i_long_long_max_and_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%li\", 9223372036854775807",
			&conv_i_long_long_max_and_l_length_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"before %i after\", 42",
			&conv_i_random_int_with_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%i%i%i%i\", 42, -42, 0, -0",
			&conv_i_only_multiple_ints, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"first%isecond%ithird%ifourth%i\", 42, -42, 0, -0",
			&conv_i_multiple_ints_with_string, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/

	return (launch_tests(&test_list, fd));
}
