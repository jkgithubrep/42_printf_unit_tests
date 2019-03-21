/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:58:04 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/03 14:51:56 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	*memalloc(size_t size);
void	*memcat(void *s1, size_t n1, const void *s2, size_t n2);
void	*memjoin(const void *s1, size_t n1, const void *s2, size_t n2);

#endif
