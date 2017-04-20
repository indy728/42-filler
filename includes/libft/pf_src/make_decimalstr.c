/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_decimalstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:31:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/23 02:15:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static intmax_t	get_decimal(t_length length, va_list ap)
{
	intmax_t	decimal;

	if (length == L)
		decimal = va_arg(ap, long);
	else if (length == LL)
		decimal = va_arg(ap, long long);
	else if (length == J)
		decimal = va_arg(ap, intmax_t);
	else if (length == Z)
		decimal = va_arg(ap, size_t);
	else
		decimal = va_arg(ap, int);
	if (length == HH)
		decimal = (char)decimal;
	else if (length == H)
		decimal = (short)decimal;
	else if (!length)
		decimal = (int)decimal;
	return (decimal);
}

static void		add_prefix(t_mods *mods, char **str)
{
	char	*prefix;

	if (ft_isdigit(*str[0]))
	{
		prefix = NULL;
		if (mods->flags.plus)
			prefix = ft_strdup("+");
		else if (mods->flags.space)
			prefix = ft_strdup(" ");
		if (prefix)
		{
			*str = ft_strmove(ft_strjoin(prefix, *str), str);
			ft_freezero((void *)prefix, ft_strlen(prefix));
		}
	}
}

char			*make_decimalstr(t_mods *mods, va_list ap)
{
	char		*str;
	intmax_t	dec;
	uintmax_t	udec;

	if (mods->spec == UNSIGNED)
		udec = get_udecimal(mods->length, ap);
	else
		dec = get_decimal(mods->length, ap);
	if ((mods->spec == UNSIGNED ? udec == 0 : dec == 0)
			&& (mods->dot + mods->prec == 1))
		str = ft_strdup("");
	else if (mods->spec == UNSIGNED)
		str = ft_umaxtoa_base(udec, 10);
	else
		str = ft_maxtoa_base(dec, 10);
	add_prefix(mods, &str);
	add_precision(mods, &str);
	return (str);
}
