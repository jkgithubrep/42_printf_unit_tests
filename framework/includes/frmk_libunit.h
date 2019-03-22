/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_libunit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:40:27 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:41:19 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRMK_LIBUNIT_H
# define FRMK_LIBUNIT_H

# include <signal.h>
# include <errno.h>
# include <unistd.h>

/*
** Parameters
*/

# define BUF_SIZE 4096
# define TIMEOUT 3
# define OUTPUT_MODE M_FILE
# define TRACE_FILE "trace.txt"
# define TESTS_OUTPUT_FD STDOUT_FILENO

/*
** Colors
*/

# define COLOR_RED "\x1b[1;31m"
# define COLOR_GREEN "\x1b[1;32m"
# define COLOR_RESET "\x1b[0m"

/*
** Definitions
*/

# define SUCCESS 0
# define FAILURE -1


/* 
** test_name: description of the test
** exp_ret: expected return value of the test
** test_fct: test function
*/

typedef struct				s_unit_test
{
	char					*test_name;
	int						exp_ret;
	int						(*test_fct)(void);
	struct s_unit_test		*next;
}							t_unit_test;

/*
** test_ret: return value of the unit test,
** status: status of the unit test (exit status or signal),
** count_success: number of successful tests,
** count_tests: number of tests.
*/

typedef struct				s_stats
{
	int						test_ret;
	int						status;
	int						count_success;
	int						count_tests;
}							t_stats;

/*
** M_STD: output to stdout,
** M_FILE: output to a file.
*/

typedef enum 				e_output_mode
{
	M_STD,
	M_FILE
}							t_output_mode;

/*
** OP_APPEND: use oflag O_APPEND for the open function
** OP_TRUNC: use oflag O_TRUNC for the open function
*/

typedef enum				e_open_mode
{
	OP_APPEND,
	OP_TRUNC
}							t_open_mode;

int							load_test(t_unit_test **test_list, char *test_name, 
										int (*test_fct)(void), int exp_ret);
int							launch_tests(t_unit_test **test_list, int fd);
void						print_error_fd(int err, int fd);
void						print_fct_name_fd(char *fct_name, int fd);
void						print_trace_header_fd(int fd);
void						print_fct_name_trace_fd(char *fct_name, int fd);
int							get_fd(const char *path, t_output_mode output_mode,
									t_open_mode open_mode);
int							pipe_stdout(int *pfd, int *save_out);
int							read_pipe(char **str, int *ret, int *pfd, 
																int *save_out);

#endif
