/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choke.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 22:48:59 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/31 00:37:07 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	helpera(t_fill *game, int **heat_map, int i, int j)
{
	int	n;

	n = 1;
	while (n < SPREAD && (i - n) >= 0 && MAP[j][i - n] == '.')
	{
		heat_map[j][i - n] += ((SPREAD - n)) * CHOKE;
		if (j - n >= 0 && MAP[j - n][i - n] == '.')
			heat_map[j - n][i - n] += ((SPREAD - n) * CHOKE / DIAG);
		++n;
	}
	n = 1;
	while (n < SPREAD && j - n >= 0 && MAP[j - n][i] == '.')
	{
		heat_map[j - n][i] += ((SPREAD - n)) * CHOKE;
		if (i + n < MAPXSIZE && MAP[j - n][i + n] == '.')
			heat_map[j - n][i + n] += ((SPREAD - n) * CHOKE / DIAG);
		++n;
	}
}

static void	helperb(t_fill *game, int **heat_map, int i, int j)
{
	int	n;

	n = 1;
	while (n < SPREAD && i + n < MAPXSIZE && MAP[j][i + n] == '.')
	{
		heat_map[j][i + n] += ((SPREAD - n)) * CHOKE;
		if (j + n < MAPYSIZE && MAP[j + n][i + n] == '.')
			heat_map[j + n][i + n] += ((SPREAD - n) * CHOKE / DIAG);
		++n;
	}
	n = 1;
	while (n < SPREAD && (j + n) < MAPYSIZE && MAP[j + n][i] == '.')
	{
		heat_map[j + n][i] += ((SPREAD - n)) * CHOKE;
		if (i - n >= 0 && MAP[j + n][i - n] == '.')
			heat_map[j + n][i - n] += ((SPREAD - n) * CHOKE / DIAG);
		++n;
	}
}

void		choke(t_fill *game, int **heat_map)
{
	int	i;
	int j;

	j = 0;
	while (j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			if (ft_isalpha(MAP[j][i]) && ft_tolower(MAP[j][i]) != game->player)
			{
				helpera(game, heat_map, i, j);
				helperb(game, heat_map, i, j);
			}
			++i;
		}
		++j;
	}
}
