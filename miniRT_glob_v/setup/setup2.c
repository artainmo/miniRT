#include "../miniRT.h"

static void ft_setup_plane2(char *line, int i, int l)
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
  begin_list();
}

void ft_setup_plane(char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 1;
  s->pl.status++;
  while(counter < s->pl.status)
    iter_list_new(&counter);
  s->pl.status = counter;
  ft_search_setup(&i, &l, line);
  s->pl.p.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.p.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->pl.p.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  ft_setup_plane2(line, i, l);
}

static void ft_setup_square2(char *line, int i, int l)
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
  begin_list();
}

void ft_setup_square(char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 1;
  s->sq.status++;
  while(counter < s->sq.status)
    iter_list_new(&counter);
  s->sq.status = counter;
  ft_search_setup(&i, &l, line);
  s->sq.p.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.p.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->sq.p.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  ft_setup_square2(line, i, l);
}
