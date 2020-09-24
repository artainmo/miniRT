#include "../miniRT.h"

void free_all(void)
{
  t_s	*tmp;

  begin_list();
  while (s)
  {
    tmp = s;
    free(s);
    s = tmp->next;
  }
}

void ft_exit(char *error_message)
{
	ft_putstr_fd(error_message, 0);
	free_all();
	exit(0);
}

void ft_exit_no_free(char *error_message)
{
	ft_putstr_fd(error_message, 0);
	exit(0);
}
