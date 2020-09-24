#include "../../miniRT.h"

int max_sp(t_s *s)
{
  int i;

	i = 0;
  s = begin_list(s);
	while(s && s->sp.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int max_pl(t_s *s)
{
  int i;

	i = 0;
  s = begin_list(s);
	while(s && s->pl.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int max_sq(t_s *s)
{
  int i;

	i = 0;
  s = begin_list(s);
	while(s && s->sq.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int max_cy(t_s *s)
{
  int i;

	i = 0;
  s = begin_list(s);
	while(s && s->cy.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int max_tr(t_s *s)
{
  int i;

	i = 0;
  s = begin_list(s);
	while(s && s->tr.status)
	{
		s = s->next;
		i++;
	}
	return (i);
}
