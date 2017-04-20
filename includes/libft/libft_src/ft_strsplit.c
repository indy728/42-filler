/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:44:29 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 23:14:42 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	wl;
	size_t	n;
	size_t	cw;
	char	**split;

	i = 0;
	n = 0;
	if (!str)
		return (NULL);
	cw = ft_count_words((char *)str, c);
	if (!(split = (char **)malloc((sizeof(*split) * (cw + 1)))))
		return (NULL);
	while (i < cw)
	{
		while (str[n] == c)
			++n;
		wl = ft_wordlen((char *)str + n, c);
		if (!(split[i] = ft_strsub(str, n, wl)))
			return (NULL);
		n = n + wl;
		++i;
	}
	split[i] = NULL;
	return (split);
}
