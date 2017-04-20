/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 00:58:31 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 02:18:17 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	hash_error(t_mess *mess, t_mods *mods)
{
	if (mods->flags.hash && OCTAL >= mods->spec && mods->spec >= HEX_UPPER)
	{
		ft_putstr_fd("ft_printf: flag '#' results in undefined "
				"behavior with specifier '", 2);
		ft_putchar_fd(char_at_x(mess, -1), 2);
		ft_putstr_fd("'", 2);
		return (1);
	}
	return (0);
}

static int	zero_error(t_mess *mess, t_mods *mods)
{
	if (mods->flags.zero)
	{
		if (mods->spec >= CHAR)
		{
			ft_putstr_fd("ft_printf: flag '0' results in undefined "
					"behavior with specifier '", 2);
			ft_putchar_fd(char_at_x(mess, -1), 2);
			ft_putstr_fd("'", 2);
			return (1);
		}
	}
	return (0);
}

static int	plus_error(t_mess *mess, t_mods *mods)
{
	if (mods->spec != SIGNED && mods->spec != PERCENT && mods->flags.space)
	{
		ft_putstr_fd("ft_printf: flag ' ' results in undefined "
				"behavior with specifier '", 2);
		ft_putchar_fd(char_at_x(mess, -1), 2);
		ft_putstr_fd("'", 2);
		return (1);
	}
	if (mods->spec != SIGNED && mods->flags.plus)
	{
		ft_putstr_fd("ft_printf: flag '+' results in undefined "
				"behavior with specifier '", 2);
		ft_putchar_fd(char_at_x(mess, -1), 2);
		ft_putstr_fd("'", 2);
		return (1);
	}
	return (0);
}

int			validate_flags(t_mess *mess, t_mods *mods)
{
	if (hash_error(mess, mods) || zero_error(mess, mods)
			|| plus_error(mess, mods))
		return (0);
	return (1);
}
