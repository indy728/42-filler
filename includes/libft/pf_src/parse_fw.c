/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 20:54:43 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/21 20:40:51 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_fw(t_mess *mess, t_mods *mods)
{
	int	fw;

	if ((fw = ft_atoi(mess->fmt_str + mess->x)))
		mods->fwidth = fw;
	while (ft_isdigit(char_at_x(mess, 0)))
		++mess->x;
}
