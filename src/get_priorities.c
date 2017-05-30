/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_priorities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 22:12:17 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/29 23:00:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_sides(t_fill *game)
{
	int		j;
	char	r;
	char	l;

	j = 0;
	r = 0;
	l = 0;
	while (j < MAPYSIZE)
	{
		if (ft_tolower(MAP[j][MAPXSIZE - 1]) == game->player)
			r = 1;
		if (ft_tolower(MAP[j][0]) == game->player)
			l = 1;
		++j;
	}
	if (r && l)
		game->right = 0;
	if (game->right > 0 && r)
		game->right = -2;
	if (game->right < 0 && l)
		game->right = 2;
}

static void	check_ends(t_fill *game)
{
	int		i;
	char	t;
	char	b;

	i = 0;
	t = 0;
	b = 0;
	while (i < MAPXSIZE)
	{
		if (ft_tolower(MAP[0][i]) == game->player)
			t = 1;
		if (ft_tolower(MAP[MAPYSIZE - 1][i]) == game->player)
			b = 1;
		++i;
	}
	if (t && b)
		game->down = 0;
	if (game->down > 0 && b)
		game->down = -2;
	if (game->down < 0 && t)
		game->down = 2;
}

static void	get_start(t_fill *game)
{
	int i;
	int j;

	j = 0;
	while (j < MAPYSIZE)
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

void		get_priorities(t_fill *game)
{
	static int	q;

	if (!q++)
		get_start(game);
	if (game->right)
		check_sides(game);
	if (game->down)
		check_ends(game);
}
