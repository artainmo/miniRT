/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:38:25 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:41:29 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	max_sp(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->sp.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	max_pl(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->pl.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	max_sq(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->sq.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	max_cy(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->cy.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	max_tr(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->tr.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}
