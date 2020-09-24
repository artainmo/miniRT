#include "../miniRT.h"

/*
** Before malloc we free each time to avoid double malloc, because each object
** should already been malloced during the initilization
*/

void ft_setup_resolution(t_s *s, char *line)
{
  int i;
  int l;

  i = 1;
  s->screen.status  = 1;
  ft_search_setup(&i, &l, line);
  s->screen.res_x = ft_atoi(ft_substr(line, 2, 6));
  ft_search_setup(&i, &l, line);
  s->screen.res_y = ft_atoi(ft_substr(line, l, i - l));
  s->screen.resolution_aspect_ratio = s->screen.res_x / s->screen.res_y;
  //+ s->screen.res_x % s->screen.res_y;//How to calculate this?
  if (s->screen.res_x > MAX_RES_X)
    s->screen.res_x = MAX_RES_X;
  if (s->screen.res_y > MAX_RES_Y)
    s->screen.res_y = MAX_RES_Y;
  if (s->screen.res_x < 1)
    s->screen.res_x = 1;
  if (s->screen.res_y < 1)
    s->screen.res_y = 1;
}

void ft_setup_ambient_light(t_s *s, char *line)
{
  int i;
  int l;

  i = 1;
  s->amb.status  = 1;
  ft_search_setup(&i, &l, line);
  s->amb.intensity = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->amb.color.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->amb.color.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->amb.color.blue = ft_atoi(ft_substr(line, l, i - l));
}

/*
** We convert the FOV from degrees to radians
*/
void ft_setup_camera(t_s *s, char *line)
{
  int i;
  int l;
  int counter;

  i = 1;
  counter = 0;
  while(counter < max_cam(s))
    s = iter_list_new(s, &counter);
  s->camera.status = counter + 1;
  ft_search_setup(&i, &l, line);
  s->camera.p.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->camera.p.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->camera.p.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->camera.ndir.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->camera.ndir.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->camera.ndir.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->camera.h_FOV = ft_atof(ft_substr(line, l, i - l)) * 0.0174533;
  s = begin_list(s);
}
