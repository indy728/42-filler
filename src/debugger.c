/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:01:55 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/29 17:44:50 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_fill *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			fprintf(stderr, "%d", MAP[j][i]);
			++i;
		}
		fprintf(stderr, "\n");
		++j;
	}
}

void	print_heat_map(t_fill *game, int **heat_map)
{
	int	i;
	int	j;

	j = 0;
	fprintf(stderr, "player %c\n", game->player);
	while (j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			fprintf(stderr, "%3d ", heat_map[j][i]);
			++i;
		}
		fprintf(stderr, "\n");
		++j;
	}
	sleep(1);
}

void	print_piece(t_piece *piece)
{
	int i;
	int	j;

	j = 0;
	while (j < piece->ysize)
	{
		fprintf(stderr, "row %d: ", j);
		i = 0;
		while (i < piece->xsize)
		{
			fprintf(stderr, "%c ", piece->map[j][i]);
			++i;
		}
		fprintf(stderr, "\n");
		++j;
	}
}
