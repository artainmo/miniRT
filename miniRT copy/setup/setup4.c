#include "../miniRT.h"

static void ft_setup_light2(t_s *s, char *line, int i, int l)
{
  ft_search_setup(&i, &l, line);
  s->light.intensity = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->light.color.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->light.color.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->light.color.blue = ft_atoi(ft_substr(line, l, i - l));
  s->light.color.color = ft_get_color(s->light.color);
  s = begin_list(s);
}

void ft_setup_light(t_s *s, char *line)
{
  int i;
  int l;
  int counter;

  i = 1;
  counter = 0;
  while(counter < max_light(s))
    s = iter_list_new(s, &counter);
  s->light.status = counter + 1;
  ft_search_setup(&i, &l, line);
  s->light.position.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->light.position.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->light.position.z = ft_atof(ft_substr(line, l, i - l));
  ft_setup_light2(s, line, i, l);
}

static void ft_setup_sphere2(t_s *s, char *line, int l, int i)
{
  ft_search_setup(&i, &l, line);
  s->sp.r = (ft_atof(ft_substr(line, l, i - l)))/2;
  ft_search_setup(&i, &l, line);
  s->sp.c.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sp.c.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sp.c.blue = ft_atoi(ft_substr(line, l, i - l));
  s->sp.c.color = ft_get_color(s->sp.c);
  s = begin_list(s);
}

void ft_setup_sphere(t_s *s, char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 0;
  while(counter < max_sp(s))
    s = iter_list_new(s, &counter);
  s->sp.status = counter + 1;
  ft_search_setup(&i, &l, line);
  s->sp.centrum.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sp.centrum.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sp.centrum.z = ft_atof(ft_substr(line, l, i - l));
  ft_setup_sphere2(s, line, l , i);
}
