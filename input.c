#include "fractol.h"

int mouse_hook(int mousecode, int x, int y, t_window *win)
{


	win->title = win->title;
	if (mousecode == 4)
	{
	//	win->fract.zoom *= 1.1;
		win->cRe += .05;
		win->cIm += .05;
		// win->cRe += (x / SCREEN_W) * 0.1;
		// win->cIm += (y / SCREEN_H) * 0.1;
		start(win, 400, 400);
		// win->cRe += 1/((x / SCREEN_W) / win->fract.zoom);
		// win->cIm += 1/((y / SCREEN_H) / win->fract.zoom);
	}
	else if (mousecode ==5)
	{
	//	win->fract.zoom /= 1.1;
		win->cRe -= .05;
		win->cIm -= .05;
		// win->cRe -= (x / SCREEN_W) * 0.1;
		// win->cIm -= (y / SCREEN_H) * 0.1;
		// win->cRe -= 1/((x / SCREEN_W) / win->fract.zoom);
		// win->cIm -= 1/((y / SCREEN_H) / win->fract.zoom);
		// win->cRe -= 0.01 / (x / (double)400);
		// win->cIm -= 0.01 / (y / (double)400);
		start(win, 400, 400);
	}
	if (mousecode == 1)
	{
		//win->cRe += 1/(((float)x / 400)
		//win->cIm += 1/((()float)y / 400);
		win->cRe = -.7 + 6 *(sin(400 / x / (3.14*20)));
		win->cIm = 0.27015 + 4 *(sin(400 / y / (3.14*40)));
		// win->cRe += 1/((x - SCREEN_W / 2)/ win->fract.zoom);
		// win->cIm += 1/((y - SCREEN_H / 2)/ win->fract.zoom);
		start(win, 400, 400);
		
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 50, 50);
	win->track++;
	win->number = ft_itoa(win->track);
	
	
	return (0);
}
int	key_hook(int kc, t_window *win)
{
	double zm = 0.25;
	win->title = win->title;
	if (kc == 53)
	{
	
		exit(1);
	}
	else if (kc == 126)//z
	{
		win->fract.zoom *= 1.1;
		start(win, 400, 400);

	}
	else if (kc == 125)
	{
		win->fract.zoom /= 1.1;
		start(win, 400, 400);
	}
	else if (kc == 0)//a 
	{
		win->fract.moveX -= 1 / (win->fract.zoom / zm);
	
		start(win, 400, 400);
	
	}
	else if (kc == 2)//d
	{
		
		win->fract.moveX += 1 / (win->fract.zoom / zm);
		//win->fract.moveX += win->fract.zoom * (0.0025 * 0.025);
		//win->fract.moveX += win->fract.zoom *  (0.0025 / win->fract.zoom);
		
		start(win, 400, 400);
	}
	else if (kc == 13)//w
	{
		win->fract.moveY += 1 / (win->fract.zoom /zm);
		//win->fract.moveY += win->fract.zoom * (0.0025);
		//win->fract.moveY += win->fract.zoom *  (0.0025 / win->fract.zoom);
		
		start(win, 400, 400);
	}
	else if (kc == 1)//s
	{
		win->fract.moveY -= 1 / (win->fract.zoom /zm);
		//win->fract.moveY -= win->fract.zoom * (0.0025);
		//win->fract.moveY -= win->fract.zoom *  (0.0025 / win->fract.zoom);
		start(win, 400, 400);
		
	}
	else if (kc == 7)
	{
		win->fract.zoom = 1;
		start (win, 400, 400);
	}
	//mlx_destroy_image(win->mlx, win->img);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 50, 50);
	win->track++;
	//printf("im in here");
	//w 13
	//a 0
	//s 1
	//d 0
	//up 126
	//left 123
	//down 125
	//right 124
	//("%d ", kc);
	return (0);
}
int get_input()
{
	write(1, "test", 1);
	return (1);
}
int mouse_move(int x, int y, t_window *win)
{
	if (x >= 0 && x <= 400 && y >= 0 && y <= 400)
	{
		if (win->lastx == 0 && win->lasty == 0)
		{
			win->lastx = 400 / 2;
			win->lasty = 400 / 2;
		}
		else
		{
			win->cIm += (win->lasty - y) * 0.0025;
			win->cRe += (win->lastx - x) * 0.0025;
			
			win->lastx = x;
			win->lasty = y;
			start(win, 400, 400);
			mlx_put_image_to_window(win->mlx, win->win, win->img, 50, 50);
			win->track++;
			char *number = ft_itoa(win->track);
			//clear_rect(500, 500, 30, 120);
			mlx_string_put(win->mlx,win->win, 50, 50,0x00FF00, number);
			free(number);
			

			//mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);

		}
	}
	return (0);
}
