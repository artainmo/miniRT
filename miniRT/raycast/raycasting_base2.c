/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 07:27:34 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 10:13:50 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** We set the closest intersectionpointdistance inside the appropriate variable
** We find the intersection point coordinated by adding the start
** of the ray with the distance to intersection
** We also collect that intersection color
*/

t_inter	*ft_set_new_closest_intersection(t_ray ray, t_inter *inter)
{
	if (inter->dis1 < inter->closest_p && inter->dis1 >= 0)
	{
		inter->closest_p = inter->dis1;
		inter->final = inter->c;
	}
	return (inter);
}

t_col	ft_cum_light_ch(t_s *s, t_inter *inter, t_s *s_light, t_col cu_light)
{
	if (!ft_color_compare(inter->final, s->amb.color) ||
			(ft_color_compare(inter->final, s->amb.color) &&
			(s_light->light.status == 0 || s_light->light.status == 1)
			&& s_light->next == NULL))
		return (ft_add_color(cu_light, inter->final));
	return (cu_light);
}
