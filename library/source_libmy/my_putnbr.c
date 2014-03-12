/*
** my_putnbr.c for my_putnbr in /home/svirch_n//.sources/Mini_kit
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Nov 26 12:06:18 2012 nicolas svirchevsky
** Last update Mon Dec 17 20:52:50 2012 nicolas svirchevsky
*/

#include	"library.h"

void	my_putnbr(int nbr)
{
  if (nbr < 0)
    {
      nbr = nbr * -1;
      if (nbr > 0)
	my_putchar('-');
    }
  if (nbr > 9 || nbr < -9)
    my_putnbr(nbr / 10);
  if (nbr % 10 >= 0)
    my_putchar(nbr % 10 + 48);
  else
    my_putchar(nbr % 10 * -1 + 48);
}
