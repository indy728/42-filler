/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:47:29 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 11:58:56 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power_of(int base, int power)
{
	int	pow;

	pow = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
		pow = pow * base;
	return (pow);
}
