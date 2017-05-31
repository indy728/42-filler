/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 17:01:55 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/31 00:51:01 by kmurray          ###   ########.fr       */
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
			if (ft_isalpha(MAP[j][i]))
			{
				if (ft_tolower(MAP[j][i]) == game->player)
					fprintf(stderr, GREEN);
				else
					fprintf(stderr, RED);
			}
			fprintf(stderr, "%c" RESET, MAP[j][i]);
			++i;
		}
		fprintf(stderr, "\n");
		++j;
	}
	sleep(1);
}
