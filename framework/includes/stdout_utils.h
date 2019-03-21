/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdout_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:48:03 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/03 13:55:45 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDOUT_UTILS_H
# define STDOUT_UTILS_H

int			get_fd(const char *path, t_output_mode output_mode,
					t_open_mode open_mode);
int			pipe_stdout(int *pfd, int *save_out);
int			reconnect_stdout(int *save_out);
int			read_pipe(char **str, int *ret, int *pfd, int *save_out);

#endif
