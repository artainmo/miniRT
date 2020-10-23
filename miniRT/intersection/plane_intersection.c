/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:11:35 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 05:14:15 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		plane_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
	inter->shadow.n = s->pl.ndir;
	inter->shadow.dis1 = (ft_vector_dot_product(s->pl.p, inter->shadow.n)
			- ft_vector_dot_product(ray.start, inter->shadow.n))
		/ ft_vector_dot_product(ray.direc, inter->shadow.n);
	if (inter->shadow.dis1 != INFINITY && inter->shadow.dis1 < 0)
		return (1);
	return (0);
}

/*
** plane intersection calculate
** A point on plane p(px,py,pz) is given with a normalized vector n[nx,ny,nz]
** normalized vector (means perpendicular / vector_n * vector_a = 0)
** To calculate plane intersection
** dis = (tr.p1 * tr.n - ray.start * n) / (ray.direc * n)
*/

t_inter	*ft_plane_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
	inter->id.object = 'p';
	inter->id.number = s->pl.status;
	inter->n = s->pl.ndir;
	inter->dis1 = (ft_vector_dot_product(s->pl.p, inter->n)
			- ft_vector_dot_product(ray.start, inter->n))
		/ ft_vector_dot_product(ray.direc, inter->n);
	if (inter->dis1 != INFINITY)
	{
		inter->p = ft_vector_add(ray.start,
				ft_vec_doub_multiplication(ray.direc, inter->dis1));
		inter = ft_inter_color(s, inter, l, s->pl.c);
	}
	return (inter);
}
