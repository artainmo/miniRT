#include "../miniRT.h"


int plane_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
  inter->shadow.n = s->pl.ndir;
  inter->shadow.dis1 = (ft_vector_dot_product(s->pl.p, inter->shadow.n)
        - ft_vector_dot_product(ray.start, inter->shadow.n))
              / ft_vector_dot_product(ray.direc, inter->shadow.n);
  if (inter->shadow.dis1 != INFINITY && inter->shadow.dis1 < 0)
    return (1);
  return (0);
}

/*
** plane intersection calculate
** A point on plane p(px,py,pz) is given with a normalized vector n[nx,ny,nz]
** normalized vector (means perpendicular / vector_n * vector_a = 0)
** To calculate plane intersection
** dis = (tr.p1 * tr.n - ray.start * n) / (ray.direc * n)
*/


t_inter *ft_plane_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
  inter->id.object = 'p';
	inter->id.number = s->pl.status;
  inter->n = s->pl.ndir;
  inter->dis1 = (ft_vector_dot_product(s->pl.p, inter->n)
        - ft_vector_dot_product(ray.start, inter->n))
              / ft_vector_dot_product(ray.direc, inter->n);
  if (inter->dis1 != INFINITY)
  {
    inter->p = ft_vector_add(ray.start,
          ft_vec_doub_multiplication(ray.direc, inter->dis1));
    inter = ft_intersection_color(s, inter, l, s->pl.c);
  }
  return (inter);
}

/*int plane_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
  double a;
  double b;
  double c;
  double d;

  a = s->pl.ndir.x;
  b = s->pl.ndir.y;
  c = s->pl.ndir.z;
  d = s->pl.ndir.x * -s->pl.p.x + s->pl.ndir.y * -s->pl.p.y + s->pl.ndir.z
        * -s->pl.p.z;
  inter->dis1 = (a * ray.start.x + b * ray.start.y + c * ray.start.z + d) /
   (a * ray.start.x + b * ray.start.y + c * ray.start.z
          - a * s->pl.p.x - b * s->pl.p.y - c * s->pl.p.z);
  if (inter->dis1 != INFINITY)
  {
    if (inter->dis1 >= 0)
			return (0);
    return (1);
  }
  else
    return (0);
}


** plane intersection calculate
** A point on plane p(px,py,pz) is given with a normalized vector n[nx,ny,nz]
** normalized vector (means perpendicular / vector_n * vector_a = 0)
** The plane formula: ax + by + cz + d = 0
** a = nx, b = ny, z = nz, d = nx * -px + ny * -py + nz * -pz
** camera: c(cx,s->cy,cz), underneath p(px,py,pz) is image pixel point or start ray,
** t is the ray distance
** t = (aCx + bs->cy + cCz + d) / (aCx + bcy + cCz - aPx - bPy - cPz)
** Now you can find the intersection point I(Ix,Iy,Iz)
** Ix = (1 - t)*Cx + t*Px
** Iy = (1 - t)*cy + t*Py
** Iz = (1 - t)*Cz + t*Pz
** Normal vector is already given or could be calculated with crossproduct



t_inter *ft_plane_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
  double a;
  double b;
  double c;
  double d;

  inter->id.object = 'p';
  inter->id.number = s->pl.status;
  a = s->pl.ndir.x;
  b = s->pl.ndir.y;
  c = s->pl.ndir.z;
  d = s->pl.ndir.x * -s->pl.p.x + s->pl.ndir.y * -s->pl.p.y + s->pl.ndir.z
        * -s->pl.p.z;
  inter->dis1 = (a * ray.start.x + b * ray.start.y + c * ray.start.z + d) /
   (a * ray.start.x + b * ray.start.y + c * ray.start.z
          - a * s->pl.p.x - b * s->pl.p.y - c * s->pl.p.z);
  if (inter->dis1 != INFINITY)
  {
    inter->p.x = (1 - inter->dis1) * ray.start.x + inter->dis1 * s->pl.p.x;
    inter->p.y = (1 - inter->dis1) * ray.start.y + inter->dis1 * s->pl.p.y;
    inter->p.z = (1 - inter->dis1) * ray.start.z + inter->dis1 * s->pl.p.z;
    inter->n = s->pl.ndir;
    inter = ft_intersection_color(s, inter, l, s->pl.c);
  }
  return (inter);
}*/
