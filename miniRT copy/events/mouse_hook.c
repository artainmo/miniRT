#include "../miniRT.h"

/*
** Quits the program cleanly when clicking on red cross and changes
** camera rotation by clikcing on screen with mouse.
*/
int ft_mouse(int button,int x,int y, t_s *s)
{
  double nx;
  double ny;

  if ((button == LEFT_CLICK || button == RIGHT_CLICK)
        && (x >= 13 && x <= 17) && (y >= -12 && y <= -7))
    ft_exit(s, "You quit the program\n");
  nx = (double)(x - s->screen.res_x/2) / (double)s->screen.res_x/2;
  ny = (double)((y - s->screen.res_y/2) * -1) / (double)s->screen.res_y/2;
  s->camera.ndir.x += nx;
  s->camera.ndir.y += ny;
  ft_next_image(s);
  return (button);
}
