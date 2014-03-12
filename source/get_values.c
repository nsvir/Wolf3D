/*
** get_values.c for get_values in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Thu Jan 10 12:17:11 2013 nicolas svirchevsky
** Last update Sun Jan 13 17:27:30 2013 nicolas svirchevsky
*/

#include	<math.h>
#include	"library.h"
#include	"wolf3D.h"

double	*get_the_cos()
{
  double	*result;
  double	i;

  i = 0;
  result = xmalloc(sizeof(double) * 360);
  while (i <= 360)
    {
      result[(int)i] = cos(i / 180 * PI);
      i++;
    }
  return (result);
}

double	*get_the_sin()
{
  double	*result;
  double	i;

  i = 0;
  printf("sinus:");
  result = xmalloc(sizeof(double) * 360);
  while (i <= 360)
    {
      result[(int)i] = sin(i / 180 * PI);
      i++;
    }
  return (result);
}
