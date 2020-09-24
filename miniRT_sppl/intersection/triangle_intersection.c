#include "../miniRT.h"

static int ft_inter_in_tr(t_vec p1, t_vec p2, t_vec p3, t_vec p)
{
  t_vec x;
  t_vec y;
  double alfa;
  double beta;
  double teta;

  x = ft_vector_substraction(p2, p1);
  y = ft_vector_substraction(p3, p1);
  teta = (ft_vector_dot_product(p, ft_vec_doub_substraction(x, 1)) +
        ft_vector_dot_product(p1, ft_vec_doub_substraction(x, 1)))
        / ft_vector_dot_product(y, ft_vec_doub_substraction(x, 1));
  beta = ft_vector_dot_product(p, x) - (teta * ft_vector_dot_product(y, x))
        - ft_vector_dot_product(p1, x);
  if (teta >= 0 && teta <= 1 && beta >= 0 && beta <= 1 && beta + teta <= 1)
    return (1);
  else
    return (0);
}

/*
** Only used for shadowing
*/
int triangle_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
  inter->shadow.n = ft_vector_cross_product(ft_direction_vector(s->tr.p1, s->tr.p2),
        ft_direction_vector(s->tr.p1, s->tr.p3));
  inter->shadow.dis1 = (ft_vector_dot_product(s->tr.p1, inter->shadow.n)
        - ft_vector_dot_product(ray.start, inter->shadow.n))
              / ft_vector_dot_product(ray.direc, inter->shadow.n);
  if (inter->shadow.dis1 != INFINITY)
  {
    if (inter->shadow.dis1 >= 0)
			return (0);
    inter->shadow.p = ft_vector_add(ray.start,
          ft_vec_doub_multiplication(ray.direc, inter->shadow.dis1));
    return (ft_inter_in_tr(s->tr.p1, s->tr.p2, s->tr.p3, inter->shadow.p));
  }
  return (0);
}

/*
** The three points of the triangle are given.
** First calculate if intersects with triangle plane, than test
** if inside the triangle.
**
** To calculate normal take crossproduct of direction vectors between the points.
**
** To calculate plane intersection
** dis = (tr.p1 * tr.n - ray.start * n) / (ray.direc * n)
**
** To calculate triangle intersection we will use bariatric coordinates
** P = aA + bB + yC <> a >=0, b>=0, y>=0 <> a + b + y = 1
** P-A=b(B-A)+y(C-A) by resolving this equation and testing if a + b + y = 1
** We can test if point inside triangle
*/
t_inter *ft_triangle_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
  inter->id.object = 't';
	inter->id.number = s->tr.status;
  inter->n = ft_vector_cross_product(ft_direction_vector(s->tr.p1, s->tr.p2),
        ft_direction_vector(s->tr.p1, s->tr.p3));
  inter->dis1 = (ft_vector_dot_product(s->tr.p1, inter->n)
        - ft_vector_dot_product(ray.start, inter->n))
              / ft_vector_dot_product(ray.direc, inter->n);
  if (inter->dis1 != INFINITY)
  {
    write(1,"f",1);
    inter->p = ft_vector_add(ray.start,
          ft_vec_doub_multiplication(ray.direc, inter->dis1));
    if (ft_inter_in_tr(s->tr.p1, s->tr.p2, s->tr.p3, inter->p)) //seems to be the error herein
      inter = ft_intersection_color(s, inter, l, s->tr.c);
    else
      inter->dis1 = INFINITY;
  }
  return (inter);
}
