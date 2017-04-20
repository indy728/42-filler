/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:06:13 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/06 15:42:48 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *str)
{
	unsigned char		*dup;
	unsigned const char	*str1;
	size_t				i;

	i = 0;
	if (!str)
		return (NULL);
	str1 = str;
	dup = (unsigned char *)malloc(sizeof(*dup) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	while (i < ft_strlen(str))
	{
		dup[i] = str1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
