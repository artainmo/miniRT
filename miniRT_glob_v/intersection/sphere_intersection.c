#include "../miniRT.h"

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

void ft_sphere_intersection(t_ray ray, t_inter *inter, t_sp sp1, t_light li)
{
	double a;
	double b;
	double c;
	double descriminant;
	t_vec dis;

	dis = ft_vector_substraction(ray.start, sp1.centrum);
	a = ft_vector_dot_product(ray.direc,ray.direc);
	b = 2 * ft_vector_dot_product(ray.direc, dis);
	c = ft_vector_dot_product(dis, dis) - pow(sp1.r,2);
	descriminant = pow(b, 2) - (4 * a * c);
	if (descriminant >= 0)
	{
		inter->dis1 = -b + sqrt(descriminant) / (2 * a);
		inter->dis2 = -b - sqrt(descriminant) / (2 * a);
		if (inter->dis2 < inter->dis1)
			inter->dis1 = inter->dis2;
		ft_intersection_color(inter, sp1.c, li,
					ft_direction_vector(sp1.centrum, inter->p));
	}
}
