/*
** hitbox.c for hitbox in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Sun Jan 13 16:51:07 2013 nicolas svirchevsky
** Last update Sun Jan 13 18:02:22 2013 nicolas svirchevsky
*/

#include	<math.h>
#include	"library.h"
#include	"wolf3D.h"

int		hitbox_cos(char **map, char c, float y, float x)
{
  float		i;

  i = 0;
  while (i < 360)
    {
      if (map[(int)y][(int)(x + HIT)] != c)
	return (1);
      if (map[(int)y][(int)(x - HIT)] != c)
	return (1);
    }
  (void)map;
  return (0);
}

int		hitbox_sin(char **map, char c, float y, int x)
{
  float		i;

  i = 0;
  while (i < 360)
    {
      if (map[(int)(y + (HIT * sin(i / 180 * PI)))][x] != c)
	return (1);
      i += 0.01;
    }
  return (0);
}

int		hit(char **map, char c, float y, float x)
{
  if (map[(int)y][(int)(x + HIT)] != c)
    return (1);
  if (map[(int)y][(int)(x - HIT)] != c)
    return (1);
  if (map[(int)(y - HIT)][(int)x] != c)
    return (1);
  if (map[(int)(y + HIT)][(int)x] != c)
    return (1);
  if (map[(int)(y - HIT / 2)][(int)(x - HIT / 2)] != c)
    return (1);
  if (map[(int)(y + HIT / 2)][(int)(x - HIT / 2)] != c)
    return (1);
  if (map[(int)(y + HIT / 2)][(int)(x + HIT / 2)] != c)
    return (1);
  if (map[(int)(y - HIT / 2)][(int)(x + HIT / 2)] != c)
    return (1);
  return (0);
}

int		hitbox(char c, t_data *data, float x, float y)
{
  char		**map;

  map = data->map;
  if (y - HIT >= 0 && y + HIT < my_tablen(map) &&
      x - HIT >= 0 && x + HIT < my_strlen(map[(int)y]) &&
      hit(map, c, y, x) == 0)
    {
      data->y_p = y;
      data->x_p = x;
    }
  return (0);
}
