#include "miniRT.h"

/*
** Raytracing is a realistic but demanding computer graphics technique
** It consists of sending a ray through each screen pixel
** and testing with math if the ray/line intersects with the sphere
** If it does the color needs to be calculated of the pixel based on the
** object and surrounding lighting in the scene
*/

/*
** To manage the data given by .rt file a chained list of structure s is used,
** s contains structures for all objects. Each time a second object
** of the same kind needs to be stored the chained list goes on to the next
** list, whereby all values are initialized first and then appropriate value is
** given to the appropriate duplicative objects. Thus there will always be as
** many chained lists as there will be objects of the same kind.
*/

static void ft_user_guide(void)
{
  ft_putstr_fd("s:sphere\n a:radius\n p:centrum sphere\n", 0);
  ft_putstr_fd("t:triangle\n p:psoition\n", 0);
  ft_putstr_fd("q:square\n a:side\n p:position\n o:orientation", 0);
  ft_putstr_fd("m:plane\n o:orientation\n p:position\n", 0);
  ft_putstr_fd("y:cylinder\n a:radius\n h:height\n o:orien\n p:posi\n", 0);
  ft_putstr_fd("l:light\n i:intensity\n p:position\n", 0);
  ft_putstr_fd("c:camera\n p:position\n n:next\n o:orientation\n", 0);
  ft_putstr_fd("Use arrows to increase, decrease or move\n", 0);
  ft_putstr_fd("Type a number, default 10, type backslach to command\n", 0);
  ft_putstr_fd("Access different objects\n Type v, number obj ", 0);
  ft_putstr_fd("(if your number is too high it goes back to the first ob)", 0);
  ft_putstr_fd(" after type the commands you want to execute on that ob\n", 0);
  ft_putstr_fd("Press ESC or left click the red cross to exit cleanly\n", 0);
}

/*
** Opens the file tests if no error occurs and returns the file descriptor
*/
static int ft_get_fd(char *filename)
{
	int fd;
	int i;

	i = 0;
	while (filename[i] != '.' && filename[i])
		i++;
	if (!filename[i] || i == 0 || !ft_strcmp(&filename[i], ".rt"))
		ft_exit_no_free("ERROR\nWrong file input\n");
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_exit_no_free("ERROR\nFile opening failed\n");
	return (fd);
}

/*
** Takes inside s structure the pointers to mlx, window, image, image data,..
*/
static t_s *window_setup(t_s *s)
{
	if (!(s->screen.mlx_ptr = mlx_init()))
		ft_exit_no_free("ERROR\nConnection between software and dis->ss->play failed\n");
	if (!(s->screen.mlx_win = mlx_new_window(s->screen.mlx_ptr, s->screen.res_x,
				s->screen.res_y, "miniRT")))
		ft_exit_no_free("ERROR\nWindow creation failed\n");
  if (!(s->screen.mlx_image = mlx_new_image(s->screen.mlx_ptr,
          s->screen.res_x, s->screen.res_y)))
    ft_exit_no_free("ERROR\nImage creation failed\n");
  	s->screen.data = mlx_get_data_addr(s->screen.mlx_image, &s->screen.bpp,
          &s->screen.size_line, &s->screen.endian);
  return (s);
}

/*
** Puts created image on screen
** mlx_clear_window clears the window and put image puts the image to window
** mlx_key_hook waits on keyboard commands to execute them
** mlx_loop creates an infinite loop that allows key_hook to wait on a command
*/
void create_window(t_s *s)
{
  s->screen.window_status = 1;
  ft_user_guide();
  mlx_clear_window(s->screen.mlx_ptr, s->screen.mlx_win);
  mlx_put_image_to_window(s->screen.mlx_ptr, s->screen.mlx_win,
        s->screen.mlx_image, 0, 0);
  mlx_key_hook(s->screen.mlx_win, ft_key, s);
  mlx_mouse_hook(s->screen.mlx_win, ft_mouse, s);
  mlx_loop(s->screen.mlx_ptr);
}

/*
** The setup function gives all objects in the scene their appropriate value
** screen iterate is the base raycasting function that will create an image
** Depending on the given arguments a window will be created or a bmp file
*/
int main(int argc, char **argv)
{
  t_s *s;

	if (argc != 2 && argc != 3)
		ft_exit_no_free("ERROR\nWrong number of pararmeters\n");
	s = ft_setup(s, ft_get_fd(argv[1]));
	s = window_setup(s);
	s = screen_iterate(s);
	if (argc == 2)
	 create_window(s);
	else if (argc == 3 && ft_strcmp(argv[2], "--save"))
		create_bmp(s, bmp_filename(s, argv[1]));
	else
		ft_exit(s, "ERROR\nWrong arguments");
	return (0);
}
