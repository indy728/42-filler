/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 18:08:07 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/29 19:22:41 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	make_map(t_fill *game, char *line)
{
	game->map[game->counter] = ft_strdup(line + 4);
	++game->counter;
}

static void	get_piece_size(t_piece *piece, char *line)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]))
		++i;
	piece->ysize = ft_atoi(line + i);
	while (line[i] != ' ')
		++i;
	piece->xsize = ft_atoi(line + i + 1);
	if(!(piece->map = ft_memalloc(sizeof(char *) * piece->ysize)))
		ft_exit_malloc_error();
}

static void	get_piece(t_piece *piece, char *line)
{
	piece->map[piece->ctr] = ft_strdup(line);
	++piece->ctr;
}

int			parse_input(t_fill *game, t_piece *piece, char *line)
{
	//ft_putstr_color_fd(line, 1, 2);
	if (ft_isdigit(line[0]))
		make_map(game, line);
	else if (!ft_strncmp("Piece", line, 5))
		get_piece_size(piece, line);
	else if (line[0] == '.' || line[0] == '*')
		get_piece(piece, line);
	if (piece->ysize && piece->ctr == piece->ysize)
		return (1);
	return (0);
}
