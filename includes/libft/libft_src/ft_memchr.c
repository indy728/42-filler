/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:58:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 19:49:16 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	c = (unsigned char)c;
	s1 = (unsigned char *)str;
	while (n--)
	{
		if (s1[i] == c)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
