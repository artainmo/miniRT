#include "../miniRT.h"

/*
** FILE RULES TO BE READABLE
** Always have a \n as file end
*/
void ft_search_setup(int *i, int *l, char *line)
{
  while (!(line[*i] >= '0' && line[*i] <= '9') && line[*i] != '-')
      *i = *i + 1;
  *l = *i;
  while ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '.'
        || line[*i] == '-')
    *i = *i + 1;
}

static void ft_find_setup(char *line)
{
  if (line[0] == 'R')
    ft_setup_resolution(line);
  if (line[0] == 'A')
    ft_setup_ambient_light(line);
  if (line[0] == 'c' && line[1] != 'y')
    ft_setup_camera(line);
  if (line[0] == 'l')
    ft_setup_light(line);
  if (line[0] == 's' && line[1] == 'p')
    ft_setup_sphere(line);
  if (line[0] == 'p' && line[1] == 'l')
    ft_setup_plane(line);
  if (line[0] == 's' && line[1] == 'q')
    ft_setup_square(line);
  if (line[0] == 'c' && line[1] == 'y')
    ft_setup_cylinder(line);
  if (line[0] == 't' && line[1] == 'r')
    ft_setup_tr(line);
}

void ft_setup(int fd)
{
  int ret;
  char *line;
  ft_setup_init();
  while((ret = get_next_line(fd, &line)))
  {
    if (ret < 0)
      ft_exit_no_free("ERROR\nProblem with file reading");
    ft_find_setup(line);
    free(line);
  }
  ft_find_setup(line);
  free(line);
  close(fd);
  ft_misconfiguration();
}

/*
resolution_x = 700;
resolution_y = 700;

s->sp.centrum = ft_point_vector(0,0,550);
s->sp.r = 350/2;
s->sp.c.red = 10;
s->sp.c.green = 0;
s->sp.c.blue = 200;
s->sp.c.color = ft_get_color(s->sp.c);

s->pl.p = ft_point_vector(100,100,100);
s->pl.norm = ft_point_vector(0,0,1);
s->pl.c.red = 10;
s->pl.c.green = 0;
s->pl.c.blue = 200;
s->pl.c.color = ft_get_color(s->pl.c);

s->camera.p = ft_point_vector(0, 0, 20.6);
s->camera.ndir = ft_point_vector(0, 0, 1);
s->camera.h_FOV = 70;

s->sp.centrum = ft_point_vector(700,100,-500);
s->light.intensity = 0.8;
s->light.color.red = 255;
s->light.color.green = 255;
s->light.color.blue = 255;
s->light.color.color = ft_get_color(s->light.color);
s->ambintensity = 0.1;
s->ambcolor.red = 255;
s->ambcolor.green = 255;
s->ambcolor.blue = 255;
s->ambcolor.color = ft_get_color(s->ambcolor);
*/
