/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:46:29 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 16:46:30 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	alt_zoom(int kc, t_window *win)
{
	if (kc == 126)
		win->fract.zoom *= 1.35;
	else if (kc == 125)
		win->fract.zoom /= 1.35;
}

int		mouse_hook(int mousecode, int x, int y, t_window *win)
{
	if (mousecode == 1)
	{
		if (win->c_index > 4)
			win->c_index = 0;
		(win->c_index == 0) ? winter(win) : 0;
		(win->c_index == 1) ? fiery(win) : 0;
		(win->c_index == 2) ? green(win) : 0;
		(win->c_index == 3) ? greyscale(win) : 0;
		(win->c_index == 3) ? rainbow(win) : 0;
		win->c_index++;
	}
	if (mousecode == 4)
		win->fract.zoom /= 1.25;
	else if (mousecode == 5)
		win->fract.zoom *= 1.25;
	start(win, IMG_SIZE, IMG_SIZE);
	mlx_put_image_to_window(win->mlx, win->win,
		win->img, win->x_off, win->y_off);
	return (x + y);
}

int		key_hook(int kc, t_window *win)
{
	double zm;

	zm = 0.35;
	if (kc == 53)
		exit(1);
	else if (kc == 38)
		init_julia(win);
	else if (kc == 46)
		init_mandel(win);
	else if (kc == 11)
		init_ship(win);
	else if (kc == 0)
		win->fract.move_x -= 1 / (win->fract.zoom / zm);
	else if (kc == 2)
		win->fract.move_x += 1 / (win->fract.zoom / zm);
	else if (kc == 13)
		win->fract.move_y -= 1 / (win->fract.zoom / zm);
	else if (kc == 1)
		win->fract.move_y += 1 / (win->fract.zoom / zm);
	alt_zoom(kc, win);
	reset_fractal(win, kc);
	start(win, IMG_SIZE, IMG_SIZE);
	mlx_put_image_to_window(win->mlx, win->win,
		win->img, win->x_off, win->y_off);
	return (0);
}

int		mouse_move(int x, int y, t_window *win)
{
	if (x >= win->x_off & x <= win->x_off + (IMG_SIZE)
		&& y >= win->y_off && y <= win->y_off + (IMG_SIZE))
	{
		if (win->lastx == 0 && win->lasty == 0)
		{
			win->lastx = win->x_off * 2;
			win->lasty = win->y_off * 2;
		}
		else
		{
			win->c_im += (win->lasty - y) * 0.0025;
			win->c_re += (win->lastx - x) * 0.0025;
			win->lastx = x;
			win->lasty = y;
			start(win, IMG_SIZE, IMG_SIZE);
			mlx_put_image_to_window(win->mlx, win->win,
				win->img, win->x_off, win->y_off);
		}
	}
	return (0);
}

void	reset_fractal(t_window *win, int kc)
{
	if (kc == 15)
	{
		if (win->c_fract == 'j')
			init_julia(win);
		else if (win->c_fract == 'b')
			init_ship(win);
		else if (win->c_fract == 'm')
			init_mandel(win);
	}
}
