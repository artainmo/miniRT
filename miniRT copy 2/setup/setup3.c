/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:06:28 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:09:24 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static void	ft_setup_cylinder2(t_s *s, char *line, int i, int l)
{
	s->cy.ndir.x = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.ndir.y = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.ndir.z = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.r = (ft_atof(ft_substr(line, l, i - l))) / 2;
	ft_search_setup(&i, &l, line);
	s->cy.height = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.c.red = ft_atoi(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.c.green = ft_atoi(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.c.blue = ft_atoi(ft_substr(line, l, i - l));
	s->cy.c.color = ft_get_color(s->cy.c);
	s = begin_list(s);
}

void		ft_setup_cylinder(t_s *s, char *line)
{
	int i;
	int l;
	int counter;

	i = 2;
	counter = 0;
	while (counter < max_cy(s))
		s = iter_list_new(s, &counter);
	s->cy.status = counter + 1;
	ft_search_setup(&i, &l, line);
	s->cy.p.x = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.p.y = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->cy.p.z = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	ft_setup_cylinder2(s, line, i, l);
}

static void	ft_setup_tr2(t_s *s, char *line, int i, int l)
{
	s->tr.p2.x = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p2.y = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p2.z = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p3.x = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p3.y = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p3.z = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.c.red = ft_atoi(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.c.green = ft_atoi(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.c.blue = ft_atoi(ft_substr(line, l, i - l));
	s->tr.c.color = ft_get_color(s->tr.c);
	s = begin_list(s);
}

void		ft_setup_tr(t_s *s, char *line)
{
	int i;
	int l;
	int counter;

	i = 2;
	counter = 0;
	while (counter < max_tr(s))
		s = iter_list_new(s, &counter);
	s->tr.status = counter + 1;
	ft_search_setup(&i, &l, line);
	s->tr.p1.x = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p1.y = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	s->tr.p1.z = ft_atof(ft_substr(line, l, i - l));
	ft_search_setup(&i, &l, line);
	ft_setup_tr2(s, line, i, l);
}
