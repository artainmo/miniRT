#include "miniRT.h"

/*
** Sphere math intersection calculate
** a = (x2 - x1)2 + (y2 - y1)2 + (z2 - z1)2
** b = 2[ (x2 - x1) (x1 - x3) + (y2 - y1) (y1 - y3) + (z2 - z1) (z1 - z3) ]
** c = x32 + y32 + z32 + x12 + y12 + z12 - 2[x3 x1 + y3 y1 + z3 z1] - r2
** D = b^2 + 4ac
** if b >=0 -> intersection point exists
** u = -b +- √d / (2a)
** x = x1 + u (x2 - x1) | y = y1 + u (y2 - y1) | z = z1 + u (z2 - z1)
**
** x - p2 line
** c.x - p1 line
** o.x - p center object sphere
*/

/*t_inter raycasting_sphere(double x, double y, double z, t_point c, t_obj_sp o)
{
	double a;
	double b;
	double c1;
	double descriminant;
	t_inter res;

	res.inter = 0;
	a = pow(x - c.x, 2) + pow(y - c.y, 2) + pow(z - c.z, 2);
	b = 2*((x - c.x)*(c.x - o.x) + (y - c.y)*(c.y - o.y) + (z - c.z)*(c.z - o.z));
	c1 = pow(o.x, 2) + pow(o.y, 2) + pow(o.z, 2) + pow(c.x, 2) + pow(c.y, 2) +
				pow(c.z, 2) - 2*(o.x*c.x + o.y*c.y + o.z*c.z) - pow(o.r, 2);
	descriminant = pow(b, 2) + 4*a*c1;
	if (descriminant >= 0)
	{
		res.u = (-b + sqrt(descriminant)) / (2*a);
		res.x1 = c.x + res.u * (x - c.x);
		res.y1 = c.y + res.u * (y - c.y);
		res.z1 = c.z + res.u * (z - c.z);
		res.color1 = ft_shadowing(o, ft_abs(ft_round(c.z) - ft_round(res.z1)), ft_abs(ft_round(c.y) - ft_round(res.y1)), ft_abs(ft_round(c.x) - ft_round(res.x1)));
		res.u = (-b - sqrt(descriminant)) / (2*a);
		res.x2 = c.x + res.u * (x - c.x);
		res.y2 = c.y + res.u * (y - c.y);
		res.z2 = c.z + res.u * (z - c.z); //Use the z coordinate to calculate depth and thus image size
		res.color2 = ft_shadowing(o, ft_abs(ft_round(c.z) - ft_round(res.z2)), ft_abs(ft_round(c.y) - ft_round(res.y2)), ft_abs(ft_round(c.x) - ft_round(res.x2)));
		res.inter = 1;
		res.descriminant = descriminant;
	}
	return (res);
}*/

t_inter raycasting_sphere(double x, double y, double z, t_point c, t_obj_sp o)
{
	double a;
	double b;
	double c1;
	double descriminant;
	t_inter res;

	res.inter = 0;
	a = pow(x - c.x, 2) + pow(y - c.y, 2) + pow(z - c.z, 2);
	b = 2*((x - c.x)*(c.x - o.x) + (y - c.y)*(c.y - o.y) + (z - c.z)*(c.z - o.z));
	c1 = pow(o.x, 2) + pow(o.y, 2) + pow(o.z, 2) + pow(c.x, 2) + pow(c.y, 2) +
				pow(c.z, 2) - 2*(o.x*c.x + o.y*c.y + o.z*c.z) - pow(o.r, 2);
	descriminant = pow(b, 2) + 4*a*c1;
	if (descriminant >= 0)
	{
		res.u = (-b + sqrt(descriminant)) / (2*a);
		res.x1 = c.x + res.u * (x - c.x);
		res.y1 = c.y + res.u * (y - c.y);
		res.z1 = c.z + res.u * (z - c.z);
		res.color1 = ft_shadowing(o, ft_abs(ft_round(c.z) - ft_round(res.z1)), ft_abs(ft_round(c.y) - ft_round(res.y1)), ft_abs(ft_round(c.x) - ft_round(res.x1)));
		res.u = (-b - sqrt(descriminant)) / (2*a);
		res.x2 = c.x + res.u * (x - c.x);
		res.y2 = c.y + res.u * (y - c.y);
		res.z2 = c.z + res.u * (z - c.z); //Use the z coordinate to calculate depth and thus image size
		res.color2 = ft_shadowing(o, ft_abs(ft_round(c.z) - ft_round(res.z2)), ft_abs(ft_round(c.y) - ft_round(res.y2)), ft_abs(ft_round(c.x) - ft_round(res.x2)));
		res.inter = 1;
		res.descriminant = descriminant;
	}
	return (res);
}

void screen_iterate_sphere(void *mlx_ptr, void *mlx_win, t_point c, t_obj_sp o)
{
	double x;
	double y;
	double z;
	t_inter inter;

	x = w_l;
	y = w_h;
	z = 300;
	while(y)
	{
		while(x)
		{
				inter = raycasting_sphere(x, y, z, c, o);
				if (inter.inter)
				{
					if ((ft_abs(inter.x1 - c.x) + ft_abs(inter.y1 - c.y) + ft_abs(inter.z1 - c.z)) <= (ft_abs(inter.x2 - c.x) + ft_abs(inter.y2 - c.y) + ft_abs(inter.z2 - c.z)) || inter.descriminant != 0)
						mlx_pixel_put(mlx_ptr, mlx_win, inter.x1, inter.y1, o.color);
					else
						mlx_pixel_put(mlx_ptr, mlx_win, inter.x2, inter.y2, o.color);
				}
			x--;
		}
		y--;
		x = w_l;
	}
}
