/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:53:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/04/19 02:43:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_to_screen(t_param *params)
{
	int i;
	int row = 0;
	t_list	*scout;

	scout = params->map;
	while (scout->next)
	{
		i = 0;
		while (i + 1 < scout->content_size / sizeof(int))
		{
			wf_draw_line(params, row, i, 'x');
			wf_draw_line(params, row, i, 'y');
			++i;
		}
		wf_draw_line(params, row, i, 'y');
		scout = scout->next;
		++row;
	}
	i = 0;
	while (i + 1 < scout->content_size / sizeof(int))
	{
		wf_draw_line(params, row, i, 'x');
		++i;
	}
}

int	my_key_funct(int keycode, t_param *params)
{
	void	*tmp;
	
	if (keycode == C)
	{
		ft_putstr("clearing window\n");
		mlx_clear_window(params->mlx, params->win);
	}
	if (keycode == LEFT)
	{
		params->beta += .02;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == RIGHT)
	{
		params->beta -= .02;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == UP)
	{
		params->alpha += .02;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == DOWN)
	{
		params->alpha -= .02;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == PLUS)
	{
		params->height += 1;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == MINUS)
	{
		params->height -= 1;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == RBRACK)
	{
		params->grid_size += 1;
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == LBRACK)
	{
		params->grid_size = ft_max(0, params->grid_size - 1);
		mlx_clear_window(params->mlx, params->win);
		put_to_screen(params);
	}
	if (keycode == D)
	{
		ft_putstr("destroying window\n");
		mlx_destroy_window(params->mlx, params->win);

	}
	if (keycode == ESC)
	{
		ft_putstr("GET ME THE FUCK OUTTA HERE!\n");
		mlx_destroy_window(params->mlx, params->win);
		ft_lstdel(&params->map, ft_freezero);
		free (params);
		exit (0);
	}
	return (1);
}

int	*make_array(char **split, int size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = ft_memalloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = ft_atoi(split[i]);
		++i;
	}
	return (arr);
}

void	put_sqr(void *mlx, void *win, int x, int y, int color)
{
	int i = 0;
	int j;
	int size = 2;

	while (i < size)
	{
		j = 0;
		while (j < size)
			mlx_pixel_put(mlx, win, (x - size / 2) + j++, (y - size / 2) + i, color);
		++i;
	}
}

void	print_list(t_list *begin_list)
{
	t_list	*scout;
	int		*arr;
	int 	count;

	scout = begin_list;
	while (scout->next)
	{
		arr = (int *)scout->content;
		count = 0;
		while (count < scout->content_size / sizeof(int))
		{
			ft_printf("% 3d", arr[count++]);
	//		ft_putnbr(arr[count++]);
		}
		ft_printf("\n");
		scout = scout->next;
	}
	count = 0;
	while (count < scout->content_size / sizeof(int))
		ft_printf("% 3d", arr[count++]);
	ft_putendl("");
	//	ft_putnbr(arr[count++]);
}

