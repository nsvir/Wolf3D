/*
** move.c for move in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Wed Jan  9 20:56:00 2013 nicolas svirchevsky
** Last update Sun Jan 13 18:00:44 2013 nicolas svirchevsky
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<math.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

void		tab_free(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void		get_new_map(t_event *event)
{
  int	i;
  char	*tmp;

  tab_free(event->data->map);
  free(event->data->initial);
  wait(&i);
  event->data->name[my_strlen(event->data->name) - 1]++;
  tmp = event->data->name;
  free(event->data);
  if ((event->data = get_the_map(tmp)) == NULL)
    {
      my_printf("Congratulation\n");
      exit(1);
    }
  back_ground(event->window);
}

void		move(t_event *event, float i)
{
  t_data	*data;
  float		x;
  float		y;
  float		c_x;
  float		c_y;
  float		angle;

  data = event->data;
  angle = data->a / 180 * PI;
  x = data->x_p + (Y_SENSITIVE * cos(angle) * i);
  c_x = data->x_p + ((Y_SENSITIVE * 4) * cos(angle) * i);
  y = data->y_p + (Y_SENSITIVE * sin(angle) * i);
  c_y = data->y_p + ((Y_SENSITIVE * 4) * sin(angle) * i);
  if (x < 0 || y < 0 || (int)y >= my_tablen(data->map) ||
      (int)x >= my_strlen(data->map[(int)y]))
    return;
  if (c_y >= 0 && c_y < my_tablen(data->map) &&
      c_x >= 0 && c_x < my_strlen(data->map[(int)c_y]) &&
      data->map[(int)c_y][(int)c_x] == '3')
    get_new_map(event);
  else
    hitbox('0', data, x, y);
}
