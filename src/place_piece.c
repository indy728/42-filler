/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:28:57 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/30 01:06:52 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	delete_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->ysize)
		ft_strdel(&piece->map[i++]);
	free(piece->map);
	ft_bzero(piece, sizeof(t_piece));
}

static void	delete_maps(t_fill *game)
{
	int i;

	i = 0;
	while (i < MAPYSIZE)
		ft_strdel(&game->map[i++]);
	free(game->map);
	if (!(game->map = ft_memalloc(sizeof(char *) * MAPYSIZE)))
		ft_exit_malloc_error();
	ft_bzero(game->map, sizeof(char *) * MAPYSIZE);
	game->counter = 0;
	
}

static int	check_piece(t_fill *game, t_piece *piece, int x, int y, int **heat_map)
{
	int	i;
	int	j;
	int	counter;
	int	value;

	j = 0;
	counter = 0;
	value = 0;
	while (j < piece->ysize)
	{
		i = 0;
		while (i < piece->xsize)
		{
			if (piece->map[j][i] == '*' && (x + i < 0 || y + j < 0))
				return (0);
			if (piece->map[j][i] == '*' && (x + i > MAPXSIZE - 1 || y + j > MAPYSIZE - 1))
				return (0);
			if (piece->map[j][i] == '*' && COORDS != game->player && COORDS != '.')
				return (0);
			if (piece->map[j][i] == '*' && MAP[j + y][x + i] == '.')
				value += heat_map[j + y][i + x];
			if (piece->map[j][i] == '*' && (COORDS == game->player))
				++counter;
			++i;
		}
		++j;
	}
	if (counter != 1)
		return (0);
	if (value > piece->value)
	{
		piece->placex = x;
		piece->placey = y;
		piece->value = value;
	}
	return (1);
}

static void	try_piece(t_fill *game, t_piece *piece, int **heat_map)
{
	int	x;
	int	y;

	x = 1 - piece->xsize;
	y = 1 - piece->ysize;
	while (y - piece->ysize < MAPYSIZE - 1)
	{
		while (x - piece->xsize < MAPXSIZE - 1)
		{
			check_piece(game, piece, x, y, heat_map);
			++x;
		}
		x = 0;
		++y;
	}
}

void		place_piece(t_fill *game, t_piece *piece)
{
	int **heat_map;

	get_priorities(game);
	heat_map = build_heat_map(game);
	piece->value = -9999999;
//	print_heat_map(game, heat_map);
	try_piece(game, piece, heat_map);
	ft_printf("%d %d\n", piece->placey, piece->placex);
	delete_piece(piece);
	delete_maps(game);
	free(heat_map);
}
