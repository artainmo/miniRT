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
