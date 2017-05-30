/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:43:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/29 19:04:18 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define COORDS ft_tolower(game->map[y + j][x + i])
# define MAP game->map
# define MAPXSIZE game->mapxsize
# define MAPYSIZE game->mapysize
# define HMULT 5
# define VMULT 1
# define CHOKE 100

typedef struct		s_fill
{
	char			player;
	int			 	mapxsize;
	int			 	mapysize;
	char			**map;
	int				counter;
	int				down;
	int				right;
}					t_fill;

typedef struct		s_piece
{
	int				ctr;
	int				ysize;
	int				xsize;
	int				placex;
	int				placey;
	int				value;
	char		 	**map;
}					t_piece;

int					parse_input(t_fill *game, t_piece *piece, char *line);
void				place_piece(t_fill *game, t_piece *piece);
int					**build_heat_map(t_fill *game);

/*
**	debugging code
*/

void				print_piece(t_piece *piece);
void				print_heat_map(t_fill *game, int **heat_map);
void				print_map(t_fill *game);

#endif
