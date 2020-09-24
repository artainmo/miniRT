/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:50:40 by artainmo          #+#    #+#             */
/*   Updated: 2019/12/17 17:30:02 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include "utils/minilibX/mlx.h"
#include "utils/libft/libft.h"
#include "utils/vec_matrix_math/vector_matrix.h"
#include "utils/get_next_line/get_next_line.h"
#include "utils/color/color.h"

# ifndef MAX_RES_X
#  define MAX_RES_X 900
# endif

# ifndef MAX_RES_Y
#  define MAX_RES_Y 900
# endif

# ifndef BMP_HEADER_SIZE
#  define BMP_HEADER_SIZE 54
# endif

# ifndef BACKGROUND_R
#  define BACKGROUND_R 20
# endif

# ifndef BACKGROUND_G
#  define BACKGROUND_G 20
# endif

# ifndef BACKGROUND_B
#  define BACKGROUND_B 20
# endif

#define ERROR_MARG 0.000001
#define KEYCODE_Q 12
#define KEYCODE_W 13
#define KEYCODE_E 14
#define KEYCODE_R 15
#define KEYCODE_T 17
#define KEYCODE_Y 16
#define KEYCODE_U 32
#define KEYCODE_I 34
#define KEYCODE_O 31
#define KEYCODE_P 35
#define KEYCODE_A 0
#define KEYCODE_S 1
#define KEYCODE_D 2
#define KEYCODE_F 3
#define KEYCODE_G 5
#define KEYCODE_H 4
#define KEYCODE_J 38
#define KEYCODE_K 40
#define KEYCODE_L 37
#define KEYCODE_Z 6
#define KEYCODE_X 7
#define KEYCODE_C 8
#define KEYCODE_V 9
#define KEYCODE_B 11
#define KEYCODE_N 45
#define KEYCODE_M 46
#define KEYCODE_0 29
#define KEYCODE_1 18
#define KEYCODE_2 19
#define KEYCODE_3 20
#define KEYCODE_4 21
#define KEYCODE_5 23
#define KEYCODE_6 22
#define KEYCODE_7 26
#define KEYCODE_8 28
#define KEYCODE_9 25
#define KEYCODE_AU 126
#define KEYCODE_AD 125
#define KEYCODE_AL 123
#define KEYCODE_AR 124
#define KEYCODE_DASH 36
#define KEYCODE_ESC 53
#define RIGHT_CLICK 1
#define LEFT_CLICK 2

/*
** Double is used instead of float to increase caluclation precision
** and minimize caluclation deviations.
*/

typedef struct s_ray
{
  t_vec start;
  t_vec direc;
} t_ray;

typedef struct s_ray_cam
{
  t_vec p;
  t_vec ndir;
  double h_FOV;
  int status;
} t_cam;

typedef struct s_ambient
{
  t_col color;
  double intensity;
  int status;
} t_ambient;

typedef struct s_light
{
  t_vec position;
  t_col color;
  double intensity;
  t_ray ray;
  int status;
} t_light;

typedef struct s_screen
{
  void *mlx_ptr;
  void *mlx_win;
  void *mlx_image;
  char *data;
  int		bpp;
	int		size_line;
	int		endian;
  int res_x;
  int res_y;
  double resolution_aspect_ratio;
  int status;
  int window_status;
} t_screen;

typedef struct s_object_sp
{
  t_vec centrum;
  double r;
  t_col c;
  int status;
} t_sp;

typedef struct s_object_pl
{
  t_vec p;
  t_vec ndir;
  t_col c;
  int status;
} t_pl;

typedef struct s_object_sq
{
  t_vec p;
  t_vec ndir;
  double side;
  t_col c;
  int status;
} t_sq;

typedef struct s_object_cy
{
  t_vec p;
  t_vec ndir;
  double r;
  double height;
  t_col c;
  int status;
} t_cy;

typedef struct s_object_tr
{
  t_vec p1;
  t_vec p2;
  t_vec p3;
  t_col c;
  int status;
} t_tr;

typedef struct s_identification
{
  char object;
  int number;
} t_id;

typedef struct s_shadow_inter
{
  double dis1;
  double dis2;
  t_vec p;
  t_vec n;
} s_shadow;

