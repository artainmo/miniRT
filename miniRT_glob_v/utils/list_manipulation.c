#include "../miniRT.h"

void begin_list(void)
{
  s = s->first;
}

t_s *iter_list_new(int *counter)
{
  if (!s->next)
    s->next = ft_setup_new();
  s = s->next;
  *counter = *counter + 1;
  return (s);
}

void iter_list(void (*function)(void))
{
  begin_list();
  while(s->next)
  {
    function();
    s = s->next;
  }
  function();
  begin_list();
}

int max_cam(void)
{
	int i;
  t_s *m_cam;

	i = 0;
  begin_list();
  m_cam = s;
	while(m_cam && m_cam->camera.status)
	{
		m_cam = m_cam->next;
		i++;
	}
	return (i);
}
