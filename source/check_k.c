/*
** check_k.c for check_k in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Sat Jan 12 15:19:52 2013 nicolas svirchevsky
** Last update Sun Jan 13 21:33:51 2013 nicolas svirchevsky
*/

#include	"library.h"
#include	"wolf3D.h"

float	check_right(t_data *data)
{
  float	k;
  int	x;
  int	y;

  x = (int)data->x_p + 1;
  while (x < my_strlen(data->map[(int)data->y_p]))
    {
      k = ((float)x - data->x_p) / data->x_v;
      y = data->y_p + (k * data->y_v);
      if (y >= 0 && y < my_tablen(data->map))
	if (data->map[y][x] == '1' || data->map[y][x] == '3')
	  {
	    if (data->map[y][x] == '3')
	      data->wall_type_x = 2;
	    else
	      data->wall_type_x = 0;
	    return (k);
	  }
      x++;
    }
  return (100000);
}

float	check_left(t_data *data)
{
  float	k;
  int	x;
  int	y;

  x = (int)data->x_p;
  while (x >= 0)
    {
      k = ((float)x - data->x_p) / data->x_v;
      y = data->y_p + (k * data->y_v);
      if (y >= 0 && y < my_tablen(data->map))
	if ((x - 1) >= 0 && (data->map[y][x - 1] == '1' ||
			     data->map[y][x - 1] == '3'))
	  {
	    if (data->map[y][x - 1] == '3')
	      data->wall_type_x = 2;
	    else
	      data->wall_type_x = 0;
	    return (k);
	  }
      x--;
    }
  return (100000);
}

float	check_up(t_data *data)
{
  float	k;
  int	x;
  int	y;

  y = (int)data->y_p;
  while (y >= 0)
    {
      k = ((float)y - data->y_p) / data->y_v;
      x = data->x_p + (k * data->x_v);
      if (x >= 0 && x < my_strlen(data->map[y]))
	if ((y - 1) >= 0 && (data->map[y - 1][x] == '1' ||
			     data->map[y - 1][x] == '3'))
	  {
	    if (data->map[y - 1][x] == '3')
	      data->wall_type_y = 2;
	    else
	      data->wall_type_y = 1;
	    return (k);
	  }
      y--;
    }
  return (100000);
}

float	check_down(t_data *data)
{
  float k;
  int	x;
  int	y;

  y = (int)data->y_p + 1;
  while (y < my_tablen(data->map))
    {
      k = ((float)y - data->y_p) / data->y_v;
      x = data->x_p + (k * data->x_v);
      if (x >= 0 && x < my_strlen(data->map[y]))
	if (data->map[y][x] == '1' || data->map[y][x] == '3')
	  {
	    if (data->map[y][x] == '3')
	      data->wall_type_y = 2;
	    else
	      data->wall_type_y = 1;
	    return (k);
	  }
      y++;
    }
  return (100000);
}

void	check_wall(t_data *data, int i, t_struct *window)
{
  float	k_x;
  float	k_y;
  float	k;

  data->wall_type = 0;
  if (data->x_v >= 0)
    k_x = check_right(data);
  else
    k_x = check_left(data);
  if (data->y_v <= 0)
    k_y = check_up(data);
  else
    k_y = check_down(data);
  if (k_y - k_x <= 0.000001)
    {
      k = k_y;
      data->wall_type = data->wall_type_y;
    }
  else
    {
      k = k_x;
      data->wall_type = data->wall_type_x;
    }
  put_wall(i, k, window, data);
}
