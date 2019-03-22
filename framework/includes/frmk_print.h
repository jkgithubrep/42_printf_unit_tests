/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_print.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:41:34 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:50:16 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRMK_PRINT_H
# define FRMK_PRINT_H

# include "frmk_libunit.h"

int			get_fd(const char *path, t_output_mode output_mode,
					t_open_mode open_mode);
void		print_error_fd(int err, int fd);
void		print_test_result_fd(t_unit_test *test, t_stats *stats, int fd);
void		print_test_name_trace_fd(char *test_name, int fd);
void		print_test_name_fd(char *test_name, int fd);
void		print_test_result_no_color_fd(t_unit_test *test, t_stats *stats,
																		int fd);
void		print_final_fd(t_stats *stats, int fd);
void		print_fct_name_fd(char *fct_name, int fd);

#endif