void	print_iso2d(t_param *params)
{
	int x;
	int y;
	int i = 0;
	int *arr;
	int *arr2;
	int	x_inc = params->grid_size;
	int	y_inc = params->grid_size;
	int n = 0;
	int z;
	void *mlx = params->mlx;
	void *win = params->win;
	double alpha = 2;
	double beta = .785;
	t_list	*scout;
	t_list	*next;
	unsigned int	r = 0xFF0000;
	unsigned int	g = 0x00FF00;
	unsigned int	b = 0x0000FF;
	unsigned int color = r + g + b;

	scout = params->map;
	while (scout->next)
	{
		arr = scout->content;
		i = 0;
		next = scout->next;
		arr2 = next->content;
		while (i < scout->content_size / sizeof(int))
		{
			z = arr[i] * params->grid_size / params->height;;
			x = cos(beta) * (500 + i * x_inc) - sin(beta) * z;
			y = sin(alpha) * sin(beta) * (500 + i * x_inc) + cos(alpha) * (500 + n * y_inc) + cos(alpha) * cos(beta) * z;
			//wf_draw_line(mlx, win, x, y - arr[i], x - x_inc, y + y_inc);
			put_sqr(mlx, win, x, y, color - arr[i] * (0x0100 * 15 + 0x010000 * 15));
/*			wf_draw_line(mlx, win, x, y, cos(beta) * (500 + i * x_inc) - sin(beta) * arr[i] * GRID / 2,
					sin(alpha) * sin(beta) * (500 + i * x_inc) + cos(alpha) * (500 + (n + 1) * y_inc) +
					sin(alpha) * cos(beta) * arr2[i] * GRID / 2);
			if (++i < scout->content_size / sizeof(int))
			{
				wf_draw_line(mlx, win, x, y, cos(beta) * (500 + i * x_inc) - sin(beta) * arr[i] * GRID / 2,
						sin(alpha) * sin(beta) * (500 + i * x_inc) + cos(alpha) * (500 + n * y_inc) +
						sin(alpha) * cos(beta) * arr[i] * GRID / 2);
			}
*/			++i;
		}
		scout = next;
		++n;
	}
	arr = scout->content;
	i = 0;
	while (i < scout->content_size / sizeof(int))
	{
		z = arr[i] * params->grid_size / params->height;
		x = cos(beta) * (500 + i * x_inc) - sin(beta) * z;
		y = sin(alpha) * sin(beta) * (500 + i * x_inc) + cos(alpha) * (500 + n * y_inc) + cos(alpha) * cos(beta) * z;
		//put_sqr(mlx, win, x, y - arr[i], color - arr[i] * (0x0100 * 10 + 0x010000 * 10));
		put_sqr(mlx, win, x, y, color - arr[i] * (0x0100 * 15 + 0x010000 * 15));
/*		if (++i < scout->content_size / sizeof(int))	
			wf_draw_line(mlx, win, x, y, cos(beta) * (500 + i * x_inc) - sin(beta) * arr[i] * GRID / 2,
					sin(alpha) * sin(beta) * (500 + i * x_inc) + cos(alpha) * (500 + n * y_inc) +
					sin(alpha) * cos(beta) * arr[i] * GRID / 2);
*/		++i;
	}
}

void	put_list(t_list *begin_list, void *mlx, void *win, int color)
{
	t_list	*scout;
	int		*arr;
	int 	count;
	int		x;
	int		y;
	int		line;

	scout = begin_list;
	y = 50;
	while (scout->next)
	{
		arr = (int *)scout->content;
		x = 50;
		count = 0;
		while (count < scout->content_size / sizeof(int))
		{
			if (arr[count++] == 0)
				put_sqr(mlx, win, x, y, 0x00FFFFFF);
			else
				put_sqr(mlx, win, x, y, color);
			line = 0;
			while (line++ < 49)
				mlx_pixel_put(mlx, win, x, y + line, 0x00FFFFFF);
			line = 0;
			if (count < scout->content_size / sizeof(int))
			{
				while (line++ < 49)
					mlx_pixel_put(mlx, win, x + line, y, 0x00FFFFFF);
			}
			x += 50;
		}
		ft_printf("\n");
		y += 50;
		scout = scout->next;
	}
	count = 0;
	x = 50;
	while (count < scout->content_size / sizeof(int))
	{
		if (arr[count++] == 0)
			put_sqr(mlx, win, x, y, 0x00FFFFFF);
		else
			put_sqr(mlx, win, x, y, color);
		line = 0;
		if (count < scout->content_size / sizeof(int))
		{
			while (line++ < 49)
				mlx_pixel_put(mlx, win, x + line, y, 0x00FFFFFF);
		}
		x += 50;
	}
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int		pulse;
	t_param	*params;
	int color = 0x000000FF;
	
	if (ac > 1)
	{
		int		gnl;
		char	*line;
		int		fd;
		char	**split;
		int		i;
		int		*arr;
		t_list	*begin_list;

		line = ft_strnew(1);
		begin_list = NULL;
		fd = open(av[1], O_RDONLY);
		while ((gnl = get_next_line(fd, &line)) > 0)
		{
			i = 0;
			split = ft_strsplit(line, ' ');
			while (split[i])
				++i;
			arr = make_array(split, i);
			ft_lstadd_back(&begin_list, ft_lstnew(arr, sizeof(int) * i));
			free(split);
			free(arr);
		}
		print_list(begin_list);
		close(fd);
		ft_freezero(line, ft_strlen(line));
		mlx = mlx_init();
		win = mlx_new_window(mlx, 1500, 1500, av[1]);
		//put_list(begin_list, mlx, win, color);
		params = (t_param *)malloc(sizeof(t_param));
		params->mlx = mlx;
		params->win = win;
		params->grid_size = GRID;
		params->height = HEIGHT;
		params->startx = STARTX;
		params->starty = STARTY;
		params->alpha = 0;
		params->beta = 0;
		params->map = begin_list;
		//print_iso2d(params);
		put_to_screen(params);
		while(mlx_key_hook(win, my_key_funct, params))
			mlx_loop(mlx);
	}
	return (0);
}
