/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:42:07 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:42:17 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRMK_UTILS_H
# define FRMK_UTILS_H

void	*memalloc(size_t size);
void	*memcat(void *s1, size_t n1, const void *s2, size_t n2);
void	*memjoin(const void *s1, size_t n1, const void *s2, size_t n2);

#endif
