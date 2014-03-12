/*
** my_putnbr_base.c for  in /afs/epitech.net/users/all/svirch_n/rendu/piscine/Jour_08/ex_02
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Wed Oct 17 15:23:13 2012 nicolas svirchevsky
** Last update Mon Dec 17 21:03:41 2012 nicolas svirchevsky
*/

#include	"library.h"

void	my_putnbr_base(int nbr, char *base)
{
  if (nbr < 0)
    {
      nbr = nbr * -1;
      if (nbr > 0)
	my_putchar('-');
    }
  if (nbr > (my_strlen(base) - 1) || nbr < -(my_strlen(base) - 1))
    my_putnbr_base((nbr / my_strlen(base)), base);
  if (nbr % 10 >= 0)
    my_putchar(base[nbr % my_strlen(base)]);
  else
    my_putchar(base[nbr % my_strlen(base) * -1]);
}
