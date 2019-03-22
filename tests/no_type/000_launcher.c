#include "frmk_libunit.h"
#include "ft_printf.h"
#include "no_type.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&no_type_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					no_type_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "no_type";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"\"",
			&no_type_empty_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"n\"",
			&no_type_newline, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"test12345678\"",
			&no_type_normal_string, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"test12345678tvn\"",
			&no_type_normal_string_with_non_printable, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"testn\"",
			&no_type_normal_string_and_newline, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%%|%%%%|%%%%%%|%%abc%%def%%ghi%%\"",
			&no_type_valid_percent_sign, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"WwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqp\"",
			&no_type_very_long_string, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
