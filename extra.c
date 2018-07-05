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

void get_vitals(t_window *win)
{
    printf("\nZoom: %f\n", win->fract.zoom);
    printf("MoveX, MoveY(%f, %f)\n", win->fract.moveX, win->fract.moveY);
}
int validate_fractal(char *c, t_window *win)
{
   printf("Character: %c", *c);
    if (*c == 'j')
    {
        printf("Im in J Check\n");
        win->c_fract = 'j';
        return (1);
    }
    else if (*c == 'm')
    {
        printf("Im in M Check\n");
        win->c_fract = 'm';
        return (1);
    }
    else if (*c == 'b')
    {
        printf("Im in B Check\n");
        win->c_fract = 'b';
        return (1);
    }
    else
    {
        ft_putendl("Proper Usage: /fractal [fractal] (j, b, m)");
        return (0);
    }
}
int controls_on_screen(t_window *win)
{
    t_point size;
    t_point location;

    location.x = 0;
    location.y = 0;
    size.x = 100;
    size.y = 200;
   // char *test = ft_strdup(&win->c_fract);
    //start(win, IMG_SIZE, IMG_SIZE);
    clear(win, size, location);
    //mlx_put_image_to_window(win->mlx, win->win, win->img, win->x_off, win->y_off);
    mlx_string_put(win->mlx, win->win,0, 0,0xFF0000,"WASD to Move Fractal");
    mlx_string_put(win->mlx, win->win,0, 20,0xFF0000,"Up/Down Arrow to Zoom In/Out");
    mlx_string_put(win->mlx, win->win,0, 40,0xFF0000,"LMB To Cycle Colors");
    mlx_string_put(win->mlx, win->win,0, 60,0xFF0000,"R To Reset Fractal");



    	// start(win, IMG_SIZE, IMG_SIZE);
		// 	mlx_put_image_to_window(win->mlx, win->win, win->img, win->x_off, win->y_off);
		// 	m_x = ft_itoa(x);
		// 	m_y = ft_itoa(y);
		// 	win->track++;
		// 	mlx_string_put(win->mlx,win->win, win->x_off, win->y_off,0x00FF00, m_x);
		// 	mlx_string_put(win->mlx,win->win, win->x_off + 25, win->y_off + 25,0x00FF00, m_y);
		// 	free(m_x);
		// 	free(m_y);
    return (0);
}