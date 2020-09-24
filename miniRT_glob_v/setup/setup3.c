#include "../miniRT.h"

static void ft_setup_cylinder2(char *line, int i, int l)
{
  s->cy.ndir.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.ndir.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.ndir.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.r = (ft_atof(ft_substr(line, l, i - l)))/2;
  ft_search_setup(&i, &l, line);
  s->cy.height = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.c.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.c.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.c.blue = ft_atoi(ft_substr(line, l, i - l));
  s->cy.c.color = ft_get_color(s->cy.c);
  begin_list();
}

void ft_setup_cylinder(char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 1;
  s->cy.status++;
  while(counter < s->cy.status)
    iter_list_new(&counter);
  s->cy.status = counter;
  ft_search_setup(&i, &l, line);
  s->cy.p.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.p.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->cy.p.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  ft_setup_cylinder2(line, i, l);
}

static void ft_setup_tr2(char *line, int i, int l)
{
  s->tr.p2.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p2.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p2.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p3.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p3.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p3.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.c.red = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.c.green = ft_atoi(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.c.blue = ft_atoi(ft_substr(line, l, i - l));
  s->tr.c.color = ft_get_color(s->tr.c);
  begin_list();
}

void ft_setup_tr(char *line)
{
  int i;
  int l;
  int counter;

  i = 2;
  counter = 1;
  s->tr.status++;
  while(counter < s->tr.status)
    iter_list_new(&counter);
  s->tr.status = counter;
  ft_search_setup(&i, &l, line);
  s->tr.p1.x = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p1.y = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  s->tr.p1.z = ft_atof(ft_substr(line, l, i - l));
  ft_search_setup(&i, &l, line);
  ft_setup_tr2(line, i, l);
}
