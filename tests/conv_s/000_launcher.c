#include "libunit.h"
#include "ft_printf.h"
#include "conv_s.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_s_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_s_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_s";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);

	if ((err = load_test(&test_list, "\"%s\", NULL",
			&conv_s_null_pointer, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%10s\", NULL",
			&conv_s_null_pointer_10_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.2s\", NULL",
			&conv_s_null_pointer_2_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s\", \"Random string\"",
			&conv_s_random_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.s\", \"Random string\"",
			&conv_s_random_string_and_dot, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.10s\", \"Random string\"",
			&conv_s_random_string_and_10_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%15s\", \"Random string\"",
			&conv_s_random_string_and_15_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-15s\", \"Random string\"",
			&conv_s_random_string_and_minus_flag_and_15_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s\", \"😁\"",
			&conv_s_emoticone, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s\", \"😄\"",
			&conv_s_emoticone_utf8_encoded, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.3s\", \"😁\"",
			&conv_s_emoticone_and_3_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.4s\", \"😁\"",
			&conv_s_emoticone_and_4_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5s\", \"😁\"",
			&conv_s_emoticone_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.10s\", \"😁\"",
			&conv_s_emoticone_and_10_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1s\", \"😁\"",
			&conv_s_emoticone_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-5s\", \"😁\"",
			&conv_s_emoticone_and_minus_flag_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s\", \"ă\"",
			&conv_s_latin_extended_a, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"This is a %s\", \"random string\"",
			&conv_s_string_format_and_random_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"This is a %10s\", \"random string\"",
			&conv_s_string_format_and_random_string_and_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"This is a %.5s\", \"random string\"",
			&conv_s_string_format_and_random_string_and_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s %s - %s %s\", \"string1\", \"string2\", \"string3\", \"string4\"",
			&conv_s_multiple_random_strings, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s%s%s%s\", \"string1\", \"string2\", \"string3\", \"string4\"",
			&conv_s_only_string_conv, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/

	return (launch_tests(&test_list, fd));
}
