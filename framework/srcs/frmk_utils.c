/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:38:33 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:38:35 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes:
**   - stdlib.h: malloc
**   - string.h: bzero, memcpy
*/

#include <stdlib.h>
#include <string.h>

/*
** Allocate a clean memory space.
*/

void	*memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	bzero(mem, size);
	return (mem);
}

/*
** Concatenate two memory spaces.
*/

void	*memcat(void *s1, size_t n1, const void *s2, size_t n2)
{
	unsigned char		*tmp_s1;
	const unsigned char *tmp_s2;
	size_t 				i;

	i = 0;
	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	while (i < n2)
	{
		tmp_s1[n1 + i] = tmp_s2[i];
		i++;
	}
	return (s1);
}

/*
** Return a pointer to a newly allocated memory space containing two memory
** spaces join together.
*/

void	*memjoin(const void *s1, size_t n1, const void *s2, size_t n2)
{
	unsigned char	*s3;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = memalloc(n1 + n2 + 1)))
		return (NULL);
	memcpy(s3, s1, n1);
	memcat(s3, n1, s2, n2);
	return (s3);
}
