/*
** get_fork_map.c for get_fork_map in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Fri Jan 11 08:56:44 2013 nicolas svirchevsky
** Last update Sun Jan 13 17:22:27 2013 nicolas svirchevsky
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"library.h"
#include	"wolf3D.h"

void		get_initial_values(t_data *data)
{
  data->initial = found_initial(data->map);
  data->x_p = data->initial[0];
  data->y_p = data->initial[1];
  data->a = get_the_angle(data);
}
