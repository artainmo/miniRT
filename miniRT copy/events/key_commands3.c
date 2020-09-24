#include "../miniRT.h"

static void ft_key_cy2(t_s *s, char *keys, int d)
{
  if (keys[1] == 'H' && s->cy.status)
  {
    if (keys[2] == 'U')
      s->cy.height += d;
    if (keys[2] == 'D')
      s->cy.height -= d;
  }
  if (keys[1] == 'O' && s->cy.status)
  {
    if (keys[2] == 'R')
      s->cy.ndir.x += 0.1;
    if (keys[2] == 'E')
      s->cy.ndir.x -= 0.1;
    if (keys[2] == 'U')
      s->cy.ndir.y -= 0.1;
    if (keys[2] == 'D')
      s->cy.ndir.y += 0.1;
    if (keys[2] == 'Z')
      s->cy.ndir.z += 0.1;
    if (keys[2] == 'B')
      s->cy.ndir.z -= 0.1;
  }
}

void ft_key_cy(t_s *s, char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'A' && s->cy.status)
  {
    if (keys[2] == 'U')
      s->cy.r += d;
    if (keys[2] == 'D')
      s->cy.r -= d;
  }
  if (keys[1] == 'P' && s->cy.status)
  {
    if (keys[2] == 'R')
      s->cy.p.x += d;
    if (keys[2] == 'E')
      s->cy.p.x -= d;
    if (keys[2] == 'U')
      s->cy.p.y += d;
    if (keys[2] == 'D')
      s->cy.p.y -= d;
    if (keys[2] == 'Z')
      s->cy.p.z += d;
    if (keys[2] == 'B')
      s->cy.p.z -= d;
  }
  ft_key_cy2(s, keys, d);
}

t_s *ft_next_obj(t_s *s, int d)
{
  printf("\n%d\n", d);
  while (d)
  {
    if (!s->next)
      s = s->first;
    else
      s = s->next;
    d--;
  }
  return (s);
}
