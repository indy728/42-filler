/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_udecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:36:42 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/20 19:28:50 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

uintmax_t	get_udecimal(t_length length, va_list ap)
{
	uintmax_t	udecimal;

	if (length == L)
		udecimal = va_arg(ap, unsigned long);
	else if (length == LL)
		udecimal = va_arg(ap, unsigned long long);
	else if (length == J)
		udecimal = va_arg(ap, uintmax_t);
	else if (length == Z)
		udecimal = va_arg(ap, size_t);
	else
		udecimal = va_arg(ap, unsigned int);
	if (length == HH)
		udecimal = (unsigned char)udecimal;
	else if (length == H)
		udecimal = (unsigned short)udecimal;
	else if (!length)
		udecimal = (unsigned int)udecimal;
	return (udecimal);
}
