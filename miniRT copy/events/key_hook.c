#include "../miniRT.h"

static int i;
static char keys[10];
static int tmp;

static void ft_check_keys_plus(int key)
{
  tmp = i;
  if (keys[8] == 'V')
    i = 9;
  if (key == KEYCODE_1)
    keys[i] = '1';
  if (key == KEYCODE_2)
    keys[i] = '2';
  if (key == KEYCODE_3)
    keys[i] = '3';
  if (key == KEYCODE_4)
    keys[i] = '4';
  if (key == KEYCODE_5)
    keys[i] = '5';
  if (key == KEYCODE_6)
    keys[i] = '6';
  if (key == KEYCODE_7)
    keys[i] = '7';
  if (key == KEYCODE_8)
    keys[i] = '8';
  if (key == KEYCODE_9)
    keys[i] = '9';
  if (key == KEYCODE_0)
    keys[i] = '0';
  i = tmp;
}

static void ft_check_key1_2(int key)
{
  if (key == KEYCODE_O)
    keys[1] = 'O';
  if (key == KEYCODE_W)
    keys[1] = 'H';
  if (key == KEYCODE_AU)
    keys[2] = 'U';
  if (key == KEYCODE_AD)
    keys[2] = 'D';
  if (key == KEYCODE_AL)
    keys[2] = 'E';
  if (key == KEYCODE_AR)
    keys[2] = 'R';
  if (key == KEYCODE_Z)
    keys[2] = 'Z';
  if (key == KEYCODE_B)
    keys[2] = 'B';
}

static void ft_check_key0_1(int key)
{
  if (key == KEYCODE_V)
    keys[8] = 'V';
  if (key == KEYCODE_S)
    keys[0] = 'S';
  if (key == KEYCODE_L)
    keys[0] = 'L';
  if (key == KEYCODE_C)
    keys[0] = 'C';
  if (key == KEYCODE_T)
    keys[0] = 'T';
  if (key == KEYCODE_Y)
    keys[0] = 'Y';
  if (key == KEYCODE_Q)
    keys[0] = 'Q';
  if (key == KEYCODE_M)
    keys[0] = 'M';
  if (key == KEYCODE_I)
    keys[1] = 'I';
  if (key == KEYCODE_P)
    keys[1] = 'P';
  if (key == KEYCODE_A)
    keys[1] = 'A';
  if (key == KEYCODE_N)
    keys[1] = 'N';
}

static void ft_key_command(t_s *s, char *keys)
{
  if (keys[8] == 'V')
      s = ft_next_obj(s, keys[9] - 48);
  keys[i] = '\0';
  if (keys[0] == 'S')
     ft_key_sp(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  if (keys[0] == 'T')
      ft_key_tr(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  if (keys[0] == 'Y')
      ft_key_cy(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  if (keys[0] == 'M')
      ft_key_pl(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  if (keys[0] == 'Q')
      ft_key_sq(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  if (keys[0] == 'L')
      ft_key_light(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  if (keys[0] == 'C')
      ft_key_cam(s, keys, ft_atoi(ft_substr(keys, 3, 8)));
  ft_next_image(s);
  i = 0;
  ft_bzero(keys, 10);
}

int ft_key(int key, t_s *s)
{
  if (key == KEYCODE_ESC)
  {
    i = 0;
    ft_bzero(keys, 10);
	  ft_exit(s, "You quit the program\n");
  }
  if (key == KEYCODE_DASH)
    ft_key_command(s, keys);
  else
  {
    ft_check_key0_1(key);
    ft_check_key1_2(key);
    ft_check_keys_plus(key);
    i++;
  }
  return (key);
}
