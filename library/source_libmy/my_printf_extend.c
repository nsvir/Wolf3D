/*
** my_printf_extend.c for my_printf_extend in /home/svirch_n//current_project/my_ls/mini_lib/my_printf-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Wed Nov 28 09:05:28 2012 nicolas svirchevsky
** Last update Mon Dec 17 20:52:00 2012 nicolas svirchevsky
*/

#include	"library.h"

void	manage_sign(int nbr, char *base)
{
  if (nbr < 0)
    my_putnbr_base((unsigned int) nbr, base);
  else
    my_putnbr_base(nbr, base);
}
void	my_put_unsigned_nbr(unsigned int nbr)
{
  if (nbr > 9)
    my_putnbr(nbr/10);
  my_putchar(nbr % 10 + 48);
}
