#include "../miniRT.h"

static void ft_key_tr2(t_s *s, char *keys, int d)
{
  if (keys[2] == 'D')
  {
    s->tr.p1.y -= d;
    s->tr.p2.y -= d;
    s->tr.p3.y -= d;
  }
  if (keys[2] == 'Z')
  {
    s->tr.p1.z += d;
    s->tr.p2.z += d;
    s->tr.p3.z += d;
  }
  if (keys[2] == 'B')
  {
    s->tr.p1.z -= d;
    s->tr.p2.z -= d;
    s->tr.p3.z -= d;
  }
}

void ft_key_tr(t_s *s, char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'P' && s->tr.status)
  {
    if (keys[2] == 'R')
    {
      s->tr.p1.x += d;
      s->tr.p2.x += d;
      s->tr.p3.x += d;
    }
    if (keys[2] == 'E')
    {
      s->tr.p1.x -= d;
      s->tr.p2.x -= d;
      s->tr.p3.x -= d;
    }
    if (keys[2] == 'U')
    {
      s->tr.p1.y += d;
      s->tr.p2.y += d;
      s->tr.p3.y += d;
    }
    ft_key_tr2(s, keys, d);
  }
}

static void ft_key_pl2(t_s *s, char *keys, int d)
{
  if (keys[1] == 'P' && s->pl.status)
  {
    if (keys[2] == 'R')
      s->pl.p.x += d;
    if (keys[2] == 'E')
      s->pl.p.x -= d;
    if (keys[2] == 'U')
      s->pl.p.y += d;
    if (keys[2] == 'D')
      s->pl.p.y -= d;
    if (keys[2] == 'Z')
      s->pl.p.z += d;
    if (keys[2] == 'B')
      s->pl.p.z -= d;
  }
}

void ft_key_pl(t_s *s, char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'O' && s->pl.status)
  {
    if (keys[2] == 'R')
      s->pl.ndir.x += 0.1;
    if (keys[2] == 'E')
      s->pl.ndir.x -= 0.1;
    if (keys[2] == 'U')
      s->pl.ndir.y -= 0.1;
    if (keys[2] == 'D')
      s->pl.ndir.y += 0.1;
    if (keys[2] == 'Z')
      s->pl.ndir.z += 0.1;
    if (keys[2] == 'B')
      s->pl.ndir.z -= 0.1;
  }
  ft_key_pl2(s, keys, d);
}

void ft_key_sp(t_s *s, char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'A' && s->sp.status)
  {
	   if (keys[2] == 'U')
		   s->sp.r += d;
	   if (keys[2] == 'D')
		   s->sp.r -= d;
  }
  if (keys[1] == 'P' && s->sp.status)
  {
       if (keys[2] == 'R')
		     s->sp.centrum.x += d;
       if (keys[2] == 'E')
		     s->sp.centrum.x -= d;
       if (keys[2] == 'U')
		     s->sp.centrum.y += d;
       if (keys[2] == 'D')
		     s->sp.centrum.y -= d;
       if (keys[2] == 'Z')
		     s->sp.centrum.z += d;
       if (keys[2] == 'B')
		     s->sp.centrum.z -= d;
  }
}
