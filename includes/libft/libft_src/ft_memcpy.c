/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:42:39 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 19:05:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t count)
{
	size_t				i;
	unsigned char		*str;
	unsigned char const	*ch;

	str = dest;
	ch = src;
	i = 0;
	while (i < count)
	{
		str[i] = ch[i];
		++i;
	}
	return (str);
}
