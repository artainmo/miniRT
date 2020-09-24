#include "miniRT.h"


void triangle_2d(void *mlx_ptr, void *mlx_win,int x,int y, int h, int color)
{
	int static_x;
	int l;

	static_x = x;
	while(h)
	{
		x = static_x;
		l = h;
		while(l)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, color);
			x++;
			l--;
		}
		y--;
		h--;
	}
}

void triangle_2d_r(void *mlx_ptr, void *mlx_win,int x,int y, int h, int color)
{
	int static_x;
	int l;

	static_x = x;
	while(h)
	{
		x = static_x;
		l = h;
		while(l)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, y, x, color);
			x++;
			l--;
		}
		y--;
		h--;
	}
}
