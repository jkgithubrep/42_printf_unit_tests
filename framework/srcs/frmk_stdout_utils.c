/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_stdout_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:54:57 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:47:34 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes:
**   - frmk_libunit.h: t_output_mode, t_open_mode, BUF_SIZE
**   - frmk_error.h: ENULL macro
**   - fcntl.h: open function
**   - unistd.h: STDOUT_FILENO, pipe, close, dup, dup2
**   - stdlib.h: malloc
**   - string.h: bzero, memcpy
**   - stdio.h: fflush
*/

#include "frmk_libunit.h"
#include "frmk_error.h"
#include "frmk_utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
** Get a file descriptor.
** If the output mode is stdout, return STDOUT_FILENO, otherwise if the ouput
** mode is a file, open the file and return the corresponding file descriptor.
** File is open either with append mode or trunc mode.
** File permissions: 0666 = 110110110 = rw-rw-rw-
*/

int			get_fd(const char *path, t_output_mode output_mode,
					t_open_mode open_mode)
{
	int		fd;
	int		oflags;	

	if (output_mode == M_STD)
		return (STDOUT_FILENO);
	else if (output_mode == M_FILE)
	{
		oflags = O_RDWR | O_CREAT | ((open_mode == OP_APPEND) ?
													O_APPEND : O_TRUNC);
		if ((fd = open(path, oflags, 0666)) < 0)
			return (-1);
		else
			return (fd);
	}
	else
		return (-1);
}

/*
** Create a descriptor pair with the write end of the pipe being a duplicate of
** stdout.
*/

int			pipe_stdout(int *pfd, int *save_out)
{
	int		fd;

	fd = STDOUT_FILENO;
	if ((*save_out = dup(fd)) < 0)
		return (errno);
	if (pipe(pfd) < 0)
		return (errno);
	if (dup2(pfd[1], fd) < 0)
		return (errno);
	return (0);
}

/*
** Reconnect the default file descriptor for stdout from the one previously
** saved.
*/

int			reconnect_stdout(int *save_out)
{
	if (dup2(*save_out, STDOUT_FILENO) < 0)
		return (errno);
	return (0);
}

/*
** Read the content in the read end of the pipe `pfd' and save it in a memory
** space pointed by `str'. The number of bytes saved in memory is stored in the
** `ret' variable.
** Both ends of the pipe are closed and the default file descriptor for stdout
** is reconnected.
*/

int			read_pipe(char **str, int *ret, int *pfd, int *save_out)
{
	char	buf[BUF_SIZE];
	char	*tmp;
	int		nbytes;
	int		err;
	
	fflush(stdout);
	if (!str)
		return (ENULL);
	if (close(pfd[1]) < 0)
		return (errno);
	if ((err = reconnect_stdout(save_out)))
		return (err);
	if (!*str)
		*str = memalloc(1);;
	*ret = 0;
	while ((nbytes = read(pfd[0], buf, BUF_SIZE)) != 0)
	{
		if (nbytes < 0)
			return (errno);
		tmp = *str;
		if (!(*str = memjoin(tmp, *ret, buf, nbytes)))
		{
			free(tmp);
			return (ENULL);
		}
		*ret += nbytes;
		free(tmp);
	}
	if (close(pfd[0]) < 0)
		return (errno);
	return (0);
}
