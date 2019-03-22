#include "frmk_libunit.h"
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
	if ((err = load_test(&test_list, "\"%s|%-s|%23s|%.5s|%.50s|%-23s|%-.5s|%-.50s|%23.5s|%23.50s|%-23.5s|%-23.50s\", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL",
			&conv_s_null_pointer_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s|%-s|%23s|%.5s|%.50s|%-23s|%-.5s|%-.50s|%23.5s|%23.50s|%-23.5s|%-23.50s\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\", \"wi32x-3vx++===98234z1esfatr\"",
			&conv_s_random_string_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s|%-s|%23s|%.5s|%.50s|%-23s|%-.5s|%-.50s|%23.5s|%23.50s|%-23.5s|%-23.50s\",\"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\", \"😁\"",
			&conv_s_emoticone_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%s|%-s|%23s|%.5s|%.50s|%-23s|%-.5s|%-.50s|%23.5s|%23.50s|%-23.5s|%-23.50s\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\", \"xF0x9Fx98x84\"",
			&conv_s_emoticone_utf8_encoded_various_flags, SUCCESS)))
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
	if ((err = load_test(&test_list, " \"%s\", \"WwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqpWwyAlxbZGYIJZGzkjomuMGJgEuAZPbUAUimRUBeAAyoSGmhJCGmBOguEdCViaCsqohhsuRGLkoFQNmTZEZQFLEwvHAEctloDFOpLZGQyDDexpPllnNXympcKOxDyygGcWpdzqp\"",
			&conv_s_very_long_string, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
