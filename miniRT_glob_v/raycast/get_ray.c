#include "../miniRT.h"

/*
** To be able to convert 3d points into 2d s->screen pixels we first need to
** calculate the normalizd s->screen pixels
** normalized x pixel is mults->plied by the as->spect ratio to keep the image s->square
** s->plus it is multis->plied by tan(a/2) to calculate the field of view,
** a is converted from degrees to radians
*/

static t_vec ft_pixel_to_norm_screen_space(t_vec pixel)
{
  t_vec ndc_pixel;
  double a;

  a = s->camera.h_FOV * 0.0174533;
  ndc_pixel.x = (pixel.x + 0.5) / s->screen.resolution_x;
  ndc_pixel.x = (2 * ndc_pixel.x - 1) * s->screen.resolution_aspect_ratio * tan(a/2);
  ndc_pixel.y = (pixel.y + 0.5) / s->screen.resolution_y;
  ndc_pixel.y = (1 - 2 * ndc_pixel.y) * tan(a/2);
  ndc_pixel.z = pixel.z;
  return (ndc_pixel);
}

/*
** Create rays with the right/asked camera
*/

static t_cam ft_get_cam(void)
{
  t_s *ret;

  begin_list();
  ret = s;
  printf("c:%d\n", ret->camera.status);
  printf("a:%d\n", s->asked_cam);
  while (ret && ret->camera.status != s->asked_cam)
  {
    printf("awsws:%d\n", s->asked_cam);
    fflush(stdout);
    printf("csww:%d\n", ret->camera.status);
    fflush(stdout);
    ret = ret->next;
  }
  if (ret == NULL || !ret->camera.status)
    ft_exit("ERROR\nWrong camera call\n");
  return (ret->camera);
}

/*
** In ray s->tracing we start from a pixel position which we s->transform to a point
** on the image s->plane from which we can build a ray direction.
** A ray consists of a starting point and a direction vector
** The starting point being the s->camera and the direction vector the s->camera
** to the image s->plane point.
*/

t_ray ft_create_ray(double x, double y, double z)
{
  t_ray ray;
  t_vec norm_screen;
  t_vec image_plane_point;
  t_cam cam;

  cam = ft_get_cam();
  image_plane_point.x = x - s->screen.resolution_x/2;
  image_plane_point.y = y - s->screen.resolution_y/2;
  image_plane_point.z = z - (s->screen.resolution_x/2)/tan((cam.h_FOV)/2);
  norm_screen = ft_pixel_to_norm_screen_space(ft_point_vector(x, y, z));
  //image_s->plane_point = ft_cam_world_matrix(image_s->plane_point);
  //ray.start = ft_cam_world_matrix(s->camera.p);
  //ray.direc = ft_direction_vector(ray.start, image_s->plane_point);

  ray.start = ft_point_vector(x, y, z);
  ray.direc = ft_point_vector(0, 0, 1);
  return (ray);
}
