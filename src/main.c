/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/29 19:59:06 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define CRED "\x1B[31m"
#define CGRN "\x1B[32m"
#define CYEL "\x1B[33m"
#define RESET "\033[0m"

void	ft_putstr_color_fd(char *str, int color, int fd)
{
	char *colors[] =
	{RESET, CRED, CGRN, CYEL};

	ft_putstr_fd(colors[color], fd);
	ft_putendl_fd(str, fd);
	ft_putstr_fd(RESET, fd);
}

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
	if (!(game->map = ft_memalloc(sizeof(char *) * game->mapysize)))
	   ft_exit_malloc_error();
	ft_bzero(game->map, sizeof(char *) * game->mapysize);
}

static void	get_priorities(t_fill *game)
{
	int i;
	int j;

	j = 0;
	while(j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			if (ft_tolower(MAP[j][i]) == game->player)
				break ;
			++i;
		}
		if (i < MAPXSIZE)
			break ;
		++j;
	}
	game->right = i < MAPXSIZE / 2 ? 1 : -1;
	game->down = j < MAPYSIZE / 2 ? 1 : -1;
}

int main(int ac, char **av)
{
	char	*line;
	t_fill	*game;
	t_piece	*piece;
	static int	q;

	q = 0;
	line = ft_strnew(1);
	if (!(game = ft_memalloc(sizeof(t_fill))))
		ft_exit_malloc_error();
	ft_bzero(game, sizeof(t_fill));
	if (!(piece = ft_memalloc(sizeof(t_piece))))
		ft_exit_malloc_error();
	ft_bzero(piece, sizeof(t_piece));
	if (get_next_line(0, &line) > 0)
		game->player = ft_atoi(line + ft_strlen("$$$ exec p")) == 1 ? 'o' : 'x';
	get_map_size(game, line);
	while (get_next_line(0, &line) > 0)
	{
		if(parse_input(game, piece, line))
		{
			if (!q++)
				get_priorities(game);
			place_piece(game, piece);
		}
	}
	free(line);
	return (0);
}
