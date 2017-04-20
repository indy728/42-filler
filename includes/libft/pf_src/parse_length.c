/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 14:30:30 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 20:46:16 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_length		data_length(char c0, char c1)
{
	t_length	len;

	if (c0 == 'h')
		len = H;
	else if (c0 == 'l')
		len = L;
	else if (c0 == 'j')
		len = J;
	else if (c0 == 'z')
		len = Z;
	else
		len = DEFAULT;
	if (len == H && c1 == 'h')
		len = HH;
	else if (len == L && c1 == 'l')
		len = LL;
	return (len);
}

void				parse_length(t_mess *mess, t_mods *mods)
{
	char	c0;
	char	c1;

	c0 = char_at_x(mess, 0);
	if (c0)
	{
		c1 = char_at_x(mess, 1);
		mods->length = data_length(c0, c1);
		if (mods->length != DEFAULT)
			++mess->x;
		if (mods->length == HH || mods->length == LL)
			++mess->x;
	}
}
