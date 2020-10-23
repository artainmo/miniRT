/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:37:53 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:38:18 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

t_s	*begin_list(t_s *s)
{
	s = s->first;
	return (s);
}

t_s	*iter_list_new(t_s *s, int *counter)
{
	if (!s->next)
		s->next = ft_setup_new(s);
	s = s->next;
	*counter = *counter + 1;
	return (s);
}
