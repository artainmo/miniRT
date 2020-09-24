#include "../miniRT.h"

/*
** s->plane intersection calculate
** A point on s->plane p(px,py,pz) is given with a normalized vector n[nx,ny,nz]
** normalized vector (means perpendicular / vector_n * vector_a = 0)
** The s->plane formula: ax + by + cz + d = 0
** a = nx, b = ny, z = nz, d = nx * -px + ny * -py + nz * -pz
** s->camera: c(cx,s->cy,cz), underneath p(px,py,pz) is image pixel point or start ray,
** t is the ray distance
** t = (aCx + bs->cy + cCz + d) / (aCx + bs->cy + cCz - aPx - bPy - cPz)
** Now you can find the intersection point I(Ix,Iy,Iz)
** Ix = (1 - t)*Cx + t*Px
** Iy = (1 - t)*s->cy + t*Py
** Iz = (1 - t)*Cz + t*Pz
*/


/*int ft_plane_intersection(t_ray ray, t_pl o, t_inter *res, t_light s->light)
{
  double a;
  double b;
  double c;
  double d;
  s->light.color.color = 1;

  a = o.norm.x;
  b = o.norm.y;
  c = o.norm.z;
  d = o.norm.x * -o.p.x + o.norm.y * -o.p.y + o.norm.z * -o.p.z;
  res->dis1 = (a * ray.start.x + b * ray.start.y + c * ray.start.z + d) /
   (a * ray.start.x + b * ray.start.y + c * ray.start.z - a * o.p.x - b * o.p.y - c * o.p.z);
  if (res->dis1 != INFINITY)
  {
    res->p.x = (1 - res->dis1) * ray.start.x + res->dis1 * o.p.x;
    res->p.y = (1 - res->dis1) * ray.start.y + res->dis1 * o.p.y;
    res->p.z = (1 - res->dis1) * ray.start.z + res->dis1 * o.p.z;
    return (1);
  }
  return (0);
}

void screen_iterate_s->plane(void)
{
	double x;
	double y;
	t_inter inter;
  t_ray ray;

	x = s->screen_lenght;
	y = s->screen_height;
	while(y)
	{
		while(x)
		{
        ray = ft_create_ray(x, y, 0, cam);
				if (ft_plane_intersection(ray, o, &inter, s->light))
						mlx_pixel_put(mlx_ptr, mlx_win, inter.p.x, inter.p.y, o.c.color);
			x--;
		}
		y--;
		x = s->screen_lenght;
	}
}*/
