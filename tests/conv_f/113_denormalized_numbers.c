#include "libunit.h"
#include "tests.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

# define ARGS "%.1150f|%.1150f|%.1150f|%.1150f", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037

int		conv_f_denormalized_numbers(void)
{
	t_test_rslt	test_rslt;
	int			pfd[2];
	int			nbytes_read;
	int			ret_value;
	int			save_out;
	int			err;
	int			fd_trace;

	test_rslt = (t_test_rslt){NULL, NULL, 0, 0};
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	if ((err = pipe_stdout(pfd, &save_out)))
		return (free_result(&test_rslt, err));
	test_rslt.ref_ret = printf(ARGS);
	if ((err = read_pipe(&test_rslt.ref_str, &nbytes_read, pfd, &save_out)))
		return (free_result(&test_rslt, err));
	if ((err = pipe_stdout(pfd, &save_out)))
		return (free_result(&test_rslt, err));
	test_rslt.user_ret = ft_printf(ARGS);
	if ((err = read_pipe(&test_rslt.user_str, &nbytes_read, pfd, &save_out)))
		return (free_result(&test_rslt, err));
	if ((test_rslt.user_ret != test_rslt.ref_ret)
			|| memcmp(test_rslt.user_str, test_rslt.ref_str, test_rslt.ref_ret))
	{
		print_test_result_values_trace(&test_rslt, fd_trace);
		ret_value = -1;
	}
	else
	{
		print_test_result_values_trace(&test_rslt, fd_trace);
		ret_value = 0;
	}
	return (free_result(&test_rslt, ret_value));
}
