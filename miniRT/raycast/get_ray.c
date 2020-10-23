/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:35:44 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 05:39:33 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_ray			ft_get_ray(t_vec start_point, t_vec direction)
{
	t_ray ret;

	ret.start = start_point;
	ret.direc = direction;
	return (ret);
}

/*
** Create rays with the right/asked camera
*/

static t_cam	ft_get_cam(t_s *s)
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
** In ray s->tracing we start from a pixel position which we
** transform to a point on the image plane from which we can
** build a ray direction.
** A ray consists of a starting point and a direction vector
** The starting point being the s->camera and the direction vector the s->camera
** to the image s->plane point.
*/

t_ray			ft_create_ray(t_s *s, double x, double y, double z)
{
	t_ray	ray;
	t_vec	image_plane_point;
	t_cam	cam;
	double	fov;

	cam = ft_get_cam(s);
	fov = tan(cam.h_fov / 2);
	image_plane_point.x = (x - s->screen.res_x / 2) * fov;
	image_plane_point.y = ((y - s->screen.res_y / 2) * -1) * fov;
	image_plane_point.z = 1;
	image_plane_point = ft_cam_world_matrix(image_plane_point, cam.ndir, cam.p);
	ray = ft_get_ray(image_plane_point, cam.ndir);
	return (ray);
}
