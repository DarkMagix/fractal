#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>

# define SCREEN_H 1080
# define SCREEN_W 1920

typedef struct	s_rgb
{
	int	r;
	int g;
	int b;
}				t_rgb;
typedef struct	s_fractal
{
	double	zoom;
	double	moveX;
	double	moveY;
	double	pr;
	double	pri;
	int		maxIter;
}				t_fractal;
typedef struct	s_window
{
	void		*mlx;
	void		*win;
	char		*title;
	t_rgb		rgb;
	t_fractal 	fract;
	void		*img;
	char		*addr;
	int			x_off;
	id_t		y_off;
	double		minR;
	double		maxR;
	double		minI;
	double		maxI;
	double		re_factor;
	double		im_factor;
	double		newRe;
	double		oldRe;
	double		newIm;
	double		oldIm;
	double		cRe;
	double		cIm;
	int			bpp;
	int			size_line;
	int			endian;
	int			lastx;
	int			lasty;
	int			track;
	char		*number;
}				t_window;

void			open_win(t_window *win, char *name, int h, int w);
void			draw_map(t_window *win, int h, int w);
int				findMandel(double cr, double ci, int max);
double			mapToImaginary(int y, int imageHeight, double minI, double maxI);
double			mapToReal(int x, int imageWidth, double minR, double maxR);
char			*ft_rgb_to_hex(int r, int g, int b);
int				key_hook(int kc, t_window *win);
void			clear(t_window *win, int h, int w);
void			init_window(t_window *win);
void			start(t_window *win, int w, int h);
int				mouse_hook(int mousecode, int x, int y, t_window *win);
int				mouse_move(int x, int y, t_window *win);
int				get_input();
#endif