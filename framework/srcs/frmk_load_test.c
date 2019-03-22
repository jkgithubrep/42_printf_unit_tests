/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_load_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:37:56 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:48:51 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes:
**   - frmk_libunit.h: t_unit_test
**   - frmk_error.h: user defined errors (EUSIG, ENULL)
**   - stdlib.h: malloc
**   - errno.h: errno
*/

#include "frmk_libunit.h"
#include "frmk_error.h"
#include <stdlib.h>
#include <errno.h>

static int				create_test(t_unit_test **test, char *test_name, 
							int (*test_fct)(void), int exp_ret)
{
	if (!(*test = (t_unit_test *)malloc(sizeof(t_unit_test))))
		return (errno);
	(*test)->test_name = test_name;
	(*test)->exp_ret = exp_ret;
	(*test)->test_fct = test_fct;
	(*test)->next = NULL;
	return (0);
}

int						load_test(t_unit_test **test_list, char *test_name,
									int (*test_fct)(void), int exp_ret)
{
	t_unit_test		*test;
	t_unit_test		*list;
	int				err;

	if (!test_list || !test_name || !test_fct)
		return (ENULL);
	test = NULL;
	if ((err = create_test(&test, test_name, test_fct, exp_ret)))
		return (err);
	list = *test_list;
	if (!list)
		*test_list = test;
	else
	{
		while (list->next)
			list = list->next;
		list->next = test;
	}
	return (0);
}
