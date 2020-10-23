/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 05:48:10 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 10:37:15 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** We iterate on all the objects in the scene
** to find the closest intersection point
*/

static void		ft_obj_iter(t_s *s, t_ray ray, t_inter **inter, t_light light)
{
	if (s->sp.status)
	{
		*inter = ft_sphere_intersection(s, *inter, ray, light);
		*inter = ft_set_new_closest_intersection(ray, *inter);
	}
	if (s->pl.status)
	{
		*inter = ft_plane_intersection(s, *inter, ray, light);
		*inter = ft_set_new_closest_intersection(ray, *inter);
	}
	if (s->sq.status)
	{
		*inter = ft_square_inter(s, *inter, ray, light);
		*inter = ft_set_new_closest_intersection(ray, *inter);
	}
	if (s->cy.status)
	{
		*inter = ft_cylinder_inter(s, *inter, ray, light);
		*inter = ft_set_new_closest_intersection(ray, *inter);
	}
	if (s->tr.status)
	{
		*inter = ft_triangle_intersection(s, *inter, ray, light);
		*inter = ft_set_new_closest_intersection(ray, *inter);
	}
}

/*
** We iterate inside the s chained list, the list is chained when multiple
** objects of the same type exist. This function returns the final pixel
** color for a particular light
*/

static t_inter	*ft_list_iter(t_s *s, t_ray ray, t_inter *inter, t_light light)
{
	s = begin_list(s);
	inter->closest_p = INFINITY;
	inter->dis1 = INFINITY;
	while (s->next)
	{
		ft_obj_iter(s, ray, &inter, light);
		s = s->next;
	}
	ft_obj_iter(s, ray, &inter, light);
	if (inter->closest_p == INFINITY)
		inter->final = ft_set_color(BACKGROUND_R, BACKGROUND_G, BACKGROUND_B);
	return (inter);
}

/*
** We iterate on each light through another chained list that points
** on the s chained list
** We cumulate the pixel color from different light sources behalf when
** the color is equal to the ambient color.
** This function returns through the inter pointer the final pixel color
** If no light exists a black sceen will be returned
*/

static t_inter	*ft_light_iterate(t_s *s, t_ray ray, t_inter *inter)
{
	t_s		*s_light;
	t_col	cum_light;

	s = begin_list(s);
	s_light = s;
	cum_light = ft_set_color(0, 0, 0);
	while (s_light && s_light->light.status)
	{
		if (s_light->light.color.color)
		{
			ft_list_iter(s, ray, inter, s_light->light);
			cum_light = ft_cum_light_ch(s, inter, s_light, cum_light);
		}
		s_light = s_light->next;
	}
	inter->final = cum_light;
	return (inter);
}

/*
** We iterate on each pixel of the screen to create rays and search for an
** intersection, we send the color data to the create_image.
*/

t_s				*screen_iterate(t_s *s)
{
	double	x;
	double	y;
	t_inter	*inter;
	t_ray	ray;

	x = s->screen.res_x;
	y = s->screen.res_y;
	if (!(inter = malloc(sizeof(inter))))
		ft_exit_no_free("ERROR\nFailed malloc\n");
	while (y)
	{
		while (x)
		{
			ray = ft_create_ray(s, x, y, 1);
			inter = ft_light_iterate(s, ray, inter);
			s = create_image(s, inter, x, y);
			x--;
		}
		y--;
		x = s->screen.res_x;
	}
	free(inter);
	return (s);
}
