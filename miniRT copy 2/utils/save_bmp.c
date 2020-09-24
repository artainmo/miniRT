/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 09:21:16 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 09:24:39 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

/*
** BMP file consists of the bmp(bitmap) file header (14bytes), the info header
** (40) bytes, in total 54 header bytes. After comes the color pixel value
** of each pixel, with size of 3 bytes, for red, green, blue. A forth byte
** called rgbreserved must always be set to zero.
** https://web.archive.org/web/20080912171714/http://www.fortunecity.com
** /skyscraper/windows/364/bmpffrmt.html -> More info about bitmap file format
*/

/*
** This function fills the BMP char * further with the image pixel data. Each
** pixel point is composed of four bytes similar to what the BMP file needs
*/

static char	*ft_bmp_pixel_data(t_s *s, char *bmp)
{
	int i;
	int start;

	i = 0;
	start = BMP_HEADER_SIZE + 1;
	while (i < (s->screen.res_x * s->screen.res_y * 4))
	{
		bmp[start + i] = s->screen.data[i];
		i++;
	}
	return (bmp);
}

/*
** One int is 32 bits or 3 bytes and one char is 8 bits or 1 byte to store
** one int inside a char string you need 3 chars, that each take 8bits
*/

static char	*ft_int_to_char(char *bmp, int start, unsigned int integer)
{
	bmp[start] = integer;
	bmp[++start] = integer >> 8;
	bmp[++start] = integer >> 16;
	bmp[++start] = integer >> 24;
	return (bmp);
}

/*
** Through the bzero used earlier the following are already set to zero
** see more in the bmp format specifier why. 6, 8, 30, 34, 38, 42, 46, 50
*/

static char	*ft_bmp_header(t_s *s, char *bmp, unsigned int size_pixel_bytes)
{
	bmp[0] = 'B';
	bmp[1] = 'M';
	bmp = ft_int_to_char(bmp, 2, size_pixel_bytes);
	bmp = ft_int_to_char(bmp, 10, BMP_HEADER_SIZE + 1);
	bmp = ft_int_to_char(bmp, 14, 40);
	bmp = ft_int_to_char(bmp, 18, s->screen.res_x);
	bmp = ft_int_to_char(bmp, 22, s->screen.res_y);
	bmp[28] = s->screen.bpp;
	bmp[28] = s->screen.bpp >> 8;
	return (bmp);
}

/*
** We create the bmp file, fill a char * with the bmp header and the pixel data
** We write that char * onto the file
*/

void		create_bmp(t_s *s, char *filename)
{
	char			*bmp;
	int				fd;
	unsigned int	size_pixel_bytes;

	size_pixel_bytes = s->screen.res_x * s->screen.res_y * 4;
	if (!(bmp = malloc(size_pixel_bytes + BMP_HEADER_SIZE + 1)))
		ft_exit(s, "ERROR\nFailed malloc\n");
	ft_bzero(bmp, size_pixel_bytes + BMP_HEADER_SIZE + 1);
	if ((fd = open(filename, O_CREAT | O_RDWR | O_TRUNC)) == -1)
	{
		free(bmp);
		ft_exit(s, "ERROR\nFailed bmp file opening\n");
	}
	bmp = ft_bmp_header(s, bmp, size_pixel_bytes);
	bmp = ft_bmp_pixel_data(s, bmp);
	write(fd, bmp, (size_pixel_bytes + BMP_HEADER_SIZE));
	free(bmp);
	close(fd);
}

/*
** Creating the bmp file name based on the scene file name plus the bmp
** extension
*/

char		*bmp_filename(t_s *s, char *filename)
{
	int		i;
	char	*ret;

	i = 0;
	while (filename[i] != '.' && filename[i])
		i++;
	if (!(ret = malloc(i + 5)))
		ft_exit(s, "ERROR\nMalloc failed\n");
	ret = ft_memcpy(ret, filename, i);
	ret[i] = '\0';
	ret = ft_strjoin(ret, ".bmp");
	return (ret);
}
