/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:43:47 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/19 18:45:28 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define GRID 30
# define HEIGHT 3
# define STARTX 500
# define STARTY 500

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	int			grid_size;
	int			startx;
	int			starty;
	int			height;
	double		alpha;
	double		beta;
	t_list		*map;
}				t_param;

typedef enum	e_keys
{
	A, S, D, F, H1, G, ZED, X, C, V, B = 11, Q, W, E, R, Y, T,
	ONE, TWO, THREE, FOUR, SIX, FIVE, PLUS, NINE, SEVEN, MINUS, EIGHT, ZERO,
	RBRACK, O, U, LBRACK, I, P, RETURN, ELL, JAY, APOS, K, SEMI,
	BACKSLASH, COMMA, SLASH, N, M, POINT, TAB, SPACE, TILDE, DEL, ESC = 53,
	LEFT = 123, RIGHT, DOWN, UP,
	LCNTRL = 256, LSHIFT, RSHIFT, LCMD, RCMD, LOPT, ROPT, RCNTRL = 269
}				t_keys;

int				getx(int x, int z, t_param *params);
int				gety(int x, int y, int z, t_param *params);
void			wf_draw_line(t_param *param, int row, int col, char axis);

#endif
