/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/19 18:55:52 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	convert_mess(t_mess *mess, va_list ap)
{
	t_mods	*mods;

	if (!(mods = (t_mods *)malloc(sizeof(t_mods))))
		exit(1);
	ft_bzero(mods, sizeof(t_mods));
	parse_flags(mess, mods);
	parse_fw(mess, mods);
	parse_precision(mess, mods);
	parse_length(mess, mods);
	parse_specifier(mess, mods);
	validate_mods(mods);
	if (!mods->error)
		print_mods(mess, mods, ap);
	ft_freezero(mods, sizeof(t_mods));
}

static void	parse_fmt(t_mess *mess, va_list ap)
{
	char	char_x;

	while ((char_x = char_at_x(mess, 0)))
	{
		if (char_x != '%')
		{
			mess->pfint += ft_putlchar(char_x);
			++mess->x;
		}
		else
		{
			++mess->x;
			convert_mess(mess, ap);
		}
	}
}

int			ft_printf(const char *fmt_str, ...)
{
	va_list	ap;
	int		printed;
	t_mess	*mess;

	if (!fmt_str)
	{
		ft_putendl_fd("ft_printf: must input valid format string", 2);
		return (0);
	}
	if (!(mess = (t_mess *)malloc(sizeof(t_mess))))
		exit(1);
	ft_bzero(mess, sizeof(t_mess));
	mess->fmt_str = fmt_str;
	va_start(ap, fmt_str);
	parse_fmt(mess, ap);
	printed = mess->pfint;
	ft_freezero(mess, sizeof(t_mess));
	va_end(ap);
	return (printed);
}
