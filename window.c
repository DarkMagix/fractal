#include "fractol.h"

void open_win(t_window *win, char *name, int h, int w)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, w, h, name);
	win->title = name;
	win->img = mlx_new_image(win->mlx, IMG_SIZE, IMG_SIZE);
	win->addr = mlx_get_data_addr(win->img, &win->bpp, &win->size_line, &win->endian);
	start(win, IMG_SIZE, IMG_SIZE);
	mlx_put_image_to_window(win->mlx, win->win, win->img, win->x_off, win->y_off);
	char *number;
	win->track++;
	number = ft_itoa(win->track);
	//mlx_string_put(win->mlx,win->win, 500, 500,0xFF0000, number);
}
int hex_to_dec(char *hexval)
{   
	int len = ft_strlen(hexval);
	 int i;
	// Initializing base value to 1, i.e 16^0
	int base = 1;
	 
	int dec_val = 0;
	i = len -1;
	// Extracting characters as digits from last character
	while (len >= 0)
	{   
		if (hexval[i]>='0' && hexval[i]<='9')
		{
			dec_val += (hexval[i] - 48)*base;
			base = base * 16;
		}
		else if (hexval[i]>='a' && hexval[i]<='f')
		{
			dec_val += (hexval[i] - 55)*base;
			base = base*16;
		}
		else if (hexval[i]>='A' && hexval[i]<='F')
		{
			dec_val += (hexval[i] - 23)*base;
			base = base*16;
		}
		len--;
	}
	return dec_val;
}

void clear(t_window *win, t_point size, t_point loc)
{	
	int tempx = loc.x;
	while (loc.y < size.y)
	{
		while (loc.x < size.x)
		{
			mlx_pixel_put(win->mlx,win->win, loc.x, loc.y, 0);
			loc.x++;
		}
		loc.x = tempx;
		loc.y++;
	}
}