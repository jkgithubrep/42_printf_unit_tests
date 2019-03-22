/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_launch_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:37:45 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:44:56 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes:
**   - frmk_libunit.h: t_unit_test, t_stats, TIMEOUT
**   - frmk_print.h: print functions
**   - frmk_error.h: user defined errors (EUSIG, ENULL)
**   - unistd.h: fork, alarm
**   - stdlib.h: free
**   - sys/wait.h: wait
**   - errno.h: errno
*/

#include "frmk_libunit.h"
#include "frmk_print.h"
#include "frmk_error.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

/*
** Create a new child process, launch the unit test and catch the exit status of
** the test or a signal in the parent process.
*/

static int				launch_unit_test(t_unit_test *test, t_stats *stats)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		alarm(TIMEOUT);
		stats->test_ret = (*test->test_fct)();
		exit(stats->test_ret);
	}
	else if (pid > 0)
	{
		wait(&(stats->status));
		if (WIFEXITED(stats->status))
			stats->status = WEXITSTATUS(stats->status);
		else if (WIFSIGNALED(stats->status))
			stats->status = WTERMSIG(stats->status);
		else
			return (EUSIG);
	}
	else if (pid == -1)
		return (errno);
	return (0);
}

/*
** Delete a node in the list of tests and return a pointer on the next one.
*/

static t_unit_test		*del_test_next(t_unit_test *test)
{
	t_unit_test *next;

	next = test->next;
	free(test); 
	return (next);
}

/*
** Delete the entire list of tests.
*/

static void				del_list(t_unit_test **test_list)
{
	if (!test_list)
		return ;
	while (*test_list)
		*test_list = del_test_next(*test_list);
}

/*
** Launch each unit test stored in `test_list' in a new process, get its return
** value, and print the result accordingly.
** When each unit test has been launched, print the number of successful tests,
** and return 0 if all tests were sucessful, otherwise return -1.
*/

int						launch_tests(t_unit_test **test_list, int fd)
{
	t_unit_test		*test;
	t_stats			stats;
	int				err;
	int				fd_trace;

	if (!test_list)
		return (ENULL);
	stats = (t_stats){0, 0, 0, 0};
	test = *test_list;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	while (test)
	{
		print_test_name_fd(test->test_name, fd);
		if (fd_trace != fd)
			print_test_name_trace_fd(test->test_name, fd_trace);
		if ((err = launch_unit_test(test, &stats)))
		{
			del_list(&test);
			return (err);
		}
		print_test_result_fd(test, &stats, fd);
		if (fd_trace != fd)
			print_test_result_no_color_fd(test, &stats, fd_trace);
		test = del_test_next(test);
	}
	print_final_fd(&stats, fd);
	return ((stats.count_success != stats.count_tests) ? -1 : 0);
}
