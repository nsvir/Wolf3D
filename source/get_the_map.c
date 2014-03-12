/*
** get_the_map.c for get_the_map in /home/svirch_n//current_project/wolf3D/wolf3d-2017-svirch_n
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Jan  7 15:43:34 2013 nicolas svirchevsky
** Last update Sun Jan 13 17:24:21 2013 nicolas svirchevsky
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<stdlib.h>
#include       	<fcntl.h>
#include	"library.h"
#include	"wolf3D.h"

int		my_listlen(t_list *begin)
{
  int	i;

  i = 0;
  while (begin)
    {
      begin = begin->next;
      i++;
    }
  return (i);
}

char		**list_to_str(t_list *begin)
{
  t_list	*tmp;
  char		**result;
  int		i;

  i = 0;
  if (!begin)
    return (NULL);
  result = xmalloc(sizeof(char*) * (my_listlen(begin) + 1));
  while (begin)
    {
      result[i] = begin->data;
      tmp = begin;
      begin = begin->next;
      free(tmp);
      i++;
    }
  result[i] = NULL;
  return (result);
}

char		**get_read(int fd)
{
  t_list	*begin;
  t_list	*elem;
  t_list	*first;
  char		*buff;

  begin = NULL;
  first = NULL;
  while ((buff = get_next_line(fd)) != NULL)
    {
      elem = xmalloc(sizeof(t_list));
      if (!begin)
	first = elem;
      elem->data = my_strdup(buff);
      if (begin)
	begin->next = elem;
      begin = elem;
      free(buff);
    }
  if (begin)
    begin->next = NULL;
  return (list_to_str(first));
}

float		get_the_angle(t_data *data)
{
  int	a;

  a = 0;
  (void) a;
  if (data->x_p + 1 < my_strlen(data->map[(int)data->y_p]))
    if (data->map[(int)data->y_p][(int)data->x_p + 1] != '1')
      return (0);
  if (data->y_p - 1 >= 0)
    if (data->map[(int)data->y_p - 1][(int)data->x_p] != '1')
      return (270);
  if (data->x_p - 1 >= 0)
    if (data->map[(int)data->y_p][(int)data->x_p - 1] != '1')
      return (180);
  if (data->y_p + 1 < my_tablen(data->map))
    if (data->map[(int)data->y_p + 1][(int)data->x_p] != '1')
      return (90);
  return (0);
}

t_data		*get_the_map(char *str)
{
  t_data	*data;
  int		fd;

  fd = 0;
  (void) str;
  data = xmalloc(sizeof(t_data));
  if (str == NULL)
    data->name = my_strdup("map/maze0");
  else
    data->name = str;
  if ((fd = open(data->name, O_RDONLY)) == -1)
    return (NULL);
  my_printf("%s\n", data->name);
  data->map = get_read(fd);
  close(fd);
  get_initial_values(data);
  return (data);
}
