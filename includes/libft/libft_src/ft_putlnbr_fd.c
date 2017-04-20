/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 23:41:37 by kmurray           #+#    #+#             */
/*   Updated: 2017/02/15 00:01:31 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlnbr_fd(int n, int fd, int i)
{
	unsigned int	o;

	o = n;
	if (n < 0)
	{
		o *= -1;
		ft_putchar_fd('-', fd);
		++i;
	}
	if (o / 10 == 0)
	{
		ft_putchar_fd(o % 10 + '0', fd);
		return (++i);
	}
	else
	{
		ft_putlnbr_fd(o / 10, fd, ++i);
		ft_putchar_fd(o % 10 + '0', fd);
	}
	return (0);
}
