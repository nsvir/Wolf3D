/*
** my_getnbr_base.c for  in /afs/epitech.net/users/all/svirch_n/rendu/piscine/Jour_08/ex_02
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Wed Oct 17 15:19:48 2012 nicolas svirchevsky
** Last update Sun Jan 13 17:18:52 2013 nicolas svirchevsky
*/

#include	"library.h"

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	b;
  int	nbr;
  int	multi;
  int	signe;

  nbr = 0;
  multi = 1;
  signe = 1;
  if (str[0] == '-')
    {
      signe = signe *  -1;
      str = &str[1];
    }
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      b = 0;
      while (str [i] != base [b])
	b = b + 1;
      nbr = nbr + b * multi;
      multi = multi * my_strlen(base);
      i--;
    }
  return (nbr * signe);
}