typedef struct s_intersection
{
  double dis1;
  double dis2;
  t_vec p;
  t_vec n;
  t_col c;
  double closest_p;
  t_col final;
  t_id id;
  s_shadow shadow;
} t_inter;

typedef struct s_global_struct
{
  t_screen screen;
  t_light light;
  t_cam camera;
  t_sp sp;
  t_pl pl;
  t_sq sq;
  t_cy cy;
  t_tr tr;
  t_ambient amb;
  struct s_global_struct *next;
  struct s_global_struct *first;
  int asked_cam;
} t_s;

void create_window(t_s *s);
t_s *screen_iterate(t_s *s);
t_col ft_cumulative_light_check(t_s *s, t_inter *inter, t_s *s_l, t_col cum);
t_inter *ft_set_new_closest_intersection(t_ray ray, t_inter *inter);
t_inter *ft_intersection_color(t_s *s, t_inter *inter, t_light l, t_col o_c);
t_inter *ft_shadows(t_s *s, t_inter *inter, t_light l);
t_inter *ft_sphere_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l);
t_inter *ft_plane_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l);
t_inter *ft_square_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l);
t_inter *ft_triangle_intersection(t_s *s, t_inter *inter, t_ray ra, t_light l);
int ft_inter_in_tr(t_vec p1, t_vec p2, t_vec p3, t_vec p);
t_inter *ft_cylinder_intersection(t_s *s, t_inter *inter, t_ray ra, t_light l);
int sphere_intersection_boolean(t_s *s, t_ray ray, t_inter *inter);
int plane_intersection_boolean(t_s *s, t_ray ray, t_inter *inter);
int square_intersection_boolean(t_s *s, t_ray ray, t_inter *inter);
int triangle_intersection_boolean(t_s *s, t_ray ray, t_inter *inter);
int cylinder_intersection_boolean(t_s *s, t_ray ray, t_inter *inter);
t_ray ft_create_ray(t_s *s, double x, double y, double z);
t_ray ft_get_ray(t_vec start_point, t_vec direction);
void ft_misconfiguration(t_s *s);
void ft_misconfiguration1(t_s *s);
void ft_exit(t_s *s, char *error_message);
void ft_exit_no_free(char *error_message);
void free_all(t_s *s);
t_s *create_image(t_s *s, t_inter *inter, int x, int y);
void ft_next_image(t_s *s);
char *bmp_filename(t_s *s, char *filename);
void create_bmp(t_s *s, char *filename);
t_s * begin_list(t_s *s);
t_s *iter_list_new(t_s *s, int *counter);
int max_cam(t_s *s);
int max_light(t_s *s);
int max_sp(t_s *s);
int max_pl(t_s *s);
int max_sq(t_s *s);
int max_cy(t_s *s);
int max_tr(t_s *s);
int ft_key(int key, t_s *s);
int ft_mouse(int button,int x,int y, t_s *s);
void ft_key_light(t_s *s, char *keys, int d);
void ft_key_cam(t_s *s, char *keys, int d);
void ft_key_sp(t_s *s, char *keys, int d);
void ft_key_cy(t_s *s, char *keys, int d);
void ft_key_pl(t_s *s, char *keys, int d);
void ft_key_tr(t_s *s, char *keys, int d);
void ft_key_sq(t_s *s, char *keys, int d);
t_s *ft_next_obj(t_s *s, char *keys, int d);
void ft_search_setup(int *i, int *l, char *line);
void ft_setup_resolution(t_s *s, char *line);
void ft_setup_ambient_light(t_s *s, char *line);
void ft_setup_camera(t_s *s, char *line);
void ft_setup_light(t_s *s, char *line);
void ft_setup_sphere(t_s *s, char *line);
void ft_setup_plane(t_s *s, char *line);
void ft_setup_square(t_s *s, char *line);
void ft_setup_cylinder(t_s *s, char *line);
void ft_setup_tr(t_s *s, char *line);
t_s *ft_setup(t_s *s, int fd);
t_s *ft_setup_init(t_s *s);
t_s *ft_setup_new(t_s *s);


//void screen_iterate_s->plane(void *mlx_ptr, void *mlx_win, t_vec cam, t_pl o, t_light light);
//int ft_plane_intersection(t_ray ray, t_pl o, t_inter *res, t_light light);


#endif
