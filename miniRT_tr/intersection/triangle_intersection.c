#include "../miniRT.h"

#define ERROR_MARG 0.000001

/*
** To calculate triangle intersection we will use bariatric coordinates
** P = aA + bB + yC <> a >=0, b>=0, y>=0 <> a + b + y = 1
** P-A=b(B-A)+y(C-A) by resolving this equation and testing if a + b + y = 1
** barycentric coordinate matrix used
** We can test if point inside triangle
** Because the comp precision is not perfect we use 0.000001 instead of 0
** as an error margin
*/
static int ft_inter_in_tr(t_vec p1, t_vec p2, t_vec p3, t_vec p)
{
	double d;
  double alfa;
	double beta;
	double ceta;

  d = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * ((p1.y - p2.y)));
  if (fabs(d) < ERROR_MARG)
    return (0);
  d = 1 / d;
  alfa = (p.x * (p2.y - p3.y) + p.y * (p3.x - p2.x) + (p2.x * p3.y
        - p3.x * p2.y)) * d;
  beta = (p.x * (p3.y - p1.y) + p.y * (p1.x - p3.x) + (p3.x * p1.y
        - p1.x * p3.y)) * d;
  ceta = (p.x * (p1.y - p2.y) + p.y * (p2.x - p1.x) + (p1.x * p2.y
        - p2.x * p1.y)) * d;
	if (alfa >= 0 && beta >= 0 && ceta >= 0 && alfa + beta + ceta <= 1 + ERROR_MARG)
      return (1);
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
** If the point is inside the triangle an intersection is found
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
    inter->p = ft_vector_add(ray.start,
          ft_vec_doub_multiplication(ray.direc, inter->dis1));
    if (ft_inter_in_tr(s->tr.p1, s->tr.p2, s->tr.p3, inter->p)) //seems to be the error herein
      inter = ft_intersection_color(s, inter, l, s->tr.c);
    else
      inter->dis1 = INFINITY;
  }
  return (inter);
}

/*
** Trying to see if intersection in triangle using barycentric points
** Failed

static int ft_inter_in_tr(t_vec p1, t_vec p2, t_vec p3, t_vec p)
{
  t_vec x;
  t_vec y;
  double alfa;
  double beta;
  double ceta;

  x = ft_vector_substraction(p2, p1);
  y = ft_vector_substraction(p3, p1);
  ceta = (-ft_vector_dot_product(p, ft_vec_doub_substraction(x, 1)) +
        ft_vector_dot_product(p1, ft_vec_doub_substraction(x, 1)))
        / -ft_vector_dot_product(y, ft_vec_doub_substraction(x, 1));
  beta = ft_vector_dot_product(p, x) - (ceta * ft_vector_dot_product(y, x))
        - ft_vector_dot_product(p1, x);
  if (ceta >= 0 && ceta <= 1 && beta >= 0 && beta <= 1)// && beta + teta <= 1)
    return (1);
  else
    return (0);
}*/

/*
** Another technique that worked but gave fizzy images
**
** To calculate if intersction point sits inside triangle ABC with point P
** we calcualte the area of the triangle (area), the area BCP (area1)
** area APC (area2) and area ABP (area3), if the sum of the last three areas
** is equal to the first area an intersection is found
** If result is not perfect using >= instead of == helped, right now round
** function resolved the problem
*/

/*static double create_tr_area(t_vec p1, t_vec p2, t_vec p3)
{
 return (fabs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x *
      (p1.y - p2.y)) / 2.0));
}

static int ft_inter_in_tr(t_vec p1, t_vec p2, t_vec p3, t_vec p)
{
  double area;
  double area1;
  double area2;
  double area3;

  area = round(create_tr_area(p1, p2, p3));
  area1 = round(create_tr_area(p, p2, p3));
  area2 = round(create_tr_area(p1, p, p3));
  area3 = round(create_tr_area(p1, p2, p));
  if (area == area1 + area2 + area3)
    return (1);
  else
    return (0);
}*/
