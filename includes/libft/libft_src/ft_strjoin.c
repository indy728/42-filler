/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:57:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 21:07:40 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;
	size_t	len1;
	size_t	len2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(join = (char *)malloc(len1 + len2 + 1)))
		return (NULL);
	while (len1--)
	{
		join[i] = s1[i];
		i++;
	}
	while (len2--)
		join[i++] = *(s2++);
	join[i] = '\0';
	return (join);
}
