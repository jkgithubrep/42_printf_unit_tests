/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_stdout_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:41:51 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:41:59 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRMK_STDOUT_UTILS_H
# define FRMK_STDOUT_UTILS_H

int			get_fd(const char *path, t_output_mode output_mode,
					t_open_mode open_mode);
int			pipe_stdout(int *pfd, int *save_out);
int			reconnect_stdout(int *save_out);
int			read_pipe(char **str, int *ret, int *pfd, int *save_out);

#endif
