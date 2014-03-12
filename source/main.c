/*
** main.c for  in /home/svirch_n//current_project
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Nov 12 11:15:15 2012 nicolas svirchevsky
** Last update Fri Jan 11 12:53:21 2013 nicolas svirchevsky
*/

#include	<stdlib.h>
#include	"library.h"
#include	"wolf3D.h"

int		main_error(int option)
{
  if (option == 1)
    my_printf("Wrong pathname\n");
  return (-1);
}

int		main(int ac, char **ag)
{
  t_struct	*window;
  t_data	*data;

  if (ac > 1)
    data = get_the_map(ag[1]);
  else
    data = get_the_map(NULL);
  if (data == NULL)
    return (main_error(1));
  if ((window = display(data)) == NULL)
    return (-1);
  event_manage(window, data);
  return (0);
}
