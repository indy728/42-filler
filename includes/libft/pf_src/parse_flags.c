/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:22:20 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 20:38:08 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		check_flag(char char_x, t_mods *mods)
{
	if (char_x == '#')
		mods->flags.hash = 1;
	else if (char_x == '0')
		mods->flags.zero = 1;
	else if (char_x == '-')
		mods->flags.minus = 1;
	else if (char_x == ' ')
		mods->flags.space = 1;
	else if (char_x == '+')
		mods->flags.plus = 1;
	else
		return (0);
	return (1);
}

void			parse_flags(t_mess *mess, t_mods *mods)
{
	char	char_x;

	while ((char_x = char_at_x(mess, 0))
				&& check_flag(char_x, mods))
		++mess->x;
}
