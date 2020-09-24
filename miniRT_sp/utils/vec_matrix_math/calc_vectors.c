#include "vector_matrix.h"
/*
** Also called the dot or scalar product its symbol is .
** relates to the cosine of the angle between the two vectors
** When the two vectors are pointing in opposite directions (A.C), the dot
** product returns -1. When they are pointing in the exact
** same direction (A.D), it returns 1.
*/

double ft_vector_dot_product(t_vec v1, t_vec v2)
{
  double ret;

  ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  return (ret);
}

/*
** The particularity of the cross product is that the vector resulting from the
** cross product is perpendicular to the other two
** its symbol is X
*/

t_vec ft_vector_cross_product(t_vec v1, t_vec v2)
{
  t_vec ret;

  ret.x = v1.y * v2.z - v1.z * v2.y;
  ret.y = v1.z * v2.x - v1.x * v2.z;
  ret.z = v1.x * v2.y - v1.y * v2.x;
  return (ret);
}

t_vec ft_vector_substraction(t_vec v1, t_vec v2)
{
  t_vec ret;

  ret.x = v1.x - v2.x;
  ret.y = v1.y - v2.y;
  ret.z = v1.z - v2.z;
  return (ret);
}

t_vec ft_vector_add(t_vec v1, t_vec v2)
{
  t_vec ret;

  ret.x = v1.x + v2.x;
  ret.y = v1.y + v2.y;
  ret.z = v1.z + v2.z;
  return (ret);
}
