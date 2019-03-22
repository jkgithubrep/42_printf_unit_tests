#include "frmk_libunit.h"
#include "ft_printf.h"
#include "TMPL_FCT_NAME.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&TMPL_FCT_NAME_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					TMPL_FCT_NAME_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "TMPL_FCT_NAME";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
