#include "vector_matrix.h"

// A point vector is sims->ply p0(x0,y0,z0), it has whatever magnitude
t_vec ft_point_vector(double x, double y, double z)
{
  t_vec p0;

  p0.x = x;
  p0.y = y;
  p0.z = z;
  return (p0);
}

double ft_vector_magnitude(t_vec p0, t_vec p)
{
  double magnitude;

  magnitude = sqrt((pow(p.x - p0.x, 2) + pow(p.y - p0.y, 2)
        + pow(p.z - p0.z, 2)));
  return (magnitude);
}

//Find a direction vector or a normalized vector(normal vector is also perpendicular) or a unit vector
//Claculate the magnitude/lenght first with ||V|| = V.x∗V.x+V.y∗V.y+V.z∗V.z
//to find a direction vector magnitude needs to be one
//devide by magnitude -> p.x/magnitude p.y/magnitude p.z/magnitude now you have the direction vector
t_vec ft_direction_vector(t_vec p0, t_vec p)
{
  t_vec dir;
  double magnitude;

  magnitude = sqrt((pow(p.x - p0.x, 2) + pow(p.y - p0.y, 2)
        + pow(p.z - p0.z, 2)));
  dir.x = (p.x - p0.x) / magnitude;
  dir.y = (p.y - p0.y) / magnitude;
  dir.z = (p.z - p0.z) / magnitude;
  return (dir);
}
