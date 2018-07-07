/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 18:07:59 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 18:08:00 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define IMG_SIZE 720

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_fractal
{
	double	zoom;
	double	move_x;
	double	move_y;
	double	pr;
	double	pri;
	int		max_iter;
}				t_fractal;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	char		*title;
	t_fractal	fract;
	void		*img;
	char		*addr;
	int			x_off;
	int			y_off;
	int			img_size;
	double		new_re;
	double		old_re;
	double		new_im;
	double		old_im;
	double		pr;
	double		pi;
	double		c_re;
	double		c_im;
	int			bpp;
	int			size_line;
	int			endian;
	int			lastx;
	int			lasty;
	int			track;
	int			color_map[8];
	int			c_index;
	char		c_fract;
}				t_window;

void			open_win(t_window *win, char *name, int h, int w);
void			draw_map(t_window *win, int h, int w);
char			*ft_rgb_to_hex(int r, int g, int b);
int				key_hook(int kc, t_window *win);
void			clear(t_window *win, t_point size, t_point loc);
void			init_window(t_window *win);
void			start(t_window *win, int w, int h);
int				mouse_hook(int mousecode, int x, int y, t_window *win);
int				mouse_move(int x, int y, t_window *win);
int				get_input();
void			fiery(t_window *win);
void			winter(t_window *win);
void			green(t_window *win);
void			greyscale(t_window *win);
void			rainbow(t_window *win);
void			pixel_math(t_window *win, int x, int y);
void			bship_math(t_window *win);
void			julia_math(t_window *win);
void			mandel_math(t_window *win);
void			put_pixel_to_image(t_window *win, int x, int y, int i);
void			get_math(char c, t_window *win);
int				validate_fractal(char *c, t_window *win);
void			get_vitals(t_window *win);
int				controls_on_screen(t_window *win);
void			reset_fractal(t_window *win, int kc);
void			init_julia(t_window *win);
void			init_mandel(t_window *win);
void			init_ship(t_window *win);
void			alt_zoom(int kc, t_window *win);
#endif
