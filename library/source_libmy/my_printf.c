/*
** my_printf.c for  in /home/svirch_n//current_project/printf
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Tue Nov 13 16:50:07 2012 nicolas svirchevsky
** Last update Mon Dec 17 20:51:40 2012 nicolas svirchevsky
*/

#include	<stdarg.h>
#include	"library.h"

char		*printf_converter(char *fmt, va_list ap)
{
  long	int	p;

  if (*(fmt) == 'b')
    manage_sign(va_arg(ap, int), "01");
  if (*(fmt) == 'o')
    manage_sign(va_arg(ap, int), "01234567");
  if (*(fmt) == 'u')
    manage_sign(va_arg(ap, int), "0123456789");
  if (*(fmt) == 'x')
    manage_sign(va_arg(ap, int), "0123456789abcdef");
  if (*(fmt) == 'X')
    manage_sign(va_arg(ap, int), "0123456789ABCDEF");
  if (*(fmt) == 'p')
    {
      p = (long int) va_arg(ap, long int);
      if (p != 0)
	{
	  my_putstr("0x");
	  my_putnbr_base(p, "0123456789abcdef");
	}
      else
	my_putstr("(nil)");
    }
  fmt = fmt + 1;
  return (fmt);
}

char		*unmatched(char *fmt)
{
  if (*(fmt) != '%')
    my_putchar(*(fmt - 1));
  my_putchar(*(fmt));
  return (fmt + 1);
}

char		*my_special_putstr(char *str, char *fmt)
{
  int	i;

  i = 0;
  if (*(fmt) == 's')
    my_putstr(str);
  else
    while (str[i] != 0)
      {
	if (str[i] < 32 || str[i] >= 127)
	  {
	    my_putchar('\\');
	    if (str[i] < 0)
	      my_putstr("000");
	    else if (str[i] < 8)
	      my_putstr("00");
	    else if (str[i] < 80)
	      my_putstr("0");
	    my_putnbr_base((long int) (str[i]), "01234567");
	  }
	else
	  my_putchar(str[i]);
	i++;
      }
  return (fmt + 1);
}

char		*printf_matching(char *fmt, va_list ap)
{
  while (cmp_char(*(fmt - 1), " %+-10'#") == 1)
    {
      if (*(fmt) == 's' || *(fmt) == 'S')
	return (my_special_putstr(va_arg(ap, char*), fmt));
      else if (*(fmt) == 'd' || *(fmt) == 'i')
	{
	  my_putnbr(va_arg(ap, int));
	  return (fmt + 1);
	}
      else if (*(fmt) == 'c')
	{
	  my_putchar(va_arg(ap, int));
	  return (fmt + 1);
	}
      else if (cmp_char(*(fmt), "eEfFgGaAm") != 0)
	va_arg(ap, double);
      else if (cmp_char(*(fmt), "n") != 01)
	va_arg(ap, int*);
      else if (cmp_char(*(fmt), "ouxXbp") != 0)
	return (printf_converter(fmt, ap));
      else if (cmp_char(*(fmt), " +-10'#") == 0 || *(fmt) == '%')
	return (unmatched(fmt));
      fmt = fmt + 1;
    }
  return (fmt);
}

int		my_printf(char *fmt, ...)
{
  va_list	ap;

  va_start(ap, fmt);
  while (*fmt)
    {
      if (*fmt == '%')
	fmt = printf_matching(fmt + 1, ap);
      else
	{
	  my_putchar(*fmt);
	  fmt++;
	}
    }
  va_end(ap);
  return (0);
}
