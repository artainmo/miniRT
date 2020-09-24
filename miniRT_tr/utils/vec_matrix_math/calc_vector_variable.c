#include "vector_matrix.h"

t_vec ft_vec_doub_substraction(t_vec v1, double d)
{
  t_vec ret;

  ret.x = v1.x - d;
  ret.y = v1.y - d;
  ret.z = v1.z - d;
  return (ret);
}

t_vec ft_vec_doub_multiplication(t_vec v1, double d)
{
  t_vec ret;

  ret.x = v1.x * d;
  ret.y = v1.y * d;
  ret.z = v1.z * d;
  return (ret);
}

int ft_vec_comp(t_vec v1, t_vec v2)
{
  if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
    return (1);
  else
    return (0);
}
