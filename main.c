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

double mapToReal(int x, int imageWidth, double minR, double maxR)
{
	double range = maxR - minR;
	return x * (range / imageWidth) + minR;

}
double mapToImaginary(int y, int imageHeight, double minI, double maxI)
{
	double range = maxI - minI;
	return y * (range / imageHeight) + minI;
}

int findMandel(double cr, double ci, int max)
{
	int i =0;
	double zr = 0.0; 
	double zi = 0.0;
	while (i < max && zr * zr + zi * zi < 4.0)
	{
		double temp = (zr * zr) - (zi * zi) + cr;
		zi =  2 * zr + zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

char *ft_rgb_to_hex(int r, int g, int b)
{
	char *res;
	res = (char*)malloc(sizeof(char) * (6 + 1));
	// if (ft_strlen(ft_itoa_base(r, 16)) < 2)
	// 	strcat(res,"0");
	strcat(res,ft_itoa_base(r, 16));

	// if (ft_strlen(ft_itoa_base(g, 16)) < 2)
	// 	strcat(res,"0");
	strcat(res,ft_itoa_base(g, 16));

	// if (ft_strlen(ft_itoa_base(b, 16)) < 2)
	// 	strcat(res,"0");
	strcat(res,ft_itoa_base(b, 16));

	
	strcat(res,"\0");
	return res;
}
int main(void)
{
	t_window win;

	ft_bzero(&win, sizeof(t_window));
	//validate(&win);
	init_window(&win);
	open_win(&win, "FDF", (SCREEN_H), (SCREEN_W));
	mlx_hook(win.win, 20, 0, get_input, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, 6, 0, mouse_move, &win);
	mlx_mouse_hook(win.win, mouse_hook, &win);
	mlx_loop(win.mlx);
	mlx_destroy_image(&win.mlx, &win.img);
	return (0);
}
