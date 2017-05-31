/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:28:57 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/31 01:30:06 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_x(t_fill *game, t_piece *piece, t_place *place, int j)
{
	int	i;

	i = 0;
	while (i < piece->xsize)
	{
		if (PIECE[j][i] == '*' && ((XPOS + i < 0 || YPOS + j < 0)
				|| (XPOS + i > MAPXSIZE - 1 || YPOS + j > MAPYSIZE - 1)
				|| (COORDS != game->player && COORDS != '.')))
			return (0);
		++i;
	}
	return (1);
}

static void	update_piece(t_piece *piece, int x, int y, int value)
{
	piece->placex = x;
	piece->placey = y;
	piece->value = value;
}

static void	check_piece(t_fill *game, t_piece *piece, t_place *place)
{
	int i;
	int	j;
	int	value;

	j = 0;
	game->counter = 0;
	value = 0;
	while (j < piece->ysize)
	{
		i = 0;
		if (!check_x(game, piece, place, j))
			return ;
		while (i < piece->xsize)
		{
			if (PIECE[j][i] == '*' && MAP[j + YPOS][XPOS + i] == '.')
				value += place->heat_map[j + YPOS][i + XPOS];
			if (PIECE[j][i] == '*' && (COORDS == game->player))
				++game->counter;
			++i;
		}
		++j;
	}
	if (game->counter == 1 && value > piece->value)
		update_piece(piece, XPOS, YPOS, value);
}

static void	try_piece(t_fill *game, t_piece *piece, t_place *place)
{
	XPOS = 1 - piece->xsize;
	YPOS = 1 - piece->ysize;
	while (YPOS - piece->ysize < MAPYSIZE - 1)
	{
		while (XPOS - piece->xsize < MAPXSIZE - 1)
		{
			check_piece(game, piece, place);
			++XPOS;
		}
		XPOS = 0;
		++YPOS;
	}
}

/*
** USE DEBUGGER CODE BELOW "piece->value" LINE BELOW:
** print_map(game);
** print_heat_map(game, place->heat_map);
*/

void		place_piece(t_fill *game, t_piece *piece)
{
	t_place	*place;

	if (!(place = ft_memalloc(sizeof(t_place))))
		ft_exit_malloc_error();
	get_priorities(game);
	place->heat_map = build_heat_map(game);
	piece->value = -9999999;
	try_piece(game, piece, place);
	ft_printf("%d %d\n", piece->placey, piece->placex);
	clean_structs(game, piece, place);
}
