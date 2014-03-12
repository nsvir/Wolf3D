/*
** xstdlib.c for  in /home/svirch_n//current_project/printf
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Tue Nov 13 14:49:15 2012 nicolas svirchevsky
** Last update Mon Dec 17 20:54:22 2012 nicolas svirchevsky
*/

#include	<stdlib.h>
#include	"library.h"

void	*xmalloc(int size)
{
  void	*str;

  str = malloc(size);
  if (str == NULL)
    {
      my_putstr("Memory error\n");
      exit(1);
    }
  else
    return (str);
}
