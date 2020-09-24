#include "../miniRT.h"

/*
** See if plane intersection is inside the disk
*/
static int ft_inter_in_disk(t_vec centrum, double r, t_vec p)
{
  double distance;

  distance = fabs(ft_vector_magnitude(p, centrum));
  if (distance <= r + ERROR_MARG)
    return (1);
  else
    return (0);
}

static int ft_cyl_boolean(t_s *s, t_shadow inter, t_ray ray, t_vec centrum)
{
  inter.dis1 = (ft_vector_dot_product(centrum, inter.n)
        - ft_vector_dot_product(ray.start, inter.n))
              / ft_vector_dot_product(ray.direc, inter.n);
  if (inter.dis1 != INFINITY)
  {
    inter.p = ft_vector_add(ray.start,
          ft_vec_doub_multiplication(ray.direc, inter.dis1));
    if (ft_inter_in_disk(centrum, s->cy.r, inter.p))
      return (1);
    else
      inter.dis1 = INFINITY;
  }
  return (0);
}

int cylinder_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
  t_vec centrum;
  int i;

  inter->shadow.n = s->cy.ndir;
  i = 0;
  centrum = s->cy.p;
  while(i <= s->cy.height)
  {
    centrum = ft_vec_move(s->cy.p, s->cy.ndir, i);
    if (ft_cyl_boolean(s, inter->shadow, ray, centrum))
      return (1);
    i++;
  }
  return (0);
}

/*
** See if ray intersects with disk plane
*/

static int ft_cyl_inter(t_s *s, t_inter *inter, t_ray ray, t_vec centrum)
{
  inter->dis1 = (ft_vector_dot_product(centrum, inter->n)
        - ft_vector_dot_product(ray.start, inter->n))
              / ft_vector_dot_product(ray.direc, inter->n);
  if (inter->dis1 != INFINITY)
  {
    inter->p = ft_vector_add(ray.start,
          ft_vec_doub_multiplication(ray.direc, inter->dis1));
    if (ft_inter_in_disk(centrum, s->cy.r, inter->p))
      return (1);
    else
      inter->dis1 = INFINITY;
  }
  return (0);
}

/*
** lowest centrum point, norm direction vector for each axis, diameter and
** height are all given.
** Iterate on each disk inside the cylinder, calculate if intersects with disk
*/
t_inter *ft_cylinder_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
  t_vec centrum;
  int i;

  inter->id.object = 'c';
	inter->id.number = s->cy.status;
  inter->n = s->cy.ndir;
  i = 0;
  centrum = s->cy.p;
  while(i <= s->cy.height)
  {
    centrum = ft_vec_move(s->cy.p, s->cy.ndir, i);
    if (ft_cyl_inter(s, inter, ray, centrum))
    {
      if (i == 0)
        inter->n = ft_vector_mult(s->cy.ndir, ft_point_vector(-1, -1, -1));
      else if (i == s->cy.height)
        inter->n = s->cy.ndir;
      else
        inter->n = ft_direction_vector(centrum, inter->p);
      inter = ft_intersection_color(s, inter, l, s->cy.c);
      break;
    }
    i++;
  }
  return (inter);
}

/*
** Finds the closest intersection between two lines returns 1 if the distance
** is smaller than or equal to the sphere radius.

static int ft_line_dist(t_s *s, t_ray ray)
{
  double distance;
  t_vec perpendicular;

  perpendicular = ft_vector_cross_product(ray.direc, s->cy.ndir);
  distance = fabs(ft_vector_dot_product(perpendicular, ft_vector_substraction(ray.start, s->cy.p)) / ft_magnitude(perpendicular));
  if (distance <= s->cy.r)
    return (1);
  else
    return (0);
}

int cylinder_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
  return (0);
}

** lowest centrum point, norm direction vector for each axis, diameter and
** height are all given.
**

t_inter *ft_cylinder_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
  inter->id.object = 'c';
	inter->id.number = s->cy.status;
  inter->n = s->cy.ndir;
  if (ft_line_dist(s, ray))
  {
      //inter->n = s->cy.ndir;
      //inter->dis1 =
      //inter->p = ft_vector_add(ray.start,
  			//ft_vec_doub_multiplication(ray.direc, inter->dis1));
      inter->c = ft_set_color(0,255,0);//inter = ft_intersection_color(s, inter, l, s->cy.c);
  }
  return (inter);
}
*/
