#include "miniRT.h"

void ft_put_line(int x1, int y1, int x2, int y2, int color, int witdh, void *mlx_ptr, void *mlx_win)
{
  double line_p;
  int yi;
  int xi;

  yi = y1;
  xi = x1;
  if (x1 == x2)
  {
    while(witdh)
    {
      while (y1 != y2)
      {
        mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, color);
        y1++;
      }
      witdh--;
      xi++;
      x1 = xi;
      x2++;
      y1 = yi;
    }
  }
  else
  {
    while(witdh)
    {
      while (x1 != x2)
      {
        line_p = ((double)y2 - (double)y1)/((double)x2 - (double)x1);
        y1 = y1 + ft_round(line_p);
        mlx_pixel_put(mlx_ptr, mlx_win, x1, y1, color);
        x1++;
      }
      witdh--;
      yi++;
      y1 = yi;
      y2++;
      x1 = xi;
    }
  }
}
