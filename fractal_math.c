/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:46:14 by mweir             #+#    #+#             */
/*   Updated: 2018/07/05 16:46:15 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bship_math(t_window *win)
{
	win->old_re = win->new_re;
	win->old_im = win->new_im;
	win->new_re = fabs(win->old_re * win->old_re -
		win->old_im * win->old_im + win->pr);
	win->new_im = fabs(2 * win->old_re * win->old_im + win->pi);
}

void	julia_math(t_window *win)
{
	win->old_re = win->new_re;
	win->old_im = win->new_im;
	win->new_re = win->old_re * win->old_re - win->old_im
		* win->old_im + win->c_re;
	win->new_im = 2 * win->old_re * win->old_im + win->c_im;
}

void	mandel_math(t_window *win)
{
	win->old_re = win->new_re;
	win->old_im = win->new_im;
	win->new_re = (win->old_re * win->old_re - win->old_im
		* win->old_im + win->pr);
	win->new_im = (2 * win->old_re * win->old_im + win->pi);
}

void	get_math(char c, t_window *win)
{
	(c == 'j') ? julia_math(win) : 0;
	(c == 'b') ? bship_math(win) : 0;
	(c == 'm') ? mandel_math(win) : 0;
}
