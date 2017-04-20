/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:00:52 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/20 20:03:42 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_umaxtoa_base(uintmax_t n, int base)
{
	char				*ascii;
	int					cb;

	if (2 > base || base > 16)
		return (NULL);
	cb = ft_countu_base(n, base);
	if (!(ascii = ft_strnew(cb)))
		return (NULL);
	ascii[cb] = '\0';
	while (n / base)
	{
		ascii[--cb] = ft_base_char(n % base);
		n /= base;
	}
	ascii[--cb] = ft_base_char(n % base);
	return (ascii);
}
