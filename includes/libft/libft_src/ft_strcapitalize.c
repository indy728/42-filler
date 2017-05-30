/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:14:25 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/27 20:26:06 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	char	*hold;

	hold = str;
	*str = ft_toupper(*str);
	while (*(++str))
		*str = ft_tolower(*str);
	return (hold);
}
