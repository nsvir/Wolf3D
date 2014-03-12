/*
** my_putstr.c for my_putstr in /home/svirch_n//.sources/Mini_kit
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Nov 26 12:05:50 2012 nicolas svirchevsky
** Last update Sun Jan  6 19:19:28 2013 nicolas svirchevsky
*/

#include	<unistd.h>
#include	"library.h"

void	my_putstr(char *str)
{
  if (str != NULL)
    write(1, str, my_strlen(str));
}
