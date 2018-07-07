/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:46:04 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 16:46:05 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_math(t_window *win, int x, int y)
{
	win->pr = 1.5 * (x - IMG_SIZE / 2) /
		(0.5 * win->fract.zoom * IMG_SIZE) + win->fract.move_x;
	win->pi = (y - IMG_SIZE / 2) /
		(0.5 * win->fract.zoom * IMG_SIZE) + win->fract.move_y;
	if (win->c_fract != 'j')
	{
		win->new_re = 0;
		win->new_im = 0;
		win->old_re = 0;
		win->old_im = 0;
	}
	else
	{
		win->new_re = 1.5 * (x - IMG_SIZE / 2) /
			(0.5 * win->fract.zoom * IMG_SIZE) + win->fract.move_x;
		win->new_im = (y - IMG_SIZE / 2) /
			(0.5 * win->fract.zoom * IMG_SIZE) + win->fract.move_y;
	}
}

void	put_pixel_to_image(t_window *win, int x, int y, int i)
{
	if (i < win->fract.max_iter)
		*((unsigned*)win->addr + (x + y * IMG_SIZE)) =
			win->color_map[(i % 8)];
	else
		*((unsigned*)win->addr + (x + y * IMG_SIZE)) = 0x000000;
}

void	get_vitals(t_window *win)
{
	printf("\nZoom: %f\n", win->fract.zoom);
	printf("MoveX, MoveY(%f, %f)\n", win->fract.move_x, win->fract.move_y);
}

int		validate_fractal(char *c, t_window *win)
{
	if (ft_strlen(c) > 1)
	{
		ft_putendl("Proper Usage: /fractol [fractol] (j, b, m)");
		return (0);
	}
	if (*c == 'j')
	{
		init_julia(win);
		return (1);
	}
	else if (*c == 'm')
	{
		init_mandel(win);
		return (1);
	}
	else if (*c == 'b')
	{
		init_ship(win);
		return (1);
	}
	else
	{
		ft_putendl("Proper Usage: /fractol [fractol] (j, b, m)");
		return (0);
	}
}

int		controls_on_screen(t_window *win)
{
	t_point size;
	t_point location;

	location.x = 0;
	location.y = 0;
	size.x = 120;
	size.y = 200;
	clear(win, size, location);
	mlx_string_put(win->mlx, win->win, 0,
		0, 0xFFFFFF, "WASD to Move Fractal");
	mlx_string_put(win->mlx, win->win, 0,
		20, 0xFFFFFF, "Mouse Wheel Up/Down to Zoom");
	mlx_string_put(win->mlx, win->win, 0,
		40, 0xFFFFFF, "LMB To Cycle Colors");
	mlx_string_put(win->mlx, win->win, 0,
		60, 0xFFFFFF, "R To Reset Fractal");
	mlx_string_put(win->mlx, win->win, 0,
		80, 0xFFFFFF, "J for Julia");
	mlx_string_put(win->mlx, win->win, 0,
		100, 0xFFFFFF, "B for Burning Ship");
	mlx_string_put(win->mlx, win->win, 0,
		120, 0xFFFFFF, "M for Mandelbrot");
	return (0);
}
