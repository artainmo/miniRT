/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 04:51:40 by artainmo          #+#    #+#             */
/*   Updated: 2020/01/19 04:53:48 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static int g_i;
static char	g_keys[10];
static int g_tmp;

static void	ft_check_keys_plus(int key)
{
	g_tmp = g_i;
	if (g_keys[8] == 'V')
		g_i = 9;
	if (key == KEYCODE_1)
		g_keys[g_i] = '1';
	if (key == KEYCODE_2)
		g_keys[g_i] = '2';
	if (key == KEYCODE_3)
		g_keys[g_i] = '3';
	if (key == KEYCODE_4)
		g_keys[g_i] = '4';
	if (key == KEYCODE_5)
		g_keys[g_i] = '5';
	if (key == KEYCODE_6)
		g_keys[g_i] = '6';
	if (key == KEYCODE_7)
		g_keys[g_i] = '7';
	if (key == KEYCODE_8)
		g_keys[g_i] = '8';
	if (key == KEYCODE_9)
		g_keys[g_i] = '9';
	if (key == KEYCODE_0)
		g_keys[g_i] = '0';
	g_i = g_tmp;
}

static void	ft_check_key1_2(int key)
{
	if (key == KEYCODE_O)
		g_keys[1] = 'O';
	if (key == KEYCODE_W)
		g_keys[1] = 'H';
	if (key == KEYCODE_AU)
		g_keys[2] = 'U';
	if (key == KEYCODE_AD)
		g_keys[2] = 'D';
	if (key == KEYCODE_AL)
		g_keys[2] = 'E';
	if (key == KEYCODE_AR)
		g_keys[2] = 'R';
	if (key == KEYCODE_Z)
		g_keys[2] = 'Z';
	if (key == KEYCODE_B)
		g_keys[2] = 'B';
}

static void	ft_check_key0_1(int key)
{
	if (key == KEYCODE_V)
		g_keys[8] = 'V';
	if (key == KEYCODE_S)
		g_keys[0] = 'S';
	if (key == KEYCODE_L)
		g_keys[0] = 'L';
	if (key == KEYCODE_C)
		g_keys[0] = 'C';
	if (key == KEYCODE_T)
		g_keys[0] = 'T';
	if (key == KEYCODE_Y)
		g_keys[0] = 'Y';
	if (key == KEYCODE_Q)
		g_keys[0] = 'Q';
	if (key == KEYCODE_M)
		g_keys[0] = 'M';
	if (key == KEYCODE_I)
		g_keys[1] = 'I';
	if (key == KEYCODE_P)
		g_keys[1] = 'P';
	if (key == KEYCODE_A)
		g_keys[1] = 'A';
	if (key == KEYCODE_N)
		g_keys[1] = 'N';
}

static void	ft_key_command(t_s *s, char *g_keys)
{
	if (g_keys[8] == 'V')
		s = ft_next_obj(s, g_keys[9] - 48);
	g_keys[g_i] = '\0';
	if (g_keys[0] == 'S')
		ft_key_sp(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	if (g_keys[0] == 'T')
		ft_key_tr(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	if (g_keys[0] == 'Y')
		ft_key_cy(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	if (g_keys[0] == 'M')
		ft_key_pl(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	if (g_keys[0] == 'Q')
		ft_key_sq(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	if (g_keys[0] == 'L')
		ft_key_light(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	if (g_keys[0] == 'C')
		ft_key_cam(s, g_keys, ft_atoi(ft_substr(g_keys, 3, 8)));
	ft_next_image(s);
	g_i = 0;
	ft_bzero(g_keys, 10);
}

int			ft_key(int key, t_s *s)
{
	if (key == KEYCODE_ESC)
	{
		g_i = 0;
		ft_bzero(g_keys, 10);
		ft_exit(s, "You quit the program\n");
	}
	if (key == KEYCODE_DASH)
		ft_key_command(s, g_keys);
	else
	{
		ft_check_key0_1(key);
		ft_check_key1_2(key);
		ft_check_keys_plus(key);
		g_i++;
	}
	return (key);
}
