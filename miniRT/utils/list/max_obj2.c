/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_obj2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:41:34 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:42:02 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

int	max_cam(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->camera.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	max_light(t_s *s)
{
	int i;

	i = 0;
	s = begin_list(s);
	while (s && s->light.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}
