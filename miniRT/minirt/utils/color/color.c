/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:25:21 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:26:51 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/*
** color is calculated with hexadecimal and a combination of red,green,blue.
** 0xA209F3 -> A2=red=A(or10)*16+2=162 09=green=0+9=9 FF=blue=For15*16+15=255
** -> primary color will be blue combined with smaller amounts of red
** Using bitshifting to manipulate the hexadecimal color value that consists
** of 3 times 8 bits for red,green,blue
** << shifts activated bytes to the left
** >> shifts activated bytes to the right
** & takes two bits and performs and operation: result is 1 if two bits are 1
** | takes two bits and performs or operation: result is 0 if two bits are 0
*/

unsigned int	ft_get_color(t_col c)
{
	if (c.red > 255)
		c.red = 255;
	if (c.green > 255)
		c.green = 255;
	if (c.blue > 255)
		c.blue = 255;
	if (c.red < 0)
		c.red = 0;
	if (c.green < 0)
		c.green = 0;
	if (c.blue < 0)
		c.blue = 0;
	return ((((c.red << 8) + c.green) << 8) + c.blue);
}

t_col			ft_set_color(int red, int green, int blue)
{
	t_col ret;

	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;
	ret.red = red;
	ret.green = green;
	ret.blue = blue;
	ret.color = ft_get_color(ret);
	return (ret);
}

t_col			ft_add_color(t_col c1, t_col c2)
{
	t_col ret;

	ret.red = c1.red + c2.red;
	ret.green = c1.green + c2.green;
	ret.blue = c1.blue + c2.blue;
	ret = ft_set_color(ret.red, ret.green, ret.blue);
	return (ret);
}

t_col			ft_mult_color_double(t_col c1, double c2)
{
	t_col ret;

	ret.red = c1.red * c2;
	ret.green = c1.green * c2;
	ret.blue = c1.blue * c2;
	ret = ft_set_color(ret.red, ret.green, ret.blue);
	return (ret);
}

int				ft_color_compare(t_col c1, t_col c2)
{
	int ret;

	ret = 0;
	if (c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue)
		ret = 1;
	return (ret);
}
