#include "../miniRT.h"

void ft_key_light(char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'I')
  {
	   if (keys[2] == 'U')
		   s->light.intensity += 0.1;
	   if (keys[2] == 'D')
		   s->light.intensity -= 0.1;
  }
  if (keys[1] == 'P')
  {
       if (keys[2] == 'R')
		     s->light.position.x += d;
       if (keys[2] == 'E')
		     s->light.position.x -= d;
       if (keys[2] == 'U')
		     s->light.position.y -= d;
       if (keys[2] == 'D')
		     s->light.position.y += d;
       if (keys[2] == 'Z')
		     s->light.position.z += d;
       if (keys[2] == 'B')
		     s->light.position.z -= d;
  }
}

static void ft_key_cam2(char *keys, int d)
{
  if (keys[1] == 'P')
  {
    if (keys[2] == 'R')
      s->camera.p.x += d;
    if (keys[2] == 'E')
      s->camera.p.x -= d;
    if (keys[2] == 'U')
      s->camera.p.y -= d;
    if (keys[2] == 'D')
      s->camera.p.y += d;
    if (keys[2] == 'Z')
      s->camera.p.z += d;
    if (keys[2] == 'B')
      s->camera.p.z -= d;
  }
  if (keys[1] == 'N')
  {
    if (keys[2] == 'U')
      s->asked_cam += 1;
    if (keys[2] == 'D')
      s->asked_cam -= 1;
  }
}

void ft_key_cam(char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'O')
  {
    if (keys[2] == 'R')
      s->camera.ndir.x += 0.1;
    if (keys[2] == 'E')
      s->camera.ndir.x -= 0.1;
    if (keys[2] == 'U')
      s->camera.ndir.y -= 0.1;
    if (keys[2] == 'D')
      s->camera.ndir.y += 0.1;
    if (keys[2] == 'Z')
      s->camera.ndir.z += 0.1;
    if (keys[2] == 'B')
      s->camera.ndir.z -= 0.1;
  }
  ft_key_cam2(keys, d);
}

static void ft_key_sq2(char *keys, int d)
{
  if (keys[1] == 'P')
  {
    if (keys[2] == 'R')
      s->sq.p.x += d;
    if (keys[2] == 'E')
      s->sq.p.x -= d;
    if (keys[2] == 'U')
      s->sq.p.y -= d;
    if (keys[2] == 'D')
      s->sq.p.y += d;
    if (keys[2] == 'Z')
      s->sq.p.z += d;
    if (keys[2] == 'B')
      s->sq.p.z -= d;
  }
  if (keys[1] == 'A')
  {
	   if (keys[2] == 'U')
		   s->sq.side += d;
	   if (keys[2] == 'D')
		   s->sq.side -= d;
  }
}

void ft_key_sq(char *keys, int d)
{
  if (d == 0)
    d = 10;
  if (keys[1] == 'O')
  {
    if (keys[2] == 'R')
      s->sq.ndir.x += 0.1;
    if (keys[2] == 'E')
      s->sq.ndir.x -= 0.1;
    if (keys[2] == 'U')
      s->sq.ndir.y -= 0.1;
    if (keys[2] == 'D')
      s->sq.ndir.y += 0.1;
    if (keys[2] == 'Z')
      s->sq.ndir.z += 0.1;
    if (keys[2] == 'B')
      s->sq.ndir.z -= 0.1;
  }
  ft_key_sq2(keys, d);
}