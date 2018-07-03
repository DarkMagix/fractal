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

// while (x*x + y*y < 2*2) && iteration < max)
// {
// 	int xtemp;
// 	xtemp = x*x - y*y + x0;
// 	y = 2 * x*y + y0;
// 	x = xtemp;
// 	iteration +=1;
// }


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
// void test_mandle(int h, int w, int max)
// {
// 	int r = 0;
// 	int c = 0;
// 	while (r < h)
// 	{
// 		while (c < w)
// 		{
// 			double c_re = (c - w/2.0) * 4.0 / w;
// 			double c_i = (r - h / 2.0) * 4.0 / w;
// 			double x = 0;
// 			double y = 0;
// 			int iter = 0;
// 			while (x * x + y * y && iter < max)
// 			{
// 				double x_new = x*x - y*y + c_re;
// 				y = 2 * x * y + c_i;
// 				x = x_new;
// 				iter++;
// 			}
// 			c++;
// 		}
// 		c= 0;
// 		r++;
// 	}
// }

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
	init_window(&win);
	open_win(&win, "FDF", (SCREEN_H), (SCREEN_W));
	
	//mlx_put_image_to_window(&win.mlx,&win.win, &win.img, 0, 0);
	//draw_map(&win, SCREEN_H, SCREEN_W);
	mlx_hook(win.win, 20, 0, get_input, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, 6, 0, mouse_move, &win);
	mlx_mouse_hook(win.win, mouse_hook, &win);
	mlx_loop(win.mlx);
	mlx_destroy_image(&win.mlx, &win.img);
	return (0);
}
