/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:44:41 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 19:48:15 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t count)
{
	size_t				i;
	unsigned char		*str;
	unsigned char const	*ch;

	str = dest;
	ch = src;
	i = 0;
	if (ch > str)
	{
		while (count--)
		{
			str[i] = ch[i];
			++i;
		}
	}
	else
	{
		while (count--)
			str[count] = ch[count];
	}
	return (str);
}
