/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:43:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/05/31 01:33:30 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define COORDS ft_tolower(game->map[YPOS + j][XPOS + i])
# define MAP game->map
# define PIECE piece->map
# define XPOS place->xpos
# define YPOS place->ypos
# define MAPXSIZE game->mapxsize
# define MAPYSIZE game->mapysize
# define HMULT 20
# define VMULT 10
# define CHOKE 10
# define SPREAD 5
# define DIAG 1

# define BLACK "\x1b[30m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"
# define BBLACK "\x1b[40m"
# define BRED "\x1b[41m"
# define BGREEN "\x1b[42m"
# define BYELLOW "\x1b[43m"
# define BBLUE "\x1b[44m"
# define BMAGENTA "\x1b[45m"
# define BCYAN "\x1b[46m"
# define BWHITE "\x1b[47m"
# define RESET "\x1b[0m"

typedef struct		s_fill
{
	char			player;
	int				mapxsize;
	int				mapysize;
	int				counter;
	int				down;
	int				right;
	char			**map;
}					t_fill;

typedef struct		s_piece
{
	int				ctr;
	int				ysize;
	int				xsize;
	int				placex;
	int				placey;
	int				value;
	char			**map;
}					t_piece;

typedef struct		s_place
{
	int				xpos;
	int				ypos;
	int				**heat_map;
}					t_place;

int					parse_input(t_fill *game, t_piece *piece, char *line);
void				place_piece(t_fill *game, t_piece *piece);
int					**build_heat_map(t_fill *game);
void				get_priorities(t_fill *game);
void				clean_structs(t_fill *game, t_piece *piece, t_place *place);
void				choke(t_fill *game, int **heat_map);

/*
**	debugging code
*/

void				print_heat_map(t_fill *game, int **heat_map);
void				print_map(t_fill *game);

#endif
