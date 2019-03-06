/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:19:10 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/04 11:21:12 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

# define ARGS "%-+015.02d", 42

int		printf_basic_test(void)
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
		ret_value = 0;
	return (free_result(&test_rslt, ret_value));
}
