#include "fractol.h"

void bship_math(t_window *win)
{
    win->oldRe = win->newRe;
    win->oldIm = win->newIm;
    win->newRe = fabs(win->oldRe * win->oldRe - win->oldIm * win->oldIm + win->pr);
    win->newIm = fabs(2 * win->oldRe * win->oldIm + win->pi);
}

void julia_math(t_window *win)
{
  	win->oldRe = win->newRe;
    win->oldIm = win->newIm;
    win->newRe = win->oldRe * win->oldRe - win->oldIm * win->oldIm + win->cRe;
    //win->newRe = win->oldRe * win->oldIm * win->oldIm + win->cRe;
    win->newIm = 2 * win->oldRe * win->oldIm + win->cIm;
}

void mandel_math(t_window *win)
{
    win->oldRe = win->newRe;
    win->oldIm = win->newIm;
    win->newRe = (win->oldRe * win->oldRe - win->oldIm * win->oldIm + win->pr);
    win->newIm = (2 * win->oldRe * win->oldIm + win->pi);
}
void get_math(char c, t_window *win)
{
    (c == 'j') ? julia_math(win) : 0;
    (c == 'b') ? bship_math(win) : 0;
    (c == 'm') ? mandel_math(win) : 0;

}