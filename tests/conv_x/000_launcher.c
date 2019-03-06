#include "libunit.h"
#include "ft_printf.h"
#include "conv_x.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_x_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_x_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_x";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);

	if ((err = load_test(&test_list, "\"%x\", 0U",
			&conv_x_zero, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.x\", 0U",
			&conv_x_zero_and_dot, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3x\", 0U",
			&conv_x_zero_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%x\", 42U",
			&conv_x_random_unsigned_int, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%x\", 4294967295",
			&conv_x_unsigned_int_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%x\", 4294967296",
			&conv_x_unsigned_int_max_and_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1x\", 42U",
			&conv_x_random_unsigned_int_and_1_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.4x\", 42U",
			&conv_x_random_unsigned_int_and_4_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%3.5x\", 42U",
			&conv_x_random_unsigned_int_and_3_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.3x\", 42U",
			&conv_x_random_unsigned_int_and_5_width_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%0x\", 42U",
			&conv_x_random_unsigned_int_and_0_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%05x\", 42U",
			&conv_x_random_unsigned_int_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%00005x\", 42U",
			&conv_x_random_unsigned_int_and_multiple_0_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5x\", 42U",
			&conv_x_random_unsigned_int_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1x\", 42U",
			&conv_x_random_unsigned_int_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5x\", 42U",
			&conv_x_random_unsigned_int_and_minus_flag_and_5, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5x\", 42U",
			&conv_x_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%------5x\", 42U",
			&conv_x_random_unsigned_int_and_multiple_minus_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%#5x\", 42U",
			&conv_x_random_unsigned_int_and_hash_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%#05x\", 42U",
			&conv_x_random_unsigned_int_and_hash_and_zero_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%#5.4x\", 42U",
			&conv_x_random_unsigned_int_and_hash_flag_and_5_width_and_4_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhx\", (unsigned char)42u",
			&conv_x_random_unsigned_char_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hx\", (unsigned short)USHRT_MAX",
			&conv_x_unsigned_short_max_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hx\", (unsigned short)(USHRT_MAX + 1)",
			&conv_x_unsigned_short_max_and_1_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lx\", (unsigned long)ULONG_MAX",
			&conv_x_unsigned_long_max_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%llx\", (unsigned long long)ULLONG_MAX",
			&conv_x_unsigned_long_long_max_and_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/

	return (launch_tests(&test_list, fd));
}
