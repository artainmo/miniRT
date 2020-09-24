#include "../miniRT.h"

/*
** We set the closest intersectionpointdistance inside the appropriate variable
** We find the intersection point coordinated by adding the start
** of the ray with the distance to intersection
** We also collect that intersection color
*/

t_inter *ft_set_new_closest_intersection(t_ray ray, t_inter *inter)
{
	if (inter->dis1 < inter->closest_p && inter->dis1 >= 0)
	{
		inter->closest_p = inter->dis1;
		inter->final = inter->c;
	}
	return (inter);
}

t_col ft_cumulative_light_check(t_s *s, t_inter *inter, t_s *s_light, t_col cumu_light)
{
	if (!ft_color_compare(inter->final, s->amb.color) ||
				(ft_color_compare(inter->final, s->amb.color) &&
							(s_light->light.status == 0 || s_light->light.status == 1)
										&& s_light->next == NULL))
		return(ft_add_color(cumu_light, inter->final));
	return(cumu_light);
}
