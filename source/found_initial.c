/*
** found_initial.c for found_initial in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Thu Jan 10 11:49:31 2013 nicolas svirchevsky
** Last update Fri Jan 11 13:10:37 2013 nicolas svirchevsky
*/

#include	<stdio.h>
#include	"library.h"

float	*check_others(float *result, char **tab)
{
  if (result[0] == -1)
    {
      result[1] = (float) my_tablen(tab) / 2;
      result[0] = (float) my_strlen(tab[(int)result[1]]) / 2;
    }
  return (result);
}

float	*found_initial(char **tab)
{
  float	*result;
  int	i;
  int	j;

  i = -1;
  result = xmalloc(sizeof(float) * 2);
  result[0] = -1;
  while (++i < my_tablen(tab))
    {
      j = 0;
      while (j < my_strlen(tab[i]))
	{
	  if (tab[i][j] == '4')
	    {
	      tab[i][j] = '0';
	      if (result[0] == -1)
		{
		  result[0] = j + 0.5;
		  result[1] = i + 0.5;
		}
	    }
	  j++;
	}
    }
  return (check_others(result, tab));
}
