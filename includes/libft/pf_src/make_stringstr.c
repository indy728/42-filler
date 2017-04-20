/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stringstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:10:33 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 21:24:27 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_stringstr(t_mods *mods, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return (ft_strdup("(null)"));
	str = ft_strdup(str);
	if (mods->dot && ft_strlen(str) > mods->prec)
		ft_bzero((void *)(str + mods->prec), ft_strlen(str) - mods->prec);
	return (str);
}
