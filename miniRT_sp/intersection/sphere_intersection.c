#include "../miniRT.h"

/*
** Returns one if intersection is found or zero if not
** Only used for the shadow algo
** If the distance to found intersection is negative the object is behind
** and thus no shadow is necessary, return 0.
*/
int sphere_intersection_boolean(t_s *s, t_ray ray, t_inter *inter)
{
	double a;
	double b;
	double c;
	double descriminant;
	t_vec dis;

	dis = ft_vector_substraction(ray.start, s->sp.centrum);
	a = ft_vector_dot_product(ray.direc,ray.direc);
	b = 2 * ft_vector_dot_product(ray.direc, dis);
	c = ft_vector_dot_product(dis, dis) - pow(s->sp.r,2);
	descriminant = pow(b, 2) - (4 * a * c);
	if (descriminant >= 0)
	{
		inter->dis1 = -b + sqrt(descriminant) / (2 * a);
		inter->dis2 = -b - sqrt(descriminant) / (2 * a);
		if (inter->dis2 < inter->dis1)
			inter->dis1 = inter->dis2;
		if (inter->dis1 >= 0)
			return (0);
		return (1);
	}
	else
		return (0);
}

/*
** We need a vector representing the distance between the start of
** the ray and the position of the circle. This is the term (p0 - c)
** that we will call t, t is a vector as well
** a = ray.direc * ray.direc (x*x + y*y + z*z)
** b = 2 * ray.direc * t
** c = t*t - pow(r,2) r is the radius of the circle
** descriminant = pow(b,2) - 4ac
** If descriminant >= 0 return intersection found
** We calculate the distance from the ray start to the intersection in
** dis1 and dis2 we choose only the closest intersection distance
** We compare with the prior closest intersection of other objects
** If necessary we compute the intersection point color
*/

t_inter *ft_sphere_intersection(t_s *s, t_inter *inter, t_ray ray, t_light l)
{
	double a;
	double b;
	double c;
	double descriminant;
	t_vec dis;

	inter->id.object = 's';
	inter->id.number = s->sp.status;
	dis = ft_vector_substraction(ray.start, s->sp.centrum);
	a = ft_vector_dot_product(ray.direc,ray.direc);
	b = 2 * ft_vector_dot_product(ray.direc, dis);
	c = ft_vector_dot_product(dis, dis) - pow(s->sp.r,2);
	descriminant = pow(b, 2) - (4 * a * c);
	if (descriminant >= 0)
	{
		inter->dis1 = -b + sqrt(descriminant) / (2 * a);
		inter->dis2 = -b - sqrt(descriminant) / (2 * a);
		if (inter->dis2 < inter->dis1)
			inter->dis1 = inter->dis2;
		inter->p = ft_vector_add(ray.start,
			ft_vec_doub_multiplication(ray.direc, inter->dis1));
		inter->n = ft_direction_vector(s->sp.centrum, inter->p);
		inter = ft_intersection_color(s, inter, l, s->sp.c);
	}
	return (inter);
}
