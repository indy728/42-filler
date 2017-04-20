/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_hexstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 00:45:10 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 20:22:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_hexstr(t_mods *mods, va_list ap)
{
	char		*str;
	char		*prefix;
	uintmax_t	hex;

	hex = get_udecimal(mods->length, ap);
	prefix = "0x";
	if (mods->dot && !hex)
		str = ft_strdup("");
	else
		str = ft_umaxtoa_base(hex, 16);
	if (mods->flags.hash && str[0] && str[0] != '0')
		str = ft_strmove(ft_strjoin(prefix, str), &str);
	add_precision(mods, &str);
	if (mods->spec == HEX_UPPER)
		ft_toupperstr(str);
	return (str);
}
