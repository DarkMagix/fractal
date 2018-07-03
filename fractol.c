#include "fractol.h"

void init_window(t_window *win)
{
    win->fract.zoom = 1.0;
    win->fract.moveX = 0;
    win->fract.moveY = 0;
    win->fract.maxIter =64;
    win->x_off = 1;
    win->y_off = 1;
	win->minR = -2.0;
	win->maxR = 1.0;
	win->minI = -1.2;
	win->maxI = win->minI + (win->maxR - win->minR) * (400/400);
	win->re_factor = (win->maxR - win->minR) / (400 - 1);
	win->im_factor = (win->maxI - win->minI) / (400 - 1);
	win->cRe= -0.7;
	win->cIm = 0.27015;
	
	
    // int y;
    // int x;
    // y = 0;
    // x = 0;
//     while (y < SCREEN_H)
//     {
//         while (x < SCREEN_W)
//         {
//             *((unsigned*)win->addr + (x + y * SCREEN_W)) = 0xFF0000;
// //            *((unsigned*)win->addr + (x + y * (SCREEN_W)) = 0xFF0000;
//             x++;
//         }
//         x = 0;
//         y++;
//     }
    
}

//julia
// void    start(t_window *win, int w, int h)
// {
//     //*((unsigned*)win->addr + (x + y * w)) = 0xFF0000;
//     int map [4];
// 	map[0] = 0xff003f;
// 	map[1] = 0xff6a00;
// 	map[2] = 0xffa100;
// 	map[3] = 0xffcc00;
//     int x;
// 	int y;

	
// 	int i;
// 	y = 0;
// 	x = 0;
	

// 	while (y < h)
// 	{
// 		while (x < w)
// 		{
// 			win->newRe = 1.5 * (x - w / 2) / (0.5 * win->fract.zoom * w) + win->fract.moveX;
// 			win->newIm = (y - h / 2) / (0.5 * win->fract.zoom * h) + win->fract.moveY;
// 			i = 0;
			
// 			while (i < win->fract.maxIter)
// 			{
// 				win->oldRe = win->newRe;
// 				win->oldIm = win->newIm;
// 				win->newRe = win->oldRe * win->oldRe - win->oldIm * win->oldIm + win->cRe;
// 				win->newIm = 2 * win->oldRe * win->oldIm + win->cIm;
// 				if((win->newRe * win->newRe + win->newIm * win->newIm) > 4) break;
// 				i++;
// 			}
// 			if (i < win->fract.maxIter)
// 			{
// 			 	*((unsigned*)win->addr + (x + y * w)) = map[(i % 32)/8];
// 			}
// 			else
// 				*((unsigned*)win->addr + (x + y * w)) = 0x000000;
// 			x++;
// 		}
// 		x = 0;
// 		y++;
	
// 	}

// }

