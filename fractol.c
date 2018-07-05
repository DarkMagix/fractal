#include "fractol.h"

void init_window(t_window *win)
{
    win->fract.zoom = 1.0;
    win->fract.moveX = -0.5;
    win->fract.maxIter =32;
    win->x_off = (SCREEN_W - IMG_SIZE) / 2;
    win->y_off = (SCREEN_H - IMG_SIZE) / 2;
	win->cRe= -0.7;
	win->cIm= 0.27015;
	win->c_index = 0;
	
	fiery(win);
}

void    start(t_window *win, int w, int h)
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
			while (i < win->fract.maxIter)
			{
				get_math(win->c_fract, win);
				if((win->newRe * win->newRe + win->newIm * win->newIm) > 4) break;
				i++;
			}
			put_pixel_to_image(win, x, y, i);
			x++;
		}
		x = 0;
		y++;
	}
}
