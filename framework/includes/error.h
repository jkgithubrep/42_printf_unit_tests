/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 22:23:48 by jkettani          #+#    #+#             */
/*   Updated: 2019/01/25 11:12:21 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** ERROR CODES
** Error codes in errno.h goes from 1 to 131.
** So we start at 200 for our own error codes:
** > ENULL: null pointer in function
** > EUSIG: undefined signal catched
*/
# define ENULL 200
# define EUSIG 201

#endif
