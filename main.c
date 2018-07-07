/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:30:46 by mweir             #+#    #+#             */
/*   Updated: 2018/06/26 13:32:42 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_window win;

	ft_bzero(&win, sizeof(t_window));
	if (ac == 2)
	{
		init_window(&win);
		if ((validate_fractal(av[1], &win) == 0))
			return (0);
		open_win(&win, "FDF", (SCREEN_H), (SCREEN_W));
		mlx_key_hook(win.win, key_hook, &win);
		mlx_hook(win.win, 6, 0, mouse_move, &win);
		mlx_hook(win.win, 12, 0, controls_on_screen, &win);
		mlx_mouse_hook(win.win, mouse_hook, &win);
		mlx_loop(win.mlx);
		mlx_destroy_image(&win.mlx, &win.img);
	}
	else
		ft_putendl("Proper Usage: /fractal [fractal] (j, b, m)");
	return (0);
}
