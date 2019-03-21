/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:04:12 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/18 18:11:49 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes:
**   - libunit.h: t_unit_test, t_stats, color macros, 
**   - error.h: user defined errors (EUSIG, ENULL);
**   - stdio.h: dprintf
**   - signal.h: signal macros
**   - string.h: strsignal
*/

#include "libunit.h"
#include "error.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>

void		print_fct_name_fd(char *fct_name, int fd)
{
	dprintf(fd, "%s:\n", fct_name);
}


void		print_test_name_fd(char *test_name, int fd)
{
	dprintf(fd, "  > %s: ", test_name);
}

void		print_error_fd(int err, int fd)
{
	if (err < 200)
		dprintf(fd, "%s", strsignal(err));
	else if (err == ENULL)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "NULL pointer.");
	else if (err == EUSIG)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "Undefined signal catched.");
	else
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "Undefined error.");
}

void		print_test_result_fd(t_unit_test *test, t_stats *stats, int fd)
{
	stats->count_tests += 1;
	if (stats->status == test->exp_ret)
	{
		dprintf(fd, COLOR_GREEN "%s\n" COLOR_RESET, "[OK]");
		stats->count_success += 1;
	}
	else if (stats->status == 0 || stats->status == 255)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[KO]");
	else if (stats->status == SIGBUS)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[BUSE]");
	else if (stats->status == SIGSEGV)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[SEGV]");
	else if (stats->status == SIGABRT)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[SIGA]");
	else if (stats->status == SIGALRM)
		dprintf(fd, COLOR_RED "%s\n" COLOR_RESET, "[TIME]");
	else
	{
		dprintf(fd, COLOR_RED "%s" COLOR_RESET, "[IERR] -> ");
		print_error_fd(stats->status, fd);
	}
}

void		print_final_fd(t_stats *stats, int fd)
{
	if (stats->count_success == stats->count_tests)
		dprintf(fd, COLOR_GREEN "⟹  %d/%d checked\n" COLOR_RESET, 
							stats->count_success, stats->count_tests);
	else
		dprintf(fd, COLOR_RED "⟹  %d/%d checked\n" COLOR_RESET, 
							stats->count_success, stats->count_tests);
}
