/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:16:12 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 20:56:36 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
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
			dup[i] = f(i, dup[i]);
			++i;
		}
		return (dup);
	}
	return (NULL);
}
