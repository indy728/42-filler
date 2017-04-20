/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:36:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/24 02:26:53 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef	struct		s_mess
{
	char const		*fmt_str;
	unsigned int	x;
	unsigned int	pfint;
}					t_mess;

typedef struct		s_flags
{
	char			hash;
	char			zero;
	char			minus;
	char			space;
	char			plus;
}					t_flags;

typedef enum		e_spec
{
	ZILCH, SIGNED, UNSIGNED, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING,
	POINTER, PERCENT, INVALID
}					t_spec;

typedef enum		e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}					t_length;

typedef	struct		s_mods
{
	t_flags			flags;
	unsigned int	fwidth;
	unsigned int	prec;
	t_length		length;
	t_spec			spec;
	char			dot;
	char			error;
}					t_mods;

int					ft_printf(const char *fmt_str, ...);
char				char_at_x(t_mess *mess, int n);
void				parse_flags(t_mess *mess, t_mods *mods);
void				parse_fw(t_mess *mess, t_mods *mods);
void				parse_precision(t_mess *mess, t_mods *mods);
void				parse_length(t_mess *mess, t_mods *mods);
void				parse_specifier(t_mess *mess, t_mods *mods);
void				validate_mods(t_mods *mods);
int					validate_flags(t_mess *mess, t_mods *mods);
void				print_mods(t_mess *mess, t_mods *mods, va_list ap);
char				*make_decimalstr(t_mods *mods, va_list ap);
char				*make_stringstr(t_mods *mods, va_list ap);
char				*make_pointerstr(t_mods *mods, va_list ap);
char				*make_octalstr(t_mods *mods, va_list ap);
char				*make_hexstr(t_mods *mods, va_list ap);
uintmax_t			get_udecimal(t_length length, va_list ap);
void				add_precision(t_mods *mods, char **str);
void				add_padding(t_mods *mods, char **str);

#endif
