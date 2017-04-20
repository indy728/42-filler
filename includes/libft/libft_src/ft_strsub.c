/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:07:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 22:55:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t size)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!str || start + size > ft_strlen(str) || !(sub = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		sub[i] = *(str + start + i);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
