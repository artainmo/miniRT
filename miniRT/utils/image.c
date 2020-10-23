/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:16:56 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:18:28 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** data pointer is a char string that should hold the information of each
** screen pixel. Each pixel contains 4 chars, to calculate the y coordinate of
** the pixel you need to use the size_line.
** The first three chars of the pixel is equal to RGB and last to alpha.
** Pixel chars (BLUE,Green,RED,Alpha) The 4th char alpha won't be used here
** bpp/8 because one char is 8bytes
*/

t_s		*create_image(t_s *s, t_inter *inter, int x, int y)
{
	int i;

	s = begin_list(s);
	i = (x * s->screen.bpp / 8) + (s->screen.size_line * y);
	s->screen.data[i] = inter->final.blue;
	s->screen.data[++i] = inter->final.green;
	s->screen.data[++i] = inter->final.red;
	s->screen.data[++i] = 0;
	return (s);
}

/*
** After using key hook commands next_image is called to refill the image data
** and make it appear on screen
*/

void	ft_next_image(t_s *s)
{
	ft_misconfiguration(s);
	ft_bzero(s->screen.data, s->screen.res_x * s->screen.res_y * 4);
	s = screen_iterate(s);
	create_window(s);
}
