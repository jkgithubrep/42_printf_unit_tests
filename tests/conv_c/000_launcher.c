#include "libunit.h"
#include "ft_printf.h"
#include "conv_c.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_c_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_c_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_c";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);

	if ((err = load_test(&test_list, "\"%c\", 0",
			&conv_c_non_printable_ascii_char_nul, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%4c\", 0",
			&conv_c_char_null_and_4_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-4c\", 0",
			&conv_c_char_null_and_minus_flag_and_4_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 9",
			&conv_c_non_printable_ascii_char_horizontal_tab, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 11",
			&conv_c_non_printable_ascii_char_vertical_tab, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", '3'",
			&conv_c_digit_ascii_char_3, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 'z'",
			&conv_c_capital_letter_ascii_char_z, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 'a'",
			&conv_c_small_letter_ascii_char_a, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 42",
			&conv_c_symbol_ascii_char_asterisk, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 127",
			&conv_c_non_printable_ascii_char_del, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 128",
			&conv_c_int_greater_than_127_128, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", 298",
			&conv_c_int_greater_than_127_298, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", -1",
			&conv_c_negative_number_minus_1, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", -42",
			&conv_c_negative_number_minus_42, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c\", -159",
			&conv_c_negative_number_minus_159, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%10c\", 'a'",
			&conv_c_small_letter_ascii_char_a_and_10_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-10c\", 'a'",
			&conv_c_small_letter_ascii_char_a_and_minus_flag_and_10_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-----10c\", 'a'",
			&conv_c_small_letter_ascii_char_a_and_multiple_minus_flags_and_10_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c%c%c%c\", 'a', 'b', 'c', 'd'",
			&conv_c_multiple_chars, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"a%c b%c c%c d%c\", 'a', 'b', 'c', 'd'",
			&conv_c_multiple_chars_and_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%c%c%c\", 0, 0, 0",
			&conv_c_only_zeros_char, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"hello ca%----4c %c va %10c%-c ??\", '', 'n', (char)110, 0",
			&conv_c_hard, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/

	return (launch_tests(&test_list, fd));
}
