#include "fractol.h"

void fiery(t_window *win)
{
	win->color_map[0] =0xef481a;
	win->color_map[1] =0xef611a;
	win->color_map[2] =0xf78247;
	win->color_map[3] =0xf7bc47;

}

void winter(t_window *win)
{
	win->color_map[0] =0x0b3f59;
	win->color_map[1] =0x17658c;
	win->color_map[2] =0x318ab7;
	win->color_map[3] =0x66b9e2;

}

void green(t_window *win)
{
    win->color_map[0] = 0x163f01;
	win->color_map[1] = 0x43b709;
	win->color_map[2] = 0x51e209;
	win->color_map[3] = 0xb8f29b;
}

void greyscale(t_window *win)
{
    win->color_map[0] = 0x383838;
	win->color_map[1] = 0x0c0c0c;
	win->color_map[2] = 0x5e5d5d;
	win->color_map[3] = 0xc4c2c2;
}