/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 16:27:36 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/04 19:13:52 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

typedef struct		s_test_rslt{
	char 			*user_str;
	char			*ref_str;
	int				user_ret;
	int				ref_ret;
}					t_test_rslt;

void				print_header_fd(int fd);
void				print_test_result_values_trace(t_test_rslt *test_rslt,
																int fd_trace);
int					free_result(t_test_rslt *test_rslt, int ret_value);

# endif
