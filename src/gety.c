/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gety.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:54:53 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/19 01:31:36 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	gety(int x, int y, int z, t_param *params)
{
	int	g;

	g = params->grid_size;
	z *= params->height;
	y = sin(params->alpha) * sin(params->beta) * x * g +
		cos(params->alpha) * (params->starty + y * g) +
		sin(params->alpha) * cos(params->beta) * z;
	return (y);
}
