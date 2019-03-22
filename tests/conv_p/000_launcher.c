#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_p.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_p_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_p_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_p";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%p\", NULL",
			&conv_p_null_pointer, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%p\", \"Random string\"",
			&conv_p_random_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%5p\", \"Random string\"",
			&conv_p_random_string_and_5_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%30p\", \"Random string\"",
			&conv_p_random_string_and_30_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-30p\", \"Random string\"",
			&conv_p_random_string_and_minus_flag_and_30_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%p\", &printf",
			&conv_p_function_pointer, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
