/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 22:06:26 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/30 23:41:49 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	cut_off(t_fill *game, int **heat_map)
{
	int	i;
	int j;

	j = 0;
	while (j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			if (MAP[j][i] == '.')
				heat_map[j][i] = game->right * HMULT * i
					+ game->down * VMULT * j;
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

int			**build_heat_map(t_fill *game)
{
	int		i;
	int		**heat_map;

	if (!(heat_map = ft_memalloc(sizeof(int *) * MAPYSIZE)))
		ft_exit_malloc_error();
	i = 0;
	while (i < MAPYSIZE)
	{
		if (!(heat_map[i] = ft_memalloc(sizeof(int) * MAPXSIZE)))
			ft_exit_malloc_error();
		ft_bzero(heat_map[i], MAPXSIZE);
		++i;
	}
	fill_map(game, heat_map);
	return (heat_map);
}
