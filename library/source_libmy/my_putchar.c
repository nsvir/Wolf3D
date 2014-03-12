/*
** pseudo_lib.c for  in /home/svirch_n//current_project
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Nov 12 11:17:03 2012 nicolas svirchevsky
** Last update Mon Dec 17 20:52:11 2012 nicolas svirchevsky
*/

#include	<unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
