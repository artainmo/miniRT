#include "../miniRT.h"

static void ft_key_cy2(char *keys, int d)
{
  if (keys[1] == 'H')
  {
    if (keys[2] == 'U')
      s->cy.height += d;
    if (keys[2] == 'D')
      s->cy.height -= d;
  }
  if (keys[1] == 'O')
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

void ft_key_cy(char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'A')
  {
    if (keys[2] == 'U')
      s->cy.r += d;
    if (keys[2] == 'D')
      s->cy.r -= d;
  }
  if (keys[1] == 'P')
  {
    if (keys[2] == 'R')
      s->cy.p.x += d;
    if (keys[2] == 'E')
      s->cy.p.x -= d;
    if (keys[2] == 'U')
      s->cy.p.y -= d;
    if (keys[2] == 'D')
      s->cy.p.y += d;
    if (keys[2] == 'Z')
      s->cy.p.z += d;
    if (keys[2] == 'B')
      s->cy.p.z -= d;
  }
  ft_key_cy2(keys, d);
}
