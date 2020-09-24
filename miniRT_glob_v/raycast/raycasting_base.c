#include "../miniRT.h"

/*
** We set the closest intersectionpointdistance inside the appropriate variable
** We find the intersection point coordinated by adding the start
** of the ray with the distance to intersection
** We also collect that intersection color
*/

static void ft_set_new_closest_intersection(t_ray ray, t_inter *inter)
{
	if (inter->dis1 < inter->closest_p)
	{
		inter->closest_p = inter->dis1;
		inter->p = ft_vector_add(ray.start,
		ft_vec_doub_multiplication(ray.direc, inter->dis1));
		inter->final = inter->c;
	}
}

/*
** We iterate on all the objects in the scene
** to find the closest intersection point
*/

static void ft_object_iterate(t_ray ray, t_inter *inter, t_light light)
{
	if (s->sp.status)
	{
		ft_sphere_intersection(ray, inter, s->sp, light);
		ft_set_new_closest_intersection(ray, inter);
	}
	if (s->pl.status)
	{
		//ft_plane_intersection(ray, inter, s->pl, light);
		ft_set_new_closest_intersection(ray, inter);
	}
	if (s->sq.status)
	{
		//ft_square_intersection(ray, inter, s->sq, light);
		ft_set_new_closest_intersection(ray, inter);
	}
	if (s->cy.status)
	{
		//ft_cylinder_intersection(ray, inter, s->cy, light);
		ft_set_new_closest_intersection(ray, inter);
	}
	if (s->tr.status)
	{
		//ft_triangle_intersection(ray, inter, s->tr, light);
		ft_set_new_closest_intersection(ray, inter);
	}
}

/*
** We iterate inside the s chained list, the list is chained when multiple
** objects of the same type exist. This function returns the final pixel
** color for a particular light
*/

static void ft_list_iterate(t_ray ray, t_inter *inter, t_light light)
{
	begin_list();
	inter->closest_p = INFINITY;
	while(s->next)
	{
		ft_object_iterate(ray, inter, light);
		s = s->next;
	}
	ft_object_iterate(ray, inter, light);
	if (inter->closest_p == INFINITY)
		inter->final = ft_set_color(0, 0, 0);
	begin_list();
}

/*
** We iterate on each light through another chained list that points
** on the s chained list
** We cumulate the pixel color from different light sources behalf when
** the color is equal to the ambient color.
** This function returns through the inter pointer the final pixel color
*/

static void ft_light_iterate(t_ray ray, t_inter *inter)
{
	t_s *s_light;
	t_col cumu_light;

	begin_list();
	s_light = s;
	cumu_light = ft_set_color(0, 0, 0);
	while(s_light && s_light->light.status)
	{
		ft_list_iterate(ray, inter, s_light->light);
		cumu_light = ft_cumulative_light_check(inter, s_light, cumu_light);
		s_light = s_light->next;
	}
	inter->final = cumu_light;
	begin_list();
}

/*
** We iterate on each pixel of the screen to create rays and search for an
** intersection
*/

void screen_iterate(void)
{
	double x;
	double y;
	t_inter *inter;
	t_ray ray;

	x = s->screen.resolution_x;
	y = s->screen.resolution_y;
	if (!(inter = malloc(sizeof(inter))))
		  ft_exit_no_free("ERROR\nFailed malloc\n");
	while(y)
	{
		while(x)
		{
				ray = ft_create_ray(x, y, 1);
				ft_light_iterate(ray, inter);
				mlx_pixel_put(s->screen.mlx_ptr, s->screen.mlx_win, x, y, inter->final.color);
				x--;
		}
		y--;
		x = s->screen.resolution_x;
	}
	free(inter);
}
