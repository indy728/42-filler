/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_at_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:00:28 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/17 21:13:09 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** int n is the relative location to mess->x
*/

char	char_at_x(t_mess *mess, int n)
{
	return (*(mess->fmt_str + mess->x + n));
}
