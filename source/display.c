/*
** main.c for  in /home/svirch_n//current_project
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Nov 12 11:15:15 2012 nicolas svirchevsky
** Last update Sun Jan 13 17:24:10 2013 nicolas svirchevsky
*/

#include	<mlx.h>
#include	<stdlib.h>
#include	"library.h"
#include	"wolf3D.h"

t_struct	*display_erreur(int option)
{
  if (option == 1)
    my_printf("Error: mlx_init\n");
  return (NULL);
}

t_struct	*display(t_data *data)
{
  t_struct	*window;

  window = xmalloc(sizeof(t_struct));
  if ((window->mlx_ptr = mlx_init()) == NULL)
    return (display_erreur(1));
  if (get_background(window) == -1)
    return (NULL);
  show_wall(window, data);
  return (window);
}
