/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:15:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 00:46:12 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	pad_decimal_str(t_mods *mods, char **str)
{
	int		prefix;
	int		size;
	int		needed;
	char	*dec_str;

	size = ft_strlen(*str);
	prefix = ft_isdigit(*str[0]) ? 0 : 1;
	if (mods->flags.zero)
		needed = mods->fwidth - size;
	else
		needed = mods->prec + prefix - size;
	if (needed > 0)
	{
		dec_str = ft_strnew(size + needed + prefix);
		if (prefix)
			dec_str[0] = *str[0];
		ft_memset(dec_str + prefix, '0', needed);
		ft_strcpy(dec_str + prefix + needed, *str + prefix);
		*str = ft_strmove(dec_str, str);
	}
}

static void	pad_hex_str(t_mods *mods, char **str)
{
	int		size;
	int		needed;
	char	*hex_str;

	size = ft_strlen(*str);
	if (mods->flags.zero)
		needed = mods->fwidth - size;
	else
		needed = mods->prec - size;
	if (needed > 0)
	{
		hex_str = ft_strnew(size + needed);
		ft_strncpy(hex_str, *str, 2);
		ft_memset(hex_str + 2, '0', needed);
		ft_strcpy(hex_str + 2 + needed, *str + 2);
		*str = ft_strmove(hex_str, str);
	}
}

static void	pad_str(t_mods *mods, char **str)
{
	int		size;
	int		needed;
	char	*dec_str;

	size = ft_strlen(*str);
	if (mods->flags.zero)
		needed = mods->fwidth - size;
	else
		needed = mods->prec - size;
	if (needed > 0)
	{
		dec_str = ft_strnew(size + needed);
		ft_memset(dec_str, '0', needed);
		ft_strcpy(dec_str + needed, *str);
		*str = ft_strmove(dec_str, str);
	}
}

void		add_precision(t_mods *mods, char **str)
{
	if (mods->spec == SIGNED || mods->spec == UNSIGNED)
		pad_decimal_str(mods, str);
	else if ((mods->flags.hash
			&& (mods->spec == HEX_LOWER || mods->spec == HEX_UPPER))
			|| mods->spec == POINTER)
		pad_hex_str(mods, str);
	else
		pad_str(mods, str);
}
