/*
** my_tablen.c for my_tablen in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Tue Jan  8 11:44:17 2013 nicolas svirchevsky
** Last update Tue Jan  8 11:44:36 2013 nicolas svirchevsky
*/

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
