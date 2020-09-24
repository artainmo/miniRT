/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misconfiguration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:18:43 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:21:05 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** exit function calls all functions registered with atexit and terminates
** the program. File buffers are flushed, streams are closed,
** and temporary files are deleted.
** The parameter zero indicate no error message, 1 would indicate
** an error message
*/

static int	ft_mis_norm_vector(t_vec n)
{
	if (n.x < -1 || n.x > 1 || n.y < -1 || n.y > 1 || n.z < -1 || n.z > 1)
		return (0);
	return (1);
}

static int	ft_mis_color(t_col c)
{
	if (c.red < 0 || c.red > 255 || c.green < 0 || c.green > 255 || c.blue < 0
			|| c.blue > 255)
		return (0);
	return (1);
}

static void	ft_misconfiguration2(t_s *s)
{
	if (s->pl.status)
	{
		if (!ft_mis_color(s->pl.c) || !ft_mis_norm_vector(s->pl.ndir))
			ft_exit(s, "ERROR\nplane is misconfigured\n");
	}
	if (s->sq.status)
	{
		if (!ft_mis_color(s->sq.c) || !ft_mis_norm_vector(s->sq.ndir))
			ft_exit(s, "ERROR\nsquare is misconfigured\n");
	}
	if (s->cy.status)
	{
		if (!ft_mis_color(s->cy.c) || !ft_mis_norm_vector(s->cy.ndir))
			ft_exit(s, "ERROR\ncylinder is misconfigured\n");
	}
	if (s->tr.status)
	{
		if (!ft_mis_color(s->tr.c))
			ft_exit(s, "ERROR\ntriangle is misconfigured\n");
	}
	if (s->sp.status)
	{
		if (!ft_mis_color(s->sp.c))
			ft_exit(s, "ERROR\nsphere is misconfigured\n");
	}
}

void		ft_misconfiguration1(t_s *s)
{
	if (s->light.status)
	{
		if (s->light.intensity > 1 || s->light.intensity < 0
				|| !ft_mis_color(s->light.color))
			ft_exit(s, "ERROR\nlight is misconfigured\n");
	}
	if (s->camera.status)
	{
		if (s->camera.h_fov < 0 || s->camera.h_fov >
				180 / 0.0174533 || !ft_mis_norm_vector(s->camera.ndir))
			ft_exit(s, "ERROR\ncamera is misconfigured\n");
	}
	ft_misconfiguration2(s);
}

void		ft_misconfiguration(t_s *s)
{
	s = begin_list(s);
	if (!s->camera.status)
		ft_exit(s, "ERROR\nNo camera\n");
	if (s->asked_cam < 1 || s->asked_cam > max_cam(s))
		ft_exit(s, "ERROR\nWrong camera call\n");
	if (s->screen.res_x <= 0 || s->screen.res_y <= 0 ||
			!s->screen.status)
		ft_exit(s, "ERROR\nscreen resolution is misconfigured\n");
	if (s->amb.status)
	{
		if (s->amb.intensity > 1 || s->amb.intensity < 0
				|| !ft_mis_color(s->amb.color))
			ft_exit(s, "ERROR\nAmbient light is misconfigured\n");
	}
	while (s->next)
	{
		ft_misconfiguration1(s);
		s = s->next;
	}
	ft_misconfiguration1(s);
	s = begin_list(s);
}
