/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 07:36:26 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 07:40:22 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** Long conditions are used to avoid intersection with non-existent objects
** or itself
*/

static int	ft_object_iterate(t_s *s, t_inter *inter, t_ray ray)
{
	int ret;

	ret = 0;
	if (s->sp.status && (s->sp.status != inter->id.number
				|| inter->id.object != 's'))
		ret = sphere_intersection_boolean(s, ray, inter);
	if (s->pl.status && (s->pl.status != inter->id.number
				|| inter->id.object != 'p') && ret == 0)
		ret = plane_intersection_boolean(s, ray, inter);
	if (s->sq.status && (s->sq.status != inter->id.number
				|| inter->id.object != 'q') && ret == 0)
		ret = square_intersection_boolean(s, ray, inter);
	if (s->cy.status && (s->cy.status != inter->id.number
				|| inter->id.object != 'c') && ret == 0)
		ret = cylinder_intersection_boolean(s, ray, inter);
	if (s->tr.status && (s->tr.status != inter->id.number
				|| inter->id.object != 't') && ret == 0)
		ret = triangle_intersection_boolean(s, ray, inter);
	ret = ret;
	return (ret);
}

static int	ft_list_iterate(t_s *s, t_inter *inter, t_ray ray)
{
	s = begin_list(s);
	while (s->next)
	{
		if (ft_object_iterate(s, inter, ray))
			return (1);
		s = s->next;
	}
	if (ft_object_iterate(s, inter, ray))
		return (1);
	return (0);
}

/*
** We create a ray that starts from the intersection point and goes to the
** light point. If this ray intersects an object on the way the intersection
** point must be a shadow.
*/

t_inter		*ft_shadows(t_s *s, t_inter *inter, t_light l)
{
	t_ray intersection_to_light;

	intersection_to_light = ft_get_ray(inter->p, l.ray.direc);
	if (ft_list_iterate(s, inter, intersection_to_light))
		inter->c = ft_set_color(0, 0, 0);
	return (inter);
}
