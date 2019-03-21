#include "libunit.h"
#include "ft_printf.h"
#include "invalid.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&invalid_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					invalid_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "invalid";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%|%%|%%%|%%%%\"",
			&invalid_percent_signs, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"% |% h|% hZ\"",
			&invalid_percent_and_wrong_type, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%%-%|%%+%|%% %|%%#%\"",
			&invalid_percent_and_flags_and_percent, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
