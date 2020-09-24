/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:29:24 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:30:27 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	int				red;
	int				green;
	int				blue;
	unsigned int	color;
}				t_col;

unsigned int	ft_get_color(t_col c);
t_col			ft_set_color(int red, int green, int blue);
t_col			ft_add_color(t_col c1, t_col c2);
int				ft_color_compare(t_col c1, t_col c2);
t_col			ft_mult_color_double(t_col c1, double c2);

#endif

/*
** void ft_inter_color(t_inter *inter, t_col o, t_light l, t_vec n);
** t_col ft_get_ambient_col(t_col o_c, t_col *inter);
** t_c ft_cum_light_ch(t_inter *inter, t_s s_light, t_c cumu_light);
*/
