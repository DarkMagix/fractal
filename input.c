#include "fractol.h"

int mouse_hook(int mousecode, int x, int y, t_window *win)
{


	win->title = win->title;
	if (mousecode == 1)
	{
		if (win->c_index >3)
			win->c_index = 0;
		
		(win->c_index == 0) ? winter(win) : 0;
		(win->c_index == 1) ? fiery(win) : 0;
		(win->c_index == 2) ? green(win) : 0;
		(win->c_index == 3) ? greyscale(win) : 0;
		win->c_index++;
		start(win, IMG_SIZE, IMG_SIZE);

	}
	if (mousecode == 4)
	{
	//	win->fract.zoom *= 1.1;
		win->cRe += .05;
		win->cIm += .05;
		// win->cRe += (x / SCREEN_W) * 0.1;
		// win->cIm += (y / SCREEN_H) * 0.1;
		start(win, IMG_SIZE, IMG_SIZE);
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
		start(win, IMG_SIZE, IMG_SIZE);
	}
	// if (mousecode == 1)
	// {
	// 	//win->cRe += 1/(((float)x / 400)
	// 	//win->cIm += 1/((()float)y / 400);
	// 	//win->cRe = -.7 + 6 *(sin(IMG_SIZE / x / (3.14*20)));
	// 	//win->cIm = 0.27015 + 4 *(sin(IMG_SIZE / y / (3.14*40)));
	// 	// win->cRe += 1/((x - SCREEN_W / 2)/ win->fract.zoom);
	// 	// win->cIm += 1/((y - SCREEN_H / 2)/ win->fract.zoom);
	// 	start(win, IMG_SIZE, IMG_SIZE);
		
	//  }
	mlx_put_image_to_window(win->mlx, win->win, win->img, win->x_off, win->y_off);
	win->track++;
	win->number = ft_itoa(win->track);
	
	
	return (x + y);
}
int	key_hook(int kc, t_window *win)
{
	double zm = 0.25;
	win->title = win->title;
	if (kc == 53)
	{
		exit(1);
	}
	else if (kc == 38)
	{
		win->c_fract = 'j';
		start(win, IMG_SIZE, IMG_SIZE);
	
	}
	else if (kc == 126)//zoom in
	{
		win->fract.zoom *= 1.1;
		start(win, IMG_SIZE, IMG_SIZE);

	}
	else if (kc == 125) // zoom out
	{
		win->fract.zoom /= 1.1;
		start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 0)//a 
	{
		win->fract.moveX -= 1 / (win->fract.zoom / zm);
		start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 2)//d
	{
		win->fract.moveX += 1 / (win->fract.zoom / zm);
		start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 1)//w
	{
		win->fract.moveY += 1 / (win->fract.zoom /zm);
		start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 13)//s
	{
		win->fract.moveY -= 1 / (win->fract.zoom /zm);
		start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 7)
	{
		win->fract.zoom = 1;
		start(win, IMG_SIZE, IMG_SIZE);
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, win->x_off, win->y_off);
	win->track++;
	return (0);
}
int get_input()
{
	write(1, "test", 1);
	return (1);
}
int mouse_move(int x, int y, t_window *win)
{
	char *m_x = 0;
	char *m_y = 0;

	if (x >= win->x_off & x <= win->x_off + (IMG_SIZE)
		 && y >= win->y_off && y <= win->y_off + (IMG_SIZE))
	{
		if (win->lastx == 0 && win->lasty == 0)
		{
			win->lastx = win->x_off;
			win->lasty = win->y_off;
		}
		else
		{
			win->cIm += (win->lasty - y) * 0.0025;
			win->cRe += (win->lastx - x) * 0.0025;
			
			win->lastx = x;
			win->lasty = y;
			start(win, IMG_SIZE, IMG_SIZE);
			mlx_put_image_to_window(win->mlx, win->win, win->img, win->x_off, win->y_off);
			m_x = ft_itoa(x);
			m_y = ft_itoa(y);
			win->track++;
			mlx_string_put(win->mlx,win->win, win->x_off, win->y_off,0x00FF00, m_x);
			mlx_string_put(win->mlx,win->win, win->x_off + 25, win->y_off + 25,0x00FF00, m_y);
			free(m_x);
			free(m_y);
		}
	}
	return (0);
}
