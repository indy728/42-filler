/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_color_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 19:23:15 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/28 19:25:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CRED "\x1B[31m"
#define CGRN "\x1B[32m"
#define CYEL "\x1B[33m"
#define RESET "\033[0m"

void	ft_putstr_color_fd(char *str, int color, int fd)
{
	char *colors[] =
	{RESET, CRED, CGRN, CYEL};

	ft_putstr_fd(colors[color], fd);
	ft_putendl_fd(str, fd);
	ft_putstr_fd(RESET, fd);
}
