#include "../miniRT.h"

  int ft_mouse(int button,int x,int y, t_s *s)
  {
    if ((button == LEFT_CLICK || button == RIGHT_CLICK)
          && (x >= 13 && x <= 17) && (y >= -12 && y <= -7))
  	   ft_exit(s, "You quit the program\n");
    return (button);
  }
