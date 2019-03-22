#include "frmk_libunit.h"
#include "ft_printf.h"
#include "mix.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&mix_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					mix_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "mix";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"abcd%%efg%dgh%u%i%c%s%f\", -42, 42u, -56, 'z', \"this is a string followed by a float: \", 2.33456",
			&mix_various_mix_simple, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"abcd%%efg%-23.10dgh%42.4u%+2.10i%-22c%.23s%.32f\", -42, 42u, -56, 'z', \"this is a string followed by a float: \", 2.33456",
			&mix_various_mix_with_flags, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
