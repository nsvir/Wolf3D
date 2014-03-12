/*
** white_window.c for white_window in /home/svirch_n//current_project/fdf
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Dec  3 09:03:33 2012 nicolas svirchevsky
** Last update Sun Jan 13 17:26:40 2013 nicolas svirchevsky
*/

#include	<stdlib.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

int	get_background_error(int option)
{
  if (option == 1)
    my_printf("Error: mlx_init\n");
  if (option == 2)
    my_printf("Error: mlx_new_window\n");
  return (-1);
}

int		back_ground(t_struct *window)
{
  int		i;
  unsigned int	sky;
  unsigned int	floor;

  i = 0;
  sky = SKY;
  floor = FLOOR;
  while (i < ((Y * X * 4)) / 2)
    {
      window->data[i + 0] = sky % 256;
      window->data[i + 1] = sky / 256 % 256;
      window->data[i + 2] = sky / 256 / 256 % 256;
      window->data[i + 3] = 0;
      i = i + 4;
    }
  while (i < (Y * X * 4))
    {
      window->data[i + 0] = floor % 256;
      window->data[i + 1] = floor / 256 % 256;
      window->data[i + 2] = floor / 256 / 256 % 256;
      window->data[i + 3] = 0;
      i = i + 4;
    }
  return (0);
}

int	get_background(t_struct *window)
{
  if ((window->win_ptr = \
       mlx_new_window(window->mlx_ptr, X, Y, "Wolf3D by svirch_n")) == NULL)
    return (get_background_error(2));
  if ((window->img = mlx_new_image(window->mlx_ptr, X, Y)) == NULL)
    return (-1);
  window->data = mlx_get_data_addr(window->img, &(window->bpp), \
				   &(window->sizeline), &(window->endian));
  back_ground(window);
  return (0);
}
