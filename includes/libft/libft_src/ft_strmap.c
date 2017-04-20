/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:04:58 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 20:43:55 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	size_t	i;
	char	*dup;

	i = 0;
	if (str && f)
	{
		if (!(dup = ft_strdup(str)))
			return (NULL);
		while (dup[i])
		{
			dup[i] = f(dup[i]);
			++i;
		}
		return (dup);
	}
	return (NULL);
}
