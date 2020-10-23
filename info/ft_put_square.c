#include "miniRT.h"

void square_2d(void *mlx_ptr, void *mlx_win,int x,int y, int l,int color)
{
	int static_x;
	int static_l;
	int h;

	static_x = x;
	static_l = l;
	h = l;
	while(h)
	{
		x = static_x;
		l = static_l;
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
