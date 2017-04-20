/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_octalstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 00:38:14 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 00:44:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_octalstr(t_mods *mods, va_list ap)
{
	char		*str;
	uintmax_t	octal;

	octal = get_udecimal(mods->length, ap);
	if (mods->dot && !octal)
		str = ft_strdup("");
	else
		str = ft_umaxtoa_base(octal, 8);
	add_precision(mods, &str);
	if (mods->flags.hash && str[0] != '0')
		str = ft_strmove(ft_strjoin("0", str), &str);
	return (str);
}