//Working Mandelbrot
void    start(t_window *win, int w, int h)
{
    //*((unsigned*)win->addr + (x + y * w)) = 0xFF0000;
    int map [4];
	//r to y
	// map[0] = 0xff003f;
	// map[1] = 0xff6a00;
	// map[2] = 0xffa100;
	// map[3] = 0xffcc00;
	map[0] = 0x163f01;//black
	map[1] = 0x43b709;
	map[2] = 0x51e209;
	map[3] = 0xb8f29b;
    int x;
	int y;
	double pr, pi;                   //real and imaginary part of the pixel p
	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
	printf("%f\t", win->fract.zoom);
	int j;
	int i;
	y = 0;
	x = 0;
	j = 0;

	while (y < h)
	{
		while (x < w)
		{
		
	//calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
			//printf("%f\t", win->fract.moveX);
			pr = 1.5 * (x - w / 2) / (0.5 * win->fract.zoom * w) + win->fract.moveX;
			pi = (y - h / 2) / (0.5 * win->fract.zoom * h) + win->fract.moveY;
			newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
			//"i" will represent the number of iterations
			i = 0;
		//start the iteration process
			while (i < win->fract.maxIter)
			{
				oldRe = newRe;
				oldIm = newIm;
				// newRe = oldRe * oldRe - oldIm * oldIm + k_re;
				// newIm = 2 * oldRe * oldIm + k_im;
				newRe = fabs(oldRe * oldRe - oldIm * oldIm + pr);
				newIm = fabs(2 * oldRe * oldIm + pi);
				if((newRe * newRe + newIm * newIm) > 4) break;
				i++;
			}
			if (i < win->fract.maxIter)
			{
			 	*((unsigned*)win->addr + (x + y * w)) = map[(i % 32)/8];
				// else if (i >=8 && i <= 15)
			 	// 	*((unsigned*)win->addr + (x + y * w)) = map[1];
				// else if (i >=16 && i <= 23)
			 	// 	*((unsigned*)win->addr + (x + y * w)) = map[2];
				// else if (i >=24 && i <= 30)
			 	// 	*((unsigned*)win->addr + (x + y * w)) = map[3];
				
			}
			else
				*((unsigned*)win->addr + (x + y * w)) = 0x000000;
			x++;
		}
		x = 0;
		y++;
	
	}

}
// void    start(t_window *win, int w, int h)
// {
//     //*((unsigned*)win->addr + (x + y * w)) = 0xFF0000;
//     int map [4];
// 	map[0] = 0xf44242;
// 	map[1] = 0xf47742;
// 	map[2] = 0x53f442;
// 	map[3] = 0x4242f4;
//     int x;
// 	int y;
// 	int i;
// 	int inside;
// 	y = 0;
// 	x = 0;
// 	i = 0;
// 	while (y < h)
// 	{
// 		win->c_im = win->maxI - y * win->im_factor;
// 		while (x < w)
// 		{
// 			win->c_re = win->minR + x * win->re_factor;
// 			win->Z_re = win->c_re;
// 			win->Z_im = win->c_im;
// 			inside = 1;
// 			i = 0;
// 			while (i < win->fract.maxIter)
// 			{
// 				win->Z_re2 = win->Z_re * win->Z_re;
// 				win->Z_im2 = win->Z_im * win->Z_im;
// 				if (win->Z_re2 + win->Z_im2 > 4)
// 				{
// 					inside = 0;
// 					break;
// 				}
// 				win->Z_im = 2 * win->Z_re * win->Z_im + win->c_im;
// 				win->Z_re = win->Z_re2 - win->Z_im2 + win->c_re;
// 				i++;
// 			if (inside == 1)
// 				*((unsigned*)win->addr + (x + y * w)) = map[i % 4];
// 			else
// 				*((unsigned*)win->addr + (x + y * w)) = 0x0000FF;
// 			}	
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }

// 	// //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
// 	// 		//printf("%f\t", win->fract.moveX);
// 	// 		pr = 1.5 * (x - w / 2) / (0.5 * win->fract.zoom * w) + win->fract.moveX;
// 	// 		pi = (y - h / 2) / (0.5 * win->fract.zoom * h) + win->fract.moveY;
// 	// 		newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
// 	// 		//"i" will represent the number of iterations
// 	// 		i = 0;
// 	// 	//start the iteration process
// 	// 		while (i < win->fract.maxIter)
// 	// 		{
// 	// 			oldRe = newRe;
// 	// 			oldIm = newIm;
// 	// 			newRe = oldRe * oldRe - oldIm * oldIm + pr;
// 	// 			newIm = 2 * oldRe * oldIm + pi;
// 	// 			if((newRe * newRe + newIm * newIm) > 4) break;
// 	// 			i++;
// 	// 		}
// 	// 		 *((unsigned*)win->addr + (x + y * w)) = map[i % 4];
// 	// 		x++;
// 	// 	}
// 	// 	x = 0;
// 	// 	y++;
	