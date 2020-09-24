#include "../../miniRT.h"

int max_cam(t_s *s)
{
	int i;

	i = 0;
  s = begin_list(s);
	while(s && s->camera.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int max_light(t_s *s)
{
  int i;

	i = 0;
  s = begin_list(s);
	while(s && s->light.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}
