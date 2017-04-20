/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countu_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:05:14 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/20 20:05:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countu_base(uintmax_t n, int base)
{
	size_t count;

	count = 0;
	if (base < 2)
		return (0);
	while (n / base != 0)
	{
		++count;
		n /= base;
	}
	return (++count);
}
