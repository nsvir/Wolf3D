/*
** my_getnbr.c for my_getnbr in /home/svirch_n//.sources/Mini_kit
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Nov 26 12:06:40 2012 nicolas svirchevsky
** Last update Mon Dec 17 20:51:11 2012 nicolas svirchevsky
*/

#include	"library.h"

int		my_getnbr(char *str)
{
  int		i;
  unsigned int	nbr;
  int		multi;
  int		signe;

  signe = 1;
  multi = 1;
  nbr = 0;
  i = 0;
  if (str[0] == '-')
    {
      signe = -1;
      str = &str[1];
    }
  i = -1;
  while (str[++i] != '\0' && str[i] >= '0' && str[i] <= '9');
  while ((i - 1) >= 0)
    {
      nbr = nbr + (str[i - 1] - '0') * multi;
      multi = multi * 10;
      i--;
    }
  if (nbr > 2147483647 || (my_strlen(str) >= 10 && str[0] > '2'))
    return (0);
  return ((nbr * signe));
}
