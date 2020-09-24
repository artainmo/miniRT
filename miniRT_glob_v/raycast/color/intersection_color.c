#include "color.h"
#include "../../miniRT.h"

t_col ft_cumulative_light_check(t_inter *inter, t_s *s_light, t_col cumu_light)
{
	if (!ft_color_compare(inter->final, s->amb.color) ||
				(ft_color_compare(inter->final, s->amb.color) &&
							(s_light->light.status == 0 || s_light->light.status == 1)
										&& s_light->next == NULL))
		return(ft_add_color(cumu_light, inter->final));
	return(cumu_light);
}

/*
** s->light usually does not come from a single s->light source,
** even when they're not immediately visible. That is why objects cannot be
** coms->pletly in the dark, minimum s->light should always be present (ambient)
** To calculate the min s->light use a min s->light intensity.
** This function returns ambient s->lightning s->plus puts ambient color where needed
*/

static t_col ft_get_ambient_col(t_col o_c, t_col *inter)
{
  t_col ambient;

  ambient.red = o_c.red * (s->amb.intensity * s->amb.color.red/255);
  ambient.green = o_c.green * (s->amb.intensity * s->amb.color.green/255);
  ambient.blue = o_c.blue * (s->amb.intensity * s->amb.color.blue/255);
  ambient.color = ft_get_color(ambient);

  if (inter->red < ambient.red)
    inter->red = ambient.red;
  if (inter->green < ambient.green)
    inter->green = ambient.green;
  if (inter->blue < ambient.blue)
    inter->blue = ambient.blue;
  return(ambient);
}

/*
** normal intersection vector is equal to intersect - centrum s->sphere direction
** vector. A normal vector is perpendicular to the surface of a vertex.
** s->lighs->tray is a direction vector from intersection to s->light position.
** Multis->plication is used to find the angle between two direction vectors.
** If the angle is 90degrees 0 is returned.
** Under 90 and a negative number is returned between 0 and -1.
** Above 90 and a positive number is returned between 0 and 1.
*/

void ft_intersection_color(t_inter *inter, t_col o, t_light l, t_vec n)
{
		double angle;

		l.ray.direc = ft_direction_vector(l.position, inter->p);
		angle = ft_vector_dot_product(l.ray.direc, n);
		inter->c.red = (o.red * l.intensity) -
          (angle * (l.color.red * l.intensity));
		inter->c.green = (o.green * l.intensity) -
          (angle * (l.color.green * l.intensity));
		inter->c.blue = (o.blue * l.intensity) -
          (angle * (l.color.blue * l.intensity));
    ft_get_ambient_col(o, &inter->c);
		inter->c.color = ft_get_color(inter->c);
}
