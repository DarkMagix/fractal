/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:45:58 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 16:45:59 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	rainbow(t_window *win)
{
	win->color_map[0] = 0xFF0000;
	win->color_map[1] = 0x00FF00;
	win->color_map[2] = 0x0000FF;
	win->color_map[3] = 0xFFFF00;
	win->color_map[4] = 0xFF0000;
	win->color_map[5] = 0x00FF00;
	win->color_map[6] = 0x0000FF;
	win->color_map[7] = 0xFFFF00;
}

void	fiery(t_window *win)
{
	win->color_map[0] = 0xef481a;
	win->color_map[1] = 0xed5f38;
	win->color_map[2] = 0xef611a;
	win->color_map[3] = 0xef7334;
	win->color_map[4] = 0xf78247;
	win->color_map[5] = 0xf9915c;
	win->color_map[6] = 0xf7bc47;
	win->color_map[7] = 0xfcd079;
}

void	winter(t_window *win)
{
	win->color_map[0] = 0x0b3f59;
	win->color_map[1] = 0x0b3f59;
	win->color_map[2] = 0x17658c;
	win->color_map[3] = 0x17658c;
	win->color_map[4] = 0x318ab7;
	win->color_map[5] = 0x318ab7;
	win->color_map[6] = 0x66b9e2;
	win->color_map[7] = 0x66b9e2;
}

void	green(t_window *win)
{
	win->color_map[0] = 0x163f01;
	win->color_map[1] = 0x163f01;
	win->color_map[2] = 0x43b709;
	win->color_map[3] = 0x43b709;
	win->color_map[4] = 0x51e209;
	win->color_map[5] = 0x51e209;
	win->color_map[6] = 0xb8f29b;
	win->color_map[7] = 0xb8f29b;
}

void	greyscale(t_window *win)
{
	win->color_map[0] = 0x383838;
	win->color_map[1] = 0x383838;
	win->color_map[2] = 0x0c0c0c;
	win->color_map[3] = 0x0c0c0c;
	win->color_map[4] = 0x5e5d5d;
	win->color_map[5] = 0x5e5d5d;
	win->color_map[6] = 0xc4c2c2;
	win->color_map[7] = 0xc4c2c2;
}
