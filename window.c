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
void color(t_window *win, int red, int green, int blue, int y, int x)
{	
	mlx_pixel_put(win->mlx, win->win,x,y, hex_to_dec(ft_rgb_to_hex(red,green,blue)));
}

void clear(t_window *win, int h, int w)
{	
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < h)
	{
		while (x < w)
		{
			mlx_pixel_put(win->mlx,win->win, x, y, 0);
			x++;
		}
		x = 0;
		y++;
	}
}
void color2(t_window *win, int y, int x, int i)
{
	int map [4];
	map[0] = 0xf44242;
	map[1] = 0xf47742;
	map[2] = 0x53f442;
	map[3] = 0x4242f4;
	// map[0] = hex_to_dec(ft_rgb_to_hex(1, 255, 1)) + 100;
	// map[1] = hex_to_dec(ft_rgb_to_hex(1, 200, 1)) + 100;
	// map[2] = hex_to_dec(ft_rgb_to_hex(1, 175,1)) + 100;
	// map[3] = hex_to_dec(ft_rgb_to_hex(1, 150, 1)) + 100;
	mlx_pixel_put(win->mlx, win->win,x,y, map[i]);
}
// void draw_map(t_window *win, int h, int w)
// {
// 	int x;
// 	x = 0;
// 	int y;
// 	y = 0;
// 	int i;
// 	i = 0;
// 	double minR, maxR;
// 	double minI,maxI;
// 	minR = -2.00;
// 	maxR = 0.7;
// 	minI = -1.0;
// 	maxI = 1.0;
// 	int maxIterations;
// 	maxIterations = 1024;
// 	while (y < h)
// 	{
// 		while (x < w)
// 		{
// 			double c_re = ((x) - w / 2.0) * 4.0 / w;
// 			double c_im = ((y) - h / 2.0) * 4.0 / w;
// 			double x0 = 0;
// 			double y0 = 0;
// 			i = 0;
// 			while (x0 *x0 + y0 *y0 < 4.0 && i < maxIterations)
// 			{
// 				double x_new = x0 * x0 - y0 * y0 + c_re;
// 				y0 = 2 * x0 * y0 + c_im;
// 				x0 = x_new;
// 				i++;
			
// 			}
			
// 			if (i == maxIterations)
// 				color (win, 0,0,0, y, x);
// 			else
// 				color2(win, y, x, i % 4);
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 		//printf("\n");
// 	}
// 	printf("Finished\n");
// }
void draw_map(t_window *win, int h, int w)
{
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
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if((newRe * newRe + newIm * newIm) > 4) break;
				i++;
			}
			if (i == win->fract.maxIter)
 				color (win, 0,0,0, y, x);
			else
				color2(win, y, x, i % 4);
			x++;
		}
		x = 0;
		y++;
		//printf("\n");
	}
	printf("Finished\n");
}
// void draw_map(t_window *win, int h, int w)
// {
// int imageWidth, imageHeight, maxN;
// 	double minR, maxR, minI, maxI;
// 	int y;
// 	int x;
// 	int i;
// 	imageWidth = w;
// 	imageHeight = h;
// 	imageWidth = 200;
// 	imageHeight = 200;
	
// 	maxN = 256;
// 	minR = -2.00;
// 	maxR = 0.7;
// 	minI = -1.0;
// 	maxI = 1.0;
// 	i = 0;
// 	y =0;
// 	x= 0;
//    // printf("%d %d",h,w);
//     while (x < imageWidth)
// 	{
// 		while (y < imageHeight)
// 		{
// 			double cr = mapToReal(x, imageWidth, minR, maxR);
// 			double ci = mapToImaginary(y, imageHeight, minI, maxI);
// 			int n = findMandel(cr, ci, maxN);
// 			int r = (n % 256);
// 			int g = (n % 256);
// 			int b = (n % 256);    
//             printf("(%d %d)\t, %s", y, x , ft_rgb_to_hex(r, g , b));
//              mlx_pixel_put(win->mlx, win->win, y,x, hex_to_dec(ft_rgb_to_hex(r,g,b)) + 50);
// 			i++;
// 			y++;
// 		}
// 		//printf("\n");
// 		y = 0;
// 		x++;
// 	}
//     // int x;
//     // int y;

//     // x = 0;
//     // y = 0;
//     // while(x < w && y < h)
//     // {
//     //     mlx_pixel_put(win->mlx, win->win,x,y,0xCCCCCC);
//     //     x+=25;
//     //     y+=25;
//     // }
// }