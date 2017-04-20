/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:11:39 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 22:35:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *str)
{
	size_t	i;
	size_t	ws;
	char	*trim;

	i = 0;
	if (!str)
		return (NULL);
	ws = ft_endspaces((char *)str);
	while (ft_iswhitespace(str[i]))
		++i;
	if (!(trim = ft_strsub(str, i, ft_strlen(str) - ws)))
		return (NULL);
	return (trim);
}
