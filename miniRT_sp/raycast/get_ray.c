#include "../miniRT.h"


t_ray ft_get_ray(t_vec start_point, t_vec direction)
{
  t_ray ret;

  ret.start = start_point;
  ret.direc = direction;
  return (ret);
}

/*
** Create rays with the right/asked camera
*/

static t_cam ft_get_cam(t_s *s)
{
  t_s *ret;

  s = begin_list(s);
  ret = s;
  while (ret && ret->camera.status != s->asked_cam)
    ret = ret->next;
  if (ret == NULL || !ret->camera.status)
    ft_exit(s, "ERROR\nWrong camera call\n");
  return (ret->camera);
}


/*
** In ray s->tracing we start from a pixel position which we s->transform to a point
** on the image s->plane from which we can build a ray direction.
** A ray consists of a starting point and a direction vector
** The starting point being the s->camera and the direction vector the s->camera
** to the image s->plane point.
*/


t_ray ft_create_ray(t_s *s, double x, double y, double z)
{
  t_ray ray;;
  t_vec image_plane_point;
  t_cam cam;
  double fov;

  cam = ft_get_cam(s);
  fov = tan(cam.h_FOV/2);
  image_plane_point.x = (x - s->screen.res_x/2) * fov;
  image_plane_point.y = ((y - s->screen.res_y/2) * -1) * fov;
  image_plane_point.z = 1;
  image_plane_point = ft_cam_world_matrix(image_plane_point, cam.ndir, cam.p);
  ray = ft_get_ray(image_plane_point, cam.ndir);
  return (ray);
}


/*
** To be able to convert 3d points into 2d s->screen pixels we first need to
** calculate the normalizd s->screen pixels
** normalized x pixel is mults->plied by the as->spect ratio to keep the image s->square
** s->plus it is multis->plied by tan(a/2) to calculate the field of view,
** a is converted from degrees to radians

static t_vec ft_pixel_to_norm_screen_space(t_s *s, t_vec pixel)
{
  t_vec ndc_pixel;

  ndc_pixel.x = (pixel.x + 0.5) / s->screen.res_x;
  ndc_pixel.x = (2 * ndc_pixel.x - 1) * s->screen.resolution_aspect_ratio * tan(s->camera.h_FOV/2);
  ndc_pixel.y = (pixel.y + 0.5) / s->screen.res_y;
  ndc_pixel.y = (1 - 2 * ndc_pixel.y) * tan(s->camera.h_FOV/2);
  ndc_pixel.z = pixel.z;
  return (ndc_pixel);
}
*/
