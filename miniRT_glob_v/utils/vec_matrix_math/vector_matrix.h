#ifndef VECTOR_MATRIX_H
# define VECTOR_MATRIX_H

#include <stdlib.h>
#include <math.h>

typedef struct s_vector
{
  double x;
  double y;
  double z;
} t_vec;

typedef struct s_matrix
{
  t_vec r0;
  t_vec r1;
  t_vec r2;
  t_vec r3;
} t_mat;

t_vec ft_matrix_transform(t_vec m1, t_mat m2);
t_mat ft_fill_4X4matrix(t_vec x_axis, t_vec y_axis, t_vec z_axis, t_vec camer);
t_vec ft_matrix_1x3_3x3(t_vec m1, t_mat m2);
char **ft_matrix(char **m1, char **m2, int rows, int colums);
t_vec ft_cam_world_matrix(t_vec norm_screen, t_vec camera_norm_dir, t_vec c_p);
t_vec ft_point_vector(double x, double y, double z);
double ft_vector_magnitude(t_vec p0, t_vec p);
t_vec ft_direction_vector(t_vec p0, t_vec p);
t_vec ft_vec_doub_multiplication(t_vec v1, double d);
t_vec ft_vec_doub_substraction(t_vec v1, double d);
t_vec ft_vector_substraction(t_vec v1, t_vec v2);
double ft_vector_dot_product(t_vec v1, t_vec v2);
t_vec ft_vector_cross_product(t_vec v1, t_vec v2);
t_vec ft_vector_add(t_vec v1, t_vec v2);


#endif
