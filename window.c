/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:46:43 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 16:46:44 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	open_win(t_window *win, char *name, int h, int w)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, w, h, name);
	win->title = name;
	win->img = mlx_new_image(win->mlx, IMG_SIZE, IMG_SIZE);
	win->addr = mlx_get_data_addr(win->img, &win->bpp,
		&win->size_line, &win->endian);
	start(win, IMG_SIZE, IMG_SIZE);
	mlx_put_image_to_window(win->mlx, win->win,
		win->img, win->x_off, win->y_off);
}

void	clear(t_window *win, t_point size, t_point loc)
{
	int tempx;

	tempx = loc.x;
	while (loc.y < size.y)
	{
		while (loc.x < size.x)
		{
			mlx_pixel_put(win->mlx, win->win, loc.x, loc.y, 0);
			loc.x++;
		}
		loc.x = tempx;
		loc.y++;
	}
}
