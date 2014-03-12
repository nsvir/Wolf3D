/*
** my_revstr.c for  in /home/svirch_n//afsl/rendu/piscine/Jour_06/ex_03
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Oct  8 10:45:46 2012 nicolas svirchevsky
** Last update Wed Oct 17 14:32:29 2012 nicolas svirchevsky
*/

char	*my_revstr(char *str)
{
  int	i;
  int	cons;
  int	temp;

  i = 0;
  while (str[i + 1] != '\0')
    i++;
  cons = i;
  while (cons - i <  i)
    {
      temp = str [cons - i];
      str[cons - i] = str[i];
      str[i] = temp;
      i--;
    }
  return (str);
}
