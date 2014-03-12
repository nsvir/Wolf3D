/*
** my_strdup.c for my_strdup in /home/svirch_n//.sources/Mini_kit/src
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Dec 17 21:05:49 2012 nicolas svirchevsky
** Last update Mon Dec 17 21:09:53 2012 nicolas svirchevsky
*/

#include	<stdlib.h>
#include	"library.h"

char	*my_strdup(char* str)
{
  char	*result;
  int	i;

  i = 0;
  result = malloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i])
    {
      result[i] = str[i];
      i++;
    }
  result[i] = 0;
  return (result);
}
