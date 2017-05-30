/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize_each.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:14:25 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/03 18:42:48 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize_each(char *str)
{
	char	*hold;

	hold = str;
	*str = ft_toupper(*str);
	while (*(++str))
	{
		if (*(str - 1) == ' ' || *(str - 1) == '\t' || *(str - 1) == '-')
			*str = ft_toupper(*str);
		else
			*str = ft_tolower(*str);
	}
	return (hold);
}
