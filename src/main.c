/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/30 21:59:24 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_map_size(t_fill *game, char *line)
{
	int		i;

	i = 0;
	if (get_next_line(0, &line) > 0)
	{
		while (!ft_isdigit(line[i]))
			++i;
		game->mapysize = ft_atoi(line + i);
		while (line[i] != ' ')
			++i;
		game->mapxsize = ft_atoi(line + i + 1);
	}
	ft_strdel(&line);
	if (!(game->map = ft_memalloc(sizeof(char *) * game->mapysize)))
		ft_exit_malloc_error();
	ft_bzero(game->map, sizeof(char *) * game->mapysize);
}

int			main(int ac, char **av)
{
	char	*line;
	t_fill	*game;
	t_piece	*piece;

	if (!(game = ft_memalloc(sizeof(t_fill))))
		ft_exit_malloc_error();
	ft_bzero(game, sizeof(t_fill));
	if (!(piece = ft_memalloc(sizeof(t_piece))))
		ft_exit_malloc_error();
	ft_bzero(piece, sizeof(t_piece));
	if (get_next_line(0, &line) > 0)
		game->player = line[10] == '1' ? 'o' : 'x';
	ft_strdel(&line);
	get_map_size(game, line);
	while (get_next_line(0, &line) > 0)
	{
		if (parse_input(game, piece, line))
			place_piece(game, piece);
		ft_strdel(&line);
	}
	free(piece);
	free(game->map);
	free(game);
	return (0);
}
