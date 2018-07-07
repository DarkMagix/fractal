/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:46:21 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 20:09:24 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_window *win)
{
	win->fract.zoom = 1.0;
	win->fract.move_x = -0.5;
	win->fract.max_iter = 32;
	win->x_off = (SCREEN_W - IMG_SIZE) / 2;
	win->y_off = (SCREEN_H - IMG_SIZE) / 2;
	win->c_re = -0.7;
	win->c_im = 0.27015;
	win->c_index = 0;
	fiery(win);
}

void	start(t_window *win, int w, int h)
{
	int x;
	int y;
	int i;

	y = 0;
	x = 0;
	while (y < h)
	{
		while (x < w)
		{
			pixel_math(win, x, y);
			i = 0;
			while (i < win->fract.max_iter)
			{
				get_math(win->c_fract, win);
				if ((win->new_re * win->new_re + win->new_im * win->new_im) > 4)
					break ;
				i++;
			}
			put_pixel_to_image(win, x, y, i);
			x++;
		}
		x = 0;
		y++;
	}
}

void	init_julia(t_window *win)
{
	win->c_fract = 'j';
	win->fract.zoom = 0.751315;
	win->fract.move_x = -0.133975;
	win->fract.move_y = 0.0;
	win->c_re = -0.7;
	win->c_im = 0.27015;
	win->lastx = 0;
	win->lasty = 0;
}

void	init_mandel(t_window *win)
{
	win->c_fract = 'm';
	win->fract.zoom = 0.909091;
	win->fract.move_x = -0.500000;
	win->fract.move_y = 0;
}

void	init_ship(t_window *win)
{
	win->c_fract = 'b';
	win->fract.zoom = 0.909091;
	win->fract.move_x = -0.408975;
	win->fract.move_y = -0.550000;
}
