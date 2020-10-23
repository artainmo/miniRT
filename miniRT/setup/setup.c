/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 08:57:52 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:02:16 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void		ft_search_setup(int *i, int *l, char *line)
{
	while (!(line[*i] >= '0' && line[*i] <= '9') && line[*i] != '-')
		*i = *i + 1;
	*l = *i;
	while ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '.'
			|| line[*i] == '-')
		*i = *i + 1;
}

static void	ft_find_setup(t_s *s, char *line)
{
	if (line[0] == 'R')
		ft_setup_resolution(s, line);
	if (line[0] == 'A')
		ft_setup_ambient_light(s, line);
	if (line[0] == 'c' && line[1] != 'y')
		ft_setup_camera(s, line);
	if (line[0] == 'l')
		ft_setup_light(s, line);
	if (line[0] == 's' && line[1] == 'p')
		ft_setup_sphere(s, line);
	if (line[0] == 'p' && line[1] == 'l')
		ft_setup_plane(s, line);
	if (line[0] == 's' && line[1] == 'q')
		ft_setup_square(s, line);
	if (line[0] == 'c' && line[1] == 'y')
		ft_setup_cylinder(s, line);
	if (line[0] == 't' && line[1] == 'r')
		ft_setup_tr(s, line);
}

t_s			*ft_setup(t_s *s, int fd)
{
	int		ret;
	char	*line;

	s = ft_setup_init(s);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			ft_exit_no_free("ERROR\nProblem with file reading");
		ft_find_setup(s, line);
		free(line);
	}
	ft_find_setup(s, line);
	free(line);
	close(fd);
	ft_misconfiguration(s);
	return (s);
}
