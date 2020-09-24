/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:16:59 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 05:26:17 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** We calculate each corner of the square, then we create two triangles from
** that square and we use the is_in_triangle function to see if the point
** sits in one of those two triangles and thus in the square
*/

static int	ft_in_sq(t_vec centrum, double side, t_vec dir, t_vec p)
{
	t_vec a;
	t_vec b;
	t_vec c;
	t_vec x_axis;
	t_vec y_axis;

	x_axis = ft_vector_cross_product(ft_point_vector(0, 1, 0), dir);
	y_axis = ft_vector_cross_product(ft_point_vector(1, 0, 0), dir);
	a = ft_vec_move(centrum, x_axis, -side / 2);
	a = ft_vec_move(a, y_axis, +side / 2);
	b = ft_vec_move(centrum, x_axis, +side / 2);
	b = ft_vec_move(b, y_axis, +side / 2);
	c = ft_vec_move(centrum, x_axis, -side / 2);
	c = ft_vec_move(c, y_axis, -side / 2);
	if (ft_inter_in_tr(a, b, c, p))
		return (1);
	a = ft_vec_move(centrum, x_axis, +side / 2);
	a = ft_vec_move(a, y_axis, -side / 2);
	if (ft_inter_in_tr(a, b, c, p))
		return (1);
	else
		return (0);
}

int			square_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
	inter->shadow.n = s->sq.ndir;
	inter->shadow.dis1 = (ft_vector_dot_product(s->sq.p, inter->shadow.n)
			- ft_vector_dot_product(ray.start, inter->shadow.n))
		/ ft_vector_dot_product(ray.direc, inter->shadow.n);
	if (inter->shadow.dis1 != INFINITY)
	{
		inter->shadow.p = ft_vector_add(ray.start,
				ft_vec_doub_multiplication(ray.direc, inter->shadow.dis1));
		return (ft_in_sq(s->sq.p, s->sq.side, s->sq.ndir, inter->shadow.p));
	}
	return (0);
}

/*
** Square center, norm vector each axis and side size are given to calculate
** a square in world space.
** To calculate square first check if ray intersets with plane, after see if
** intersect is in square
*/

t_inter		*ft_square_inter(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
	inter->id.object = 'q';
	inter->id.number = s->sq.status;
	inter->n = s->sq.ndir;
	inter->dis1 = (ft_vector_dot_product(s->sq.p, inter->n)
			- ft_vector_dot_product(ray.start, inter->n))
		/ ft_vector_dot_product(ray.direc, inter->n);
	if (inter->dis1 != INFINITY)
	{
		inter->p = ft_vector_add(ray.start,
				ft_vec_doub_multiplication(ray.direc, inter->dis1));
		if (ft_in_sq(s->sq.p, s->sq.side, s->sq.ndir, inter->p))
			inter = ft_inter_color(s, inter, l, s->sq.c);
		else
			inter->dis1 = INFINITY;
	}
	return (inter);
}
