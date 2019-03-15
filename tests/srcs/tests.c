/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:37:08 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/14 15:16:50 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

void		print_header_fd(int fd)
{
 dprintf(fd, " ____       _       _    __   _            _       \n");
 dprintf(fd, "|  _ \\ _ __(_)_ __ | |_ / _| | |_ ___  ___| |_ ___ \n");
 dprintf(fd, "| |_) | '__| | '_ \\| __| |_  | __/ _ \\/ __| __/ __|\n");
 dprintf(fd, "|  __/| |  | | | | | |_|  _| | ||  __/\\__ \\ |_\\__ \\\n");
 dprintf(fd, "|_|   |_|  |_|_| |_|\\__|_|    \\__\\___||___/\\__|___/\n\n");

 dprintf(fd, "     by: jkettani\n\n");
}

void		print_test_result_values_trace(t_test_rslt *test_rslt, int fd_trace)
{
	dprintf(fd_trace, "  > %8s: |%s|, ret = %d\n", "expected",
								test_rslt->ref_str, test_rslt->ref_ret);
	dprintf(fd_trace, "  > %8s: |%s|, ret = %d\n", "actual",
								test_rslt->user_str, test_rslt->user_ret);
}

int			free_result(t_test_rslt *test_rslt, int ret_value)
{
	if (test_rslt->user_str)
		free(test_rslt->user_str);
	if (test_rslt->ref_str)
		free(test_rslt->ref_str);
	return (ret_value);
}
