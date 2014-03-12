/*
** my_strlen.c for my_strlen in /home/svirch_n//.sources/Mini_kit
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Nov 26 12:06:06 2012 nicolas svirchevsky
** Last update Mon Nov 26 12:06:09 2012 nicolas svirchevsky
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i++;
    }
  return (i);
}
