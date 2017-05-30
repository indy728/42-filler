/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:06:26 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/29 19:20:00 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void cut_off(t_fill *game, int **heat_map)
{
	int	i;
	int j;

	j = 0;
	while (j < game->mapysize)
	{
		i = 0;
		while (i < game->mapxsize)
		{
			if (MAP[j][i] == '.')
				heat_map[j][i] = game->right * HMULT * i + game->down * VMULT * j;
			++i;
		}
		++j;
	}
}

static void	choke(t_fill *game, int **heat_map)
{
	int	i;
	int j;

	j = 0;
	while (j < game->mapysize)
	{
		i = 0;
		while (i < game->mapxsize)
		{
			if (ft_isalpha(MAP[j][i]) && ft_tolower(MAP[j][i]) != game->player)
			{
				if ((i - 1) > 0 && (i - 2) > 0 && MAP[j][i - 1] == '.' && MAP[j][i - 2] == '.')
					heat_map[j][i - 2] += CHOKE;
				if ((i + 1) < MAPXSIZE && (i + 2) < MAPXSIZE && MAP[j][i + 1] == '.' && MAP[j][i + 2] == '.')
					heat_map[j][i + 2] += CHOKE;
				if ((j - 1) > 0 && (j - 2) > 0 && MAP[j - 1][i] == '.' && MAP[j - 2][i] == '.')
					heat_map[j - 2][i] += CHOKE;
				if ((j + 1) < MAPYSIZE && (j + 2) < MAPYSIZE && MAP[j + 1][i] == '.' && MAP[j + 2][i] == '.')
					heat_map[j + 2][i] += CHOKE;
				if ((i - 1) > 0 && (j - 2) > 0 && MAP[j - 1][i - 1] == '.' && MAP[j - 2][i - 1] == '.')
					heat_map[j - 2][i - 1] += CHOKE;
				if ((i + 1) < MAPXSIZE && (j + 2) < MAPYSIZE && MAP[j + 1][i + 1] == '.' && MAP[j + 2][i + 1] == '.')
					heat_map[j + 2][i + 1] += CHOKE;
				if ((j - 1) > 0 && (i + 2) < MAPXSIZE && MAP[j - 1][i + 1] == '.' && MAP[j - 1][i + 2] == '.')
					heat_map[j - 1][i + 2] += CHOKE;
				if ((j + 1) < MAPYSIZE && (i + 2) < MAPXSIZE && MAP[j + 1][i + 1] == '.' && MAP[j + 1][i + 2] == '.')
					heat_map[j + 1][i + 2] += CHOKE;
		}
			++i;
		}
		++j;
	}
}

static void	fill_map(t_fill *game, int **heat_map)
{
	cut_off(game, heat_map);
	choke(game, heat_map);
}

int		**build_heat_map(t_fill *game)
{
	int		i;
	int		**heat_map;

	if (!(heat_map = ft_memalloc(sizeof(int *) * game->mapysize)))
		ft_exit_malloc_error();
	i = 0;
	while (i < game->mapysize)
	{
		if (!(heat_map[i] = ft_memalloc(sizeof(int) * game->mapxsize)))
			ft_exit_malloc_error();
		ft_bzero(heat_map[i], game->mapxsize);
		++i;
	}
	fill_map(game, heat_map);
	return (heat_map);
}
