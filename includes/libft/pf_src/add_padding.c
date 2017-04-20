/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 01:23:58 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 01:35:58 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	add_padding(t_mods *mods, char **str)
{
	char		*pad;
	char		filler;
	intmax_t	needed;

	needed = mods->fwidth - ft_strlen(*str);
	if (needed > 0)
	{
		if (mods->flags.zero
				&& (mods->spec == HEX_LOWER || mods->spec == HEX_UPPER))
			filler = '0';
		else
			filler = ' ';
		pad = ft_strnew(needed);
		ft_memset(pad, filler, needed);
		if (mods->flags.minus)
			*str = ft_strmove(ft_strjoin(*str, pad), str);
		else
			*str = ft_strmove(ft_strjoin(pad, *str), str);
		ft_freezero((void *)pad, ft_strlen(pad));
	}
}
