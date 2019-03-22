#include "frmk_libunit.h"
#include "tests.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

# define ARGS "%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c|%14c", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127

int		conv_c_ascii_chars_8_width(void)
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
