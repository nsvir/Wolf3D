/*
** show_wall.c for show_wall in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Tue Jan  8 09:29:16 2013 nicolas svirchevsky
** Last update Sun Jan 13 17:23:52 2013 nicolas svirchevsky
*/

#include	<mlx.h>
#include	<math.h>
#include	<stdlib.h>
#include	"library.h"
#include	"wolf3D.h"

void	get_vector(t_data *data, float i)
{
  float	d;
  float	p;
  float	x;
  float	y;

  d = 0.5;
  p = 1;
  x = d;
  y = (p / 2) - (i / X);
  data->x_v = x * cos(data->a / 180 * PI) - y * sin(data->a / 180 * PI);
  data->y_v = x * sin(data->a / 180 * PI) + y * cos(data->a / 180 * PI);
}

int	show_wall(t_struct *window, t_data *data)
{
  int	i;

  i = 0;
  while (i < X)
    {
      get_vector(data, i);
      check_wall(data, i, window);
      i += 1;
    }
  mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img, 0, 0);
  return (0);
}
