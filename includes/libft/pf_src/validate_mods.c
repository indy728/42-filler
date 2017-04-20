/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 00:38:34 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 20:39:44 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		validate_mods(t_mods *mods)
{
	if ((mods->flags.space || mods->flags.plus) && (mods->spec == UNSIGNED))
		mods->error = 1;
	if (mods->spec == INVALID)
		mods->error = 1;
}
