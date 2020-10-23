/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:36:33 by artainmo          #+#    #+#             */
/*   Updated: 2019/12/17 17:32:52 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://achedeuzot.me/2014/12/20/installer-la-minilibx/ -> miniLIbx library functions explanation
//https://github.com/keuhdall/images_example -> How to use images with the miniLibx
//https://dev.to/freerangepixels/a-probably-terrible-way-to-render-gradients-1p3n -> colors with RGB values

//https://www.scratchapixel.com/index.php?redirect
//https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing/how-does-it-work
//https://www.scratchapixel.com/code.php?id=3&origin=/lessons/3d-basic-rendering/introduction-to-ray-tracing&src=0
//https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-overview/ray-tracing-rendering-technique-overview?url=3d-basic-rendering/ray-tracing-overview/ray-tracing-rendering-technique-overview
//https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
//http://paulbourke.net/geometry/circlesphere/?fbclid=IwAR3d-TkXNrxT1DXnLav-2Fx3yweJx8w5HzxYTkJd0STDvHR4YiPrGhej-XY
//http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/basic_algo.pdf



#include "miniRT.h"

void *mlx_ptr;
void *mlx_win;
void *im1;

#define w_h 700
#define w_l 700

void	color_map_1(void *mlx_ptr, void *mlx_win,int x,int y)
{
	int ix = x;
  int	color = 255;

	while(y)
	{
		x = ix;
		while(x)
			mlx_pixel_put(mlx_ptr, mlx_win, x--, y, color);
		y--;
	}
}

void	mouse_win1(int button,int x,int y, void *p)
{
	char *s = "HELLO WORLD";
	char *s1 = "HELLO WORLD 2";
	if (button == 1)
	{
		color_map_1(mlx_ptr,mlx_win,w_l,w_h);
		mlx_put_image_to_window(mlx_ptr,mlx_win,im1,w_l/4,w_h/4);
		mlx_string_put(mlx_ptr,mlx_win,w_l/2 - 80,w_l/2,100000,s);
}
	if (button == 2)
	{
		color_map_1(mlx_ptr,mlx_win,w_l,w_h);
		mlx_put_image_to_window(mlx_ptr,mlx_win,im1,w_l/4,w_h/4);
		mlx_string_put(mlx_ptr,mlx_win,w_l/2 - 170,w_l/2,100000,s1);
	}
  //printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y);
}

void	key_win1(int key, void *p)
{
	if (key == 12)
		mlx_destroy_window(mlx_ptr,mlx_win); //If the person clicks on right mouse the window gets destroyed and closes
	else if (key == 8)
		mlx_clear_window(mlx_ptr,mlx_win); //Window turns black again all prior pixels get deleted
	else if (key == 8)
			mlx_clear_window(mlx_ptr,mlx_win);
	else if (key == 0)
	{
		color_map_1(mlx_ptr,mlx_win,w_l,w_h);
		mlx_put_image_to_window(mlx_ptr,mlx_win,im1,w_l/4,w_h/4);
		mlx_string_put(mlx_ptr,mlx_win,w_l/2 - 170, w_l/2 + 40, 100000,"'END'");
		mlx_string_put(mlx_ptr,mlx_win,w_l/2 - 20,w_l/2 + 60,100000,"THANK YOU");
	}
	printf("Key in Win1 : %d\n",key);
}

int main(void)
{
	void *param;
	int x;
	int y;
	char *data;
	int bpp;
	int sl;
	int endian;

	x = 0;
	y = 0;

	if (!(mlx_ptr = mlx_init()))
	{
		ft_putstr_fd("ERROR\nConnection between software and display failed\n", 0);
		exit(0);
	}
	if (!(mlx_win = mlx_new_window(mlx_ptr, w_l, w_h, "MINIRT")))
	{
		ft_putstr_fd("ERROR\nWindow creation failed\n", 0);
		exit(0);
	}
	color_map_1(mlx_ptr,mlx_win,w_l,w_h); //Personal function that uses mlx_pixel_put to fill a square
	//mlx_clear_window(mlx_ptr,mlx_win); //Clears to make space for the new images
	//mlx_destroy_window (mlx_ptr, mlx_win); Destroys the window
	if(!(im1 = mlx_new_image(mlx_ptr,w_l/2,w_h/2))) //Returns a pointer to an image that can be used later on
	{
		ft_putstr_fd("ERROR\nImage one creation failed\n", 0);
		exit(0);
	}
	data = mlx_get_data_addr(im1,&bpp,&sl,&endian);
	/*
	Returns information about the image that can be used to modify
	the image later on or draw in it, bytesperpixel, sizelineimage*4,endianisofrmemorystorage,
	returns a char * address that represents the begining of the memory area where the image is stored,
	Add size line to the adress to get the begining of the second line. You can reach any pixels of the image that way.
	*/
  //color_map_2(mlx_ptr,(unsigned char *)&data,bpp,sl,242,242,endian, 2);
	mlx_put_image_to_window(mlx_ptr,mlx_win,im1,w_l/4,w_h/4);
 	mlx_string_put(mlx_ptr,mlx_win,w_l/2 - 80,w_h/2,100000,"MINIRT");

	mlx_mouse_hook(mlx_win,mouse_win1, 0);
	mlx_key_hook(mlx_win,key_win1, 0);

	//triangle_2d(mlx_ptr, mlx_win, w_l/3, w_h/2,150, 255);
	//triangle_2d_r(mlx_ptr, mlx_win, w_l/3, w_h/2,150, 255);
	//square_2d(mlx_ptr, mlx_win, w_l/3 + 116, w_h/2 - 116,150, 255);
	//square_2d(mlx_ptr, mlx_win, w_l/3 - 150, w_h/2 + 150,150, 255);
	/*
	ft_put_line(w_l/2, w_l/6, w_l/2 + w_l/3, w_l/6, 1000000, 1, mlx_ptr, mlx_win);
	ft_put_line(w_l/2 - w_l/3, w_l - w_l/6, w_l/2, w_l - w_l/6, 1000000, 1, mlx_ptr, mlx_win);
	ft_put_line(w_l/2, w_l/6, w_l/2, w_l - w_l/6, 1000000, 50, mlx_ptr, mlx_win);
	ft_put_line(w_l/2 - w_l/3, w_l/2, w_l/2 + w_l/3, w_l/2, 1000000, 1, mlx_ptr, mlx_win);
	ft_put_line(w_l/2 - w_l/3, w_l/6, w_l/2 - w_l/3, w_l/2, 1000000, 50, mlx_ptr, mlx_win);
	ft_put_line(w_l/2 + w_l/3, w_l/2, w_l/2 + w_l/3, w_l - w_l/6, 1000000, 50, mlx_ptr, mlx_win);
	*/

	mlx_loop(mlx_ptr);
	return (0);
}
