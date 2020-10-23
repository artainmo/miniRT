/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:26:37 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 05:34:08 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** To calculate triangle intersection we will use bariatric coordinates
** P = aA + bB + yC <> a >=0, b>=0, y>=0 <> a + b + y = 1
** P-A=b(B-A)+y(C-A) by resolving this equation and testing if a + b + y = 1
** barycentric coordinate matrix used
** We can test if point inside triangle
** Because the comp precision is not perfect we use 0.000001 instead of 0
** as an error margin
*/

int		ft_inter_in_tr(t_vec p1, t_vec p2, t_vec p3, t_vec p)
{
	double d;
	double alfa;
	double beta;
	double ceta;

	d = (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * ((p1.y - p2.y)));
	if (fabs(d) < ERROR_MARG)
		return (0);
	d = 1 / d;
	alfa = (p.x * (p2.y - p3.y) + p.y * (p3.x - p2.x) + (p2.x * p3.y
				- p3.x * p2.y)) * d;
	beta = (p.x * (p3.y - p1.y) + p.y * (p1.x - p3.x) + (p3.x * p1.y
				- p1.x * p3.y)) * d;
	ceta = (p.x * (p1.y - p2.y) + p.y * (p2.x - p1.x) + (p1.x * p2.y
				- p2.x * p1.y)) * d;
	if (alfa >= 0 && beta >= 0 && ceta >= 0 && alfa + beta + ceta
			<= 1 + ERROR_MARG)
		return (1);
	return (0);
}

/*
** Only used for shadowing
*/

int		triangle_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
	inter->shadow.n = ft_vector_cross_product(ft_direction_vector(s->tr.p1,
				s->tr.p2), ft_direction_vector(s->tr.p1, s->tr.p3));
	inter->shadow.dis1 = (ft_vector_dot_product(s->tr.p1, inter->shadow.n)
			- ft_vector_dot_product(ray.start, inter->shadow.n))
		/ ft_vector_dot_product(ray.direc, inter->shadow.n);
	if (inter->shadow.dis1 != INFINITY)
	{
		if (inter->shadow.dis1 >= 0)
			return (0);
		inter->shadow.p = ft_vector_add(ray.start,
				ft_vec_doub_multiplication(ray.direc, inter->shadow.dis1));
		return (ft_inter_in_tr(s->tr.p1, s->tr.p2, s->tr.p3, inter->shadow.p));
	}
	return (0);
}

/*
** The three points of the triangle are given.
** First calculate if intersects with triangle plane, than test
** if inside the triangle.
**
** To calculate normal take crossproduct of direction vectors
** between the points.
**
** To calculate plane intersection
** dis = (tr.p1 * tr.n - ray.start * n) / (ray.direc * n)
**
** If the point is inside the triangle an intersection is found
*/

t_inter	*ft_triangle_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
	inter->id.object = 't';
	inter->id.number = s->tr.status;
	inter->n = ft_vector_cross_product(ft_direction_vector(s->tr.p1, s->tr.p2),
			ft_direction_vector(s->tr.p1, s->tr.p3));
	inter->dis1 = (ft_vector_dot_product(s->tr.p1, inter->n)
			- ft_vector_dot_product(ray.start, inter->n))
		/ ft_vector_dot_product(ray.direc, inter->n);
	if (inter->dis1 != INFINITY)
	{
		inter->p = ft_vector_add(ray.start,
				ft_vec_doub_multiplication(ray.direc, inter->dis1));
		if (ft_inter_in_tr(s->tr.p1, s->tr.p2, s->tr.p3, inter->p))
			inter = ft_inter_color(s, inter, l, s->tr.c);
		else
			inter->dis1 = INFINITY;
	}
	return (inter);
}
