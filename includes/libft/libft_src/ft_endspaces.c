/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endspaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:14:27 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 22:22:20 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_endspaces(char *str)
{
	size_t i;
	size_t ws;

	i = 0;
	while (ft_iswhitespace(str[i]))
		++i;
	ws = i;
	i = ft_strlen(str) - 1;
	if (ws <= i)
	{
		while (ft_iswhitespace(str[i--]))
			++ws;
	}
	return (ws);
}
