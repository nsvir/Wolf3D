/*
** compare_char_to_str.c for  in /home/svirch_n//current_project/printf/my_printf-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Sun Nov 18 11:26:55 2012 nicolas svirchevsky
** Last update Mon Dec 17 21:03:42 2012 nicolas svirchevsky
*/

int	cmp_char(char c, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == c)
	j++;
      i++;
    }
  return (j);
}
