/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:39:41 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 05:43:37 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** light usually does not come from a single light source,
** even when they're not immediately visible. That is why objects cannot be
** completly in the dark, minimum light should always be present (ambient)
** To calculate the min light use a min light intensity.
** This function returns ambient lightning plus puts ambient color where needed
*/

static t_col	ft_ambient_col(t_s *s, t_col o_c, t_inter *inter)
{
	t_col ambient;

	ambient.red = o_c.red * (s->amb.intensity * s->amb.color.red / 255);
	ambient.green = o_c.green * (s->amb.intensity * s->amb.color.green / 255);
	ambient.blue = o_c.blue * (s->amb.intensity * s->amb.color.blue / 255);
	ambient.color = ft_get_color(ambient);
	if (inter->c.red < ambient.red)
		inter->c.red = ambient.red;
	if (inter->c.green < ambient.green)
		inter->c.green = ambient.green;
	if (inter->c.blue < ambient.blue)
		inter->c.blue = ambient.blue;
	return (inter->c);
}

/*
** Dot product of two vectors is used to find the
** angle between two direction vectors.
** angle will always be between -1,1
** If the angle is 90degrees 0 is returned, if angle 0 than 1 is returned.
** If the angle between both vectors is greater than 90 degrees
** then the result of the dot product will actually become negative
** If angle is less than 90degrees result will be positive
** The function set_color make ssure no values are under 0 or above 255
*/

static t_col	ft_diffuse_col(t_s *s, t_light l, t_inter *inter, t_col o_c)
{
	t_col	diffuse;
	t_col	tmp;
	double	angle;

	if ((angle = 1 - ft_vector_dot_product(inter->n, l.ray.direc)) < 0
			|| inter->p.z < l.position.z)
		angle = 0;
	diffuse.red = o_c.red * (angle * l.color.red / 255 * l.intensity);
	diffuse.green = o_c.green * (angle * l.color.green / 255 * l.intensity);
	diffuse.blue = o_c.blue * (angle * l.color.blue / 255 * l.intensity);
	diffuse = ft_set_color(diffuse.red, diffuse.green, diffuse.blue);
	return (diffuse);
}

/*
** A normal vector is perpendicular to the surface of a vertex.
** l.ray.direc is a direction vector from light position to inter.
** Diffuse light find the illumination basis, ambient color gives a minimum
** color to each pixel and shadow creates hard shadows
*/

t_inter			*ft_inter_color(t_s *s, t_inter *inter, t_light l, t_col o_c)
{
	double	angle;
	t_col	diffuse;

	l.ray.direc = ft_direction_vector(l.position, inter->p);
	inter->c = ft_diffuse_col(s, l, inter, o_c);
	inter = ft_shadows(s, inter, l);
	inter->c = ft_ambient_col(s, o_c, inter);
	inter->c = ft_set_color(inter->c.red, inter->c.green, inter->c.blue);
	return (inter);
}
