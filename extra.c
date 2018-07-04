#include "fractol.h"

void pixel_math(t_window *win, int x, int y)
{
    win->pr = 1.5 * (x - IMG_SIZE / 2) / (0.5 * win->fract.zoom * IMG_SIZE) + win->fract.moveX;
	win->pi = (y - IMG_SIZE / 2) / (0.5 * win->fract.zoom * IMG_SIZE) + win->fract.moveY;
    if(win->c_fract != 'j')
    {
        win->newRe = 0;
        win->newIm = 0;
        win->oldRe = 0;
        win->oldIm = 0;
    }
    else
    {
        win->newRe = 1.5 * (x - IMG_SIZE / 2) / (0.5 * win->fract.zoom * IMG_SIZE) + win->fract.moveX;
		win->newIm = (y - IMG_SIZE / 2) / (0.5 * win->fract.zoom * IMG_SIZE) + win->fract.moveY;
    }
}
void put_pixel_to_image(t_window *win, int x, int y, int i)
{
    if (i < win->fract.maxIter)
        *((unsigned*)win->addr + (x + y * IMG_SIZE)) = win->color_map[(i % 32)/8];
    else
        *((unsigned*)win->addr + (x + y * IMG_SIZE)) = 0x000000;
}