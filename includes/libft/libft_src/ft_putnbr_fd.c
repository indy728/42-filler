/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:41:37 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 23:32:04 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	o;

	o = n;
	if (n < 0)
	{
		o *= -1;
		ft_putchar_fd('-', fd);
	}
	if (o / 10 == 0)
		ft_putchar_fd(o % 10 + '0', fd);
	else
	{
		ft_putnbr_fd(o / 10, fd);
		ft_putchar_fd(o % 10 + '0', fd);
	}
}
