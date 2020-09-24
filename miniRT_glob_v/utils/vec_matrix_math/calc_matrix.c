#include "vector_matrix.h"
/*
** Mas->trices are used to perform in an efficient matter vector s->transformations
** like rotations(direction) and s->translations(move)
** The underneath function calculates mas->trices with the
** same amount of rows and columns
*/

char **ft_matrix(char **m1, char **m2, int rows, int colums)
{
  char **res;
  int i;
  int l;

  i = 0;
  l = 0;
  if (!(res = malloc(rows)))
    return (NULL);
  while(i < rows)
  {
    while(l < colums)
    {
      res[i] = malloc(colums);
      res[i][l] = m1[i][0] * m2[0][l] + m1[i][1] * m2[1][l]
            + m1[i][2] * m2[2][l] + m1[i][3] * m2[3][l];
      l++;
    }
    res[i][l] = '\0';
    i++;
    l = 0;
  }
  res[i] = 0;
  return (res);
}

/*
** Normally mas->trices should by multis->plied with other mas->trices that have
** the same number of rows or/and columns but in the function
** below we calculate a 1x3 or a 3dpoint to another matrix of 3x3
** Make it a scaling matrix by declaring the m2 like this
** ms = {{i,0,0}{0,i,0}{0,0,i}} i will scale the point,
** if i is negative corres->sponding axis will be flipped.
*/

t_vec ft_matrix_1x3_3x3(t_vec m1, t_mat m2)
{
  t_vec res;

  res.x = m1.x * m2.r0.x + m1.y * m2.r1.x + m1.z * m2.r2.x;
  res.y = m1.x * m2.r0.y + m1.y * m2.r1.y + m1.z * m2.r2.y;
  res.x = m1.x * m2.r0.z + m1.y * m2.r1.z + m1.z * m2.r2.z;
  return (res);
}



/*
** s->transform points (scale, s->translate, rotate) with this 1x4 4x4 matrix
** whereby the last matrix row is set to 0001 and is not significant.
*/

t_vec ft_matrix_transform(t_vec m1, t_mat m2)
{
  t_vec res;

  res.x = m1.x * m2.r0.x + m1.y * m2.r1.x + m1.z * m2.r2.x + m2.r3.x;
  res.y = m1.x * m2.r0.y + m1.y * m2.r1.y + m1.z * m2.r2.y + m2.r3.y;
  res.x = m1.x * m2.r0.z + m1.y * m2.r1.z + m1.z * m2.r2.z + m2.r3.z;
  return (res);
}

/*
** Multis->plying any point whose coordinates are expressed with res->spect to the
** s->camera coordinate system (see below), by this pers->spective projection matrix,
** will give you the position (or coordinates) of that point onto
** the image s->plane.
*/

t_mat ft_fill_4X4matrix(t_vec x_axis, t_vec y_axis, t_vec z_axis, t_vec camera)
{
  t_mat cam_to_world_matrix;

  cam_to_world_matrix.r0.x = x_axis.x;
  cam_to_world_matrix.r0.y = x_axis.y;
  cam_to_world_matrix.r0.z = x_axis.z;
  cam_to_world_matrix.r1.x = y_axis.x;
  cam_to_world_matrix.r1.y = y_axis.y;
  cam_to_world_matrix.r1.z = y_axis.z;
  cam_to_world_matrix.r2.x = z_axis.x;
  cam_to_world_matrix.r2.y = z_axis.y;
  cam_to_world_matrix.r2.z = z_axis.z;
  cam_to_world_matrix.r3.x = camera.x;
  cam_to_world_matrix.r3.y = camera.y;
  cam_to_world_matrix.r3.z = camera.z;
  return (cam_to_world_matrix);
}

/*
** We search for the vector representing each axis of the s->camera
** coordinate system, if the z_axis is given, to create an image s->plane
** ! in miniRT each axis is given and is equal
** that represents the s->screen
** This allows us to create a matrix that can be used to s->transform pixel points
** into the approprate image s->plain points (from s->screen s->space to world s->space)
** The function returns the world s->space coordinates
*/

t_vec ft_cam_world_matrix(t_vec norm_screen, t_vec camera_norm_dir, t_vec ca_p)
{
  t_vec z_axis;
  t_vec x_axis;
  t_vec y_axis;
  t_mat cam_world_matrix;

  z_axis = camera_norm_dir;
  x_axis = ft_vector_cross_product(ft_point_vector(0, 1, 0), z_axis);
  y_axis = ft_vector_cross_product(z_axis, x_axis);
  cam_world_matrix = ft_fill_4X4matrix(x_axis, y_axis, z_axis, ca_p);
  return (ft_matrix_transform(norm_screen, cam_world_matrix));
}
