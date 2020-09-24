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
#include "raycast/color/color.h"

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
  float intensity;
  int status;
} t_ambient;

typedef struct s_light
{
  t_vec position;
  t_col color;
  float intensity;
  t_ray ray;
  int status;
} t_light;

typedef struct s_intersection
{
  double dis1;
  double dis2;
  t_vec p;
  t_col c;
  double closest_p;
  t_col final;
} t_inter;

typedef struct s_screen
{
  void *mlx_ptr;
  void *mlx_win;
  int resolution_x;
  int resolution_y;
  double resolution_aspect_ratio;
  int status;
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
  float side;
  t_col c;
  int status;
} t_sq;

typedef struct s_object_cy
{
  t_vec p;
  t_vec ndir;
  float r;
  float height;
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

extern t_s *s;

void ft_intersection_color(t_inter *inter, t_col o, t_light l, t_vec n);
t_col ft_cumulative_light_check(t_inter *inter, t_s *s_light, t_col cumu_light);
void screen_iterate(void);
void ft_sphere_intersection(t_ray ray, t_inter *inter, t_sp sp1, t_light li);
t_ray ft_create_ray(double x, double y, double z);
void ft_misconfiguration(void);
void ft_misconfiguration1(void);
void ft_exit(char *error_message);
void ft_exit_no_free(char *error_message);
void free_all(void);
void begin_list(void);
t_s *iter_list_new(int *counter);
void iter_list(void (*function)(void));
int max_cam(void);
int	ft_key(int key);
void ft_key_light(char *keys, int d);
void ft_key_cam(char *keys, int d);
void ft_key_sp(char *keys, int d);
void ft_key_cy(char *keys, int d);
void ft_key_pl(char *keys, int d);
void ft_key_tr(char *keys, int d);
void ft_key_sq(char *keys, int d);
void ft_search_setup(int *i, int *l, char *line);
void ft_setup_resolution(char *line);
void ft_setup_ambient_light(char *line);
void ft_setup_camera(char *line);
void ft_setup_light(char *line);
void ft_setup_sphere(char *line);
void ft_setup_plane(char *line);
void ft_setup_square(char *line);
void ft_setup_cylinder(char *line);
void ft_setup_tr(char *line);
void ft_setup(int fd);
void ft_setup_init(void);
t_s *ft_setup_new(void);

//void screen_iterate_s->plane(void *mlx_ptr, void *mlx_win, t_vec cam, t_pl o, t_light light);
//int ft_plane_intersection(t_ray ray, t_pl o, t_inter *res, t_light light);


#endif
