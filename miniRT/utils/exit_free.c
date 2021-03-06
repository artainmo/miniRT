/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:15:32 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:16:37 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	free_all(t_s *s)
{
	t_s	*tmp;

	s = begin_list(s);
	while (s)
	{
		tmp = s;
		free(s);
		s = tmp->next;
	}
}

void	ft_exit(t_s *s, char *error_message)
{
	ft_putstr_fd(error_message, 0);
	s = begin_list(s);
	if (s->screen.window_status)
		mlx_destroy_window(s->screen.mlx_ptr, s->screen.mlx_win);
	free_all(s);
	exit(0);
}

void	ft_exit_no_free(char *error_message)
{
	ft_putstr_fd(error_message, 0);
	exit(0);
}
