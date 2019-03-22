/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_print_trace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:38:22 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:46:57 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes:
**   - frmk_libunit.h: t_unit_test, t_stats
**   - stdio: dprintf
**   - string.h: 
*/

#include "frmk_libunit.h"
#include <stdio.h>
#include <string.h>

void		print_trace_header_fd(int fd)
{
	dprintf(fd, "============= TRACE ==============\n");
}

void		print_fct_name_trace_fd(char *fct_name, int fd)
{
	dprintf(fd, "\n\n%s\n", fct_name);
}

void		print_test_name_trace_fd(char *test_name, int fd)
{
	dprintf(fd, "----------------------------------\n");
	dprintf(fd, "test: %s\n", test_name);
}

void		print_test_result_no_color_fd(t_unit_test *test, t_stats *stats, 
																		int fd)
{
	dprintf(fd, "⟹  ");
	if (stats->status == test->exp_ret)
		dprintf(fd, "%s\n", "[OK]");
	else if (stats->status == 0 || stats->status == 255)
		dprintf(fd, "%s\n", "[KO]");
	else if (stats->status == SIGBUS)
		dprintf(fd, "%s\n", "[BUSE]");
	else if (stats->status == SIGSEGV)
		dprintf(fd, "%s\n", "[SEGV]");
	else if (stats->status == SIGABRT)
		dprintf(fd, "%s\n", "[SIGA]");
	else if (stats->status == SIGALRM)
		dprintf(fd, "%s\n", "[TIME]");
	else
		dprintf(fd, "%s\n", "[UNDEF]");
}
