/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heat_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 00:48:52 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/31 01:28:56 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_heat(t_fill *game, int **heat_map, int a, int b)
{
	int	i;
	int	j;
	int	min;
	int	max;

	j = 0;
	min = 0;
	max = 0;
	while (j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			min = ft_min(min, heat_map[j][i]);
			max = ft_max(max, heat_map[j][i]);
			++i;
		}
		++j;
	}
	if (heat_map[b][a] < min + ((max - min) / 12))
		return (0);
	if (heat_map[b][a] < min + 4 * ((max - min) / 10))
		return (1);
	return (2);
}

static void	output(t_fill *game, int **heat_map, int i, int j)
{
	int h;

	h = 0;
	if (ft_isalpha(MAP[j][i]))
	{
		if (ft_tolower(MAP[j][i]) == game->player)
			fprintf(stderr, "%s%s++", BLACK, BWHITE);
		else
			fprintf(stderr, "%s%s--", WHITE, BBLACK);
	}
	else
	{
		h = get_heat(game, heat_map, i, j);
		if (h == 2)
			fprintf(stderr, "%s%s", RED, BRED);
		else if (h == 1)
			fprintf(stderr, "%s%s", YELLOW, BYELLOW);
		else
			fprintf(stderr, "%s%s", GREEN, BGREEN);
		fprintf(stderr, "  ");
	}
	fprintf(stderr, RESET);
}

void		print_heat_map(t_fill *game, int **heat_map)
{
	int	i;
	int	j;

	j = 0;
	while (j < MAPYSIZE)
	{
		i = 0;
		while (i < MAPXSIZE)
		{
			output(game, heat_map, i, j);
			++i;
		}
		fprintf(stderr, "\n");
		++j;
	}
	fprintf(stderr, "\n\n");
	sleep(1);
}
