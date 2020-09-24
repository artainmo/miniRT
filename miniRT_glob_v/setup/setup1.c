#include "../miniRT.h"

/*
** Before malloc we free each time to avoid double malloc, because each object
** should already been malloced during the initilization
*/

void ft_setup_resolution(char *line)
{
  int i;
  int l;

  i = 1;
  s->screen.status  = 1;
  ft_search_setup(&i, &l, line);
  s->screen.resolution_x = ft_atoi(ft_substr(line, 2, 6));
  ft_search_setup(&i, &l, line);
  s->screen.resolution_y = ft_atoi(ft_substr(line, l, i - l));
  s->screen.resolution_aspect_ratio = s->screen.resolution_x / s->screen.resolution_y;
  //+ s->screen.resolution_x % s->screen.resolution_y;//How to calculate this?
}

void ft_setup_ambient_light(char *line)
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
void ft_setup_camera(char *line)
{
  int i;
  int l;
  int counter;

  i = 1;
  counter = 0;
  while(counter < max_cam())
    s = iter_list_new(&counter);
  s->camera.status = counter + 1;
  printf("a:%d\n", s->asked_cam);
  printf("pl:%d\n", s->amb.status);
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
  begin_list();
}
