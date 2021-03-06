/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:34:03 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:34:42 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns zero if not same and one if same
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int n;

	i = 0;
	n = ft_strlen(s2);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && s1[i] && s2[i])
		i++;
	if (n == i)
		return (1);
	else
		return (0);
}
