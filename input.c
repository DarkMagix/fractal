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
		//start(win, IMG_SIZE, IMG_SIZE);

	}
	if (mousecode == 4)
	{
		win->cRe += .05;
		win->cIm += .05;
		//start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (mousecode ==5)
	{
		win->cRe -= .05;
		win->cIm -= .05;
	}
	start(win, IMG_SIZE, IMG_SIZE);
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
	else if (kc == 9)
	{
		get_vitals(win);
	}
	else if (kc == 38)
	{
		win->c_fract = 'j';
	//	start(win, IMG_SIZE, IMG_SIZE);
	
	}
	else if (kc == 126)//zoom in
	{
		win->fract.zoom *= 1.1;
	//	start(win, IMG_SIZE, IMG_SIZE);

	}
	else if (kc == 125) // zoom out
	{
		win->fract.zoom /= 1.1;
	//	start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 0)//a 
	{
		win->fract.moveX -= 1 / (win->fract.zoom / zm);
	//	start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 2)//d
	{
		win->fract.moveX += 1 / (win->fract.zoom / zm);
	//	start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 1)//w
	{
		win->fract.moveY += 1 / (win->fract.zoom /zm);
	//	start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 13)//s
	{
		win->fract.moveY -= 1 / (win->fract.zoom /zm);
	//	start(win, IMG_SIZE, IMG_SIZE);
	}
	else if (kc == 15) //reset
	{
		if (win->c_fract == 'j')
		{
			win->fract.zoom = 0.751315;
			win->fract.moveX =-0.133975;
			win->fract.moveY = 0.0;
			win->cRe= -0.7;
			win->cIm= 0.27015;
			win->lastx = win->x_off * 2;
			win->lasty = win->y_off * 2;
		}
		else if (win->c_fract == 'b')
		{
			//bship
			win->fract.zoom = 0.909091;
			win->fract.moveX =-0.408975;
			win->fract.moveY = -0.550000;
		}
		else if (win->c_fract == 'm')
		{
			win->fract.zoom = 0.909091;
			win->fract.moveX =-0.500000;
			win->fract.moveY = 0;
		}

	}
	start(win, IMG_SIZE, IMG_SIZE);
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
			win->lastx = win->x_off * 2;
			win->lasty = win->y_off * 2;
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
			mlx_string_put(win->mlx,win->win, win->x_off, win->y_off,0x00FF00, m_x);
			mlx_string_put(win->mlx,win->win, win->x_off + 25, win->y_off + 25,0x00FF00, m_y);
			free(m_x);
			free(m_y);
		}
	}
	return (0);
}
