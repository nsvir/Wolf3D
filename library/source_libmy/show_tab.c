/*
** show_tab.c for show_tab in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Fri Jan 11 13:17:53 2013 nicolas svirchevsky
** Last update Fri Jan 11 15:30:56 2013 nicolas svirchevsky
*/

#include	"library.h"

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
