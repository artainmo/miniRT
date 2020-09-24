/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:12:01 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:12:40 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_s	*ft_setup_new(t_s *s)
{
	t_s *new;

	if (!(new = malloc(sizeof(t_s))))
		ft_exit_no_free("ERROR\nFailed malloc\n");
	new->screen = s->screen;
	new->amb = s->amb;
	new->camera.status = 0;
	new->light.status = 0;
	new->sp.status = 0;
	new->pl.status = 0;
	new->sq.status = 0;
	new->cy.status = 0;
	new->tr.status = 0;
	new->next = NULL;
	new->first = s->first;
	return (new);
}

t_s	*ft_setup_init(t_s *s)
{
	if (!(s = malloc(sizeof(t_s))))
		ft_exit_no_free("ERROR\nFailed malloc\n");
	s->screen.status = 0;
	s->screen.window_status = 0;
	s->light.status = 0;
	s->camera.status = 0;
	s->sp.status = 0;
	s->pl.status = 0;
	s->sq.status = 0;
	s->cy.status = 0;
	s->tr.status = 0;
	s->amb.status = 0;
	s->amb.color = ft_set_color(0, 0, 0);
	s->asked_cam = 1;
	s->next = NULL;
	s->first = s;
	return (s);
}
