/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxtoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:53:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/20 19:53:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_maxtoa_base(intmax_t n, int base)
{
	char				*ascii;
	int					cb;
	uintmax_t			o;

	if (2 > base || base > 16)
		return (NULL);
	cb = ft_count_base(n, base);
	if (!(ascii = ft_strnew(cb)))
		return (NULL);
	ascii[cb] = '\0';
	o = n;
	if (n < 0)
	{
		o *= -1;
		if (base == 10)
			ascii[0] = '-';
	}
	while (o / base)
	{
		ascii[--cb] = ft_base_char(o % base);
		o /= base;
	}
	ascii[--cb] = ft_base_char(o % base);
	return (ascii);
}
