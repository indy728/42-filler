/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:02:36 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 19:08:59 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t count)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		*ch;

	str = (unsigned char *)dest;
	ch = (unsigned char *)src;
	c = (unsigned char)c;
	i = 0;
	while (i < count && ch[i] != c)
	{
		str[i] = ch[i];
		i++;
	}
	if (i == count)
		return (NULL);
	else
		str[i] = ch[i];
	return (&str[i + 1]);
}
