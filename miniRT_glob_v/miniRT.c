#include "miniRT.h"

/*
** Rays->tracing is a realistic but demanding computer graphics technique
** It consists of sending a ray through each s->screen pixel
** and testing with math if the ray/line intersects with the s->sphere
** If it does the color needs to be calculated of the pixel based on the
** object and surrounding s->lighting in the scene
*/

/*
** Global variable is used because containing values are constant
*/
t_s *s;


static void ft_user_guide(void)
{
  ft_putstr_fd("s:sphere\na:radius\np:centrum sphere\n", 0);
  ft_putstr_fd("t:triangle\np:psoition\n", 0);
  ft_putstr_fd("q:square\na:side\np:position\no:orientation", 0);
  ft_putstr_fd("m:plane\no:orientation\np:position\n", 0);
  ft_putstr_fd("y:cylinder\na:radius\nh:height\no:orientation\np:posi\n", 0);
  ft_putstr_fd("l:light\ni:intensity\np:position\n", 0);
  ft_putstr_fd("c:camera\np:position\nn:next\no:orientation", 0);
  ft_putstr_fd("Use arrows to increase, decrease or move\n", 0);
  ft_putstr_fd("Type a number, default 10\nType backslach to command", 0);
}

/*
** Creating the bmp file name based on the scene file name plus the bmp
** extension
*/
static char *bmp_filename(char *filename)
{
	int i;
	char *ret;

	i = 0;
	while (filename[i] != '.' && filename[i])
		i++;
	if (!(ret = malloc(i + 5)))
		ft_exit("ERROR\nMalloc failed\n");
	ret = ft_memcpy(ret, filename, i);
	ret[++i] = '\0';
	ret = ft_strjoin(ret, ".bmp");
	return (ret);
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
		ft_exit_no_free("ERROR\nWrong file input1\n");
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_exit_no_free("ERROR\nWrong file input2\n");
	return (fd);
}

/*
** Creates the pixelated screen and returns error if necessary
*/
static void window_creation(void)
{
	if (!(s->screen.mlx_ptr = mlx_init()))
		ft_exit_no_free("ERROR\nConnection between software and dis->ss->play failed\n");
	if (!(s->screen.mlx_win = mlx_new_window(s->screen.mlx_ptr, s->screen.resolution_x,
				s->screen.resolution_y, "miniRT")))
		ft_exit_no_free("ERROR\nWindow creation failed\n");
}

/*
** The setup function gives all objects in the scene their appropriate value
** s->screen iterate is the base raycasting function that will create an image
** misconfiguration function will exit the program if necessary
** mlx_key_hook waits on keyboard commands to execute them
** mlx_loop creates an infinite loop that allows key_hook to wait on a command
** To quit the program and free adequately use the key 'q'
*/
int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		ft_exit_no_free("ERROR\nWrong number of pararmeters\n");
	ft_setup(ft_get_fd(argv[1]));
	window_creation();
	screen_iterate();
	mlx_key_hook(s->screen.mlx_win, ft_key, 0);
	if (argc == 2)
	{
		mlx_key_hook(s->screen.mlx_win, ft_key, 0);
		mlx_loop(s->screen.mlx_ptr);
		ft_user_guide();
	}
	//else if (argc == 3 && ft_strcmp(argv[2], "--save"))
		//create_bmp(bmp_filename(argv[1]));
	else
		ft_exit("ERROR\nWrong second argument");
	return (0);
}
