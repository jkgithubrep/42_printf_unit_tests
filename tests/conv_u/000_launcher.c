#include "libunit.h"
#include "ft_printf.h"
#include "conv_u.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_u_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_u_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_u";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);

	if ((err = load_test(&test_list, "\"%u\", 0U",
			&conv_u_zero, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.u\", 0U",
			&conv_u_zero_and_dot, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3u\", 0U",
			&conv_u_zero_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%u\", 42U",
			&conv_u_random_unsigned_int, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%u\", 4294967295",
			&conv_u_unsigned_int_max, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%u\", 4294967296",
			&conv_u_unsigned_int_max_and_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.1u\", 42U",
			&conv_u_random_unsigned_int_and_1_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.4u\", 42U",
			&conv_u_random_unsigned_int_and_4_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%3.5u\", 42U",
			&conv_u_random_unsigned_int_and_3_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5.3u\", 42U",
			&conv_u_random_unsigned_int_and_5_width_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%0u\", 42U",
			&conv_u_random_unsigned_int_and_0_flag, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%05u\", 42U",
			&conv_u_random_unsigned_int_and_0_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%00005u\", 42U",
			&conv_u_random_unsigned_int_and_multiple_0_flags_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5u\", 42U",
			&conv_u_random_unsigned_int_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1u\", 42U",
			&conv_u_random_unsigned_int_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5u\", 42U",
			&conv_u_random_unsigned_int_and_minus_flag_and_5, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5u\", 42U",
			&conv_u_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%------5u\", 42U",
			&conv_u_random_unsigned_int_and_multiple_minus_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhu\", (unsigned char)42u",
			&conv_u_random_unsigned_char_and_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hu\", (unsigned short)USHRT_MAX",
			&conv_u_unsigned_short_max_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hu\", (unsigned short)(USHRT_MAX + 1)",
			&conv_u_unsigned_short_max_and_1_and_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lu\", (unsigned long)ULONG_MAX",
			&conv_u_unsigned_long_max_and_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%llu\", (unsigned long long)ULLONG_MAX",
			&conv_u_unsigned_long_long_max_and_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/

	return (launch_tests(&test_list, fd));
}
