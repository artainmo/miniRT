#include "../miniRT.h"

static void ft_setup_plane2(t_s *s, char *line, int i, int l)
{
  s->pl.ndir.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.ndir.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.ndir.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.c.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.c.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.c.blue = ft_atoi(ft_substr(line, l, i - l));
  s->pl.c.color = ft_get_color(s->pl.c);
  s = begin_list(s);
}

void ft_setup_plane(t_s *s, char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 0;
  while(counter < max_pl(s))
    s = iter_list_new(s, &counter);
  s->pl.status = counter + 1;
  ft_search_setup(&i, &l, line);
  s->pl.p.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.p.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.p.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  ft_setup_plane2(s, line, i, l);
}

static void ft_setup_square2(t_s *s, char *line, int i, int l)
{
  s->sq.ndir.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.ndir.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.ndir.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.side = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.c.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.c.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.c.blue = ft_atoi(ft_substr(line, l, i - l));
  s->sq.c.color = ft_get_color(s->sq.c);
  s = begin_list(s);
}

void ft_setup_square(t_s *s, char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 0;
  while(counter < max_sq(s))
    s = iter_list_new(s, &counter);
  s->sq.status = counter + 1;
  ft_search_setup(&i, &l, line);
  s->sq.p.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.p.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.p.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  ft_setup_square2(s, line, i, l);
}
