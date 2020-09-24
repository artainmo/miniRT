#include "../miniRT.h"

t_s *ft_setup_new(void)
{
  t_s *new;

  if (!(new = malloc(sizeof(t_s))))
    ft_exit_no_free("ERROR\nFailed malloc\n");
  new->screen = s->screen;
  new->amb = s->amb;
  new->camera.status = 0;
  new->light.status = 0;
  new->sp.status = 0;
  new->pl.status = 0;
  new->sq.status = 0;
  new->cy.status = 0;
  new->tr.status = 0;
  new->next = NULL;
  new->first = s->first;
  return (new);
}

void ft_setup_init(void)
{
  if (!(s = malloc(sizeof(t_s))))
    ft_exit_no_free("ERROR\nFailed malloc\n");
  s->screen.status = 0;
  s->light.status = 0;
  s->camera.status = 0;
  s->sp.status = 0;
  s->pl.status = 0;
  s->sq.status = 0;
  s->cy.status = 0;
  s->tr.status = 0;
  s->amb.status = 0;
  s->amb.color = ft_set_color(0, 0, 0);
  s->asked_cam = 1;
  s->next = NULL;
  s->first = s;
}
