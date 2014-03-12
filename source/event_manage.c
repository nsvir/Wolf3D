/*
** event_manage.c for event_manage in /home/svirch_n//current_project/wolf3D
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Mon Jan  7 13:41:56 2013 nicolas svirchevsky
** Last update Sun Jan 13 17:26:24 2013 nicolas svirchevsky
*/

#include	<features.h>
#include	<unistd.h>
#include	<math.h>
#include	<stdlib.h>
#include	<X11/X.h>
#include	<mlx.h>
#include	"library.h"
#include	"wolf3D.h"

int		key_press(int keycode, t_event *event)
{
  if (keycode == UP)
    event->up = 1;
  if (keycode == DOWN)
    event->down = 1;
  if (keycode == LEFT)
    event->left = 1;
  if (keycode == RIGHT)
    event->right = 1;
  return (0);
}

int		key_hook(int keycode, t_event *event)
{
  if (keycode == UP)
    event->up = 0;
  if (keycode == DOWN)
    event->down = 0;
  if (keycode == LEFT)
    event->left = 0;
  if (keycode == RIGHT)
    event->right = 0;
  if (keycode == 65307)
    exit(1);
  return (0);
}

int		loop_hook(t_event *event)
{
  if (event->up == 1)
    move(event, 1);
  if (event->down == 1)
    move(event, -1);
  if (event->right == 1)
    event->data->a = ((int) event->data->a + X_SENSITIVE) % 360;
  if (event->left == 1)
    event->data->a = ((int) event->data->a - X_SENSITIVE) % 360;
  usleep(USLEEP);
  back_ground(event->window);
  show_wall(event->window, event->data);
  return (0);
}

t_event		*init_event(t_struct *window)
{
  t_event	*event;

  event = malloc(sizeof(t_event));
  event->window = window;
  event->up = 0;
  event->down = 0;
  event->left = 0;
  event->right = 0;
  return (event);
}

int	event_manage(t_struct *window, t_data *data)
{
  t_event	*event;

  event = init_event(window);
  event->data = data;
  mlx_hook(window->win_ptr, KeyPress, KeyPressMask, key_press, event);
  mlx_key_hook(window->win_ptr, key_hook, event);
  mlx_loop_hook(window->mlx_ptr, loop_hook, event);
  mlx_loop(window->mlx_ptr);
  return (0);
}
