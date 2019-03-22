/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frmk_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:40:03 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/22 16:40:15 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRMK_ERROR_H
# define FRMK_ERROR_H

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
