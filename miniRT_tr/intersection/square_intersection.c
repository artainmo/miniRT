#include "../miniRT.h"


int square_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
  return (0);
}


/*
** Square center, norm vector each axis and side size are given to calculate
** a square in world space.
*/

t_inter *ft_square_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{

  inter->id.object = 'q';
	inter->id.number = s->sq.status;
  return (inter);
}
