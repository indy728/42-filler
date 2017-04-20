/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:48:03 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/24 19:41:20 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmove(char *dest, char **src)
{
	char	*tmp;

	if (!src || !dest)
		return (NULL);
	tmp = *src;
	*src = dest;
	ft_freezero((void *)tmp, ft_strlen(tmp));
	return (dest);
}
