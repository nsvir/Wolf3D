/*
** renome.h for  in /home/svirch_n//current_project
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Nov 12 11:19:14 2012 nicolas svirchevsky
** Last update Wed Mar 12 00:40:01 2014 nicolas svirchevsky
*/

#ifndef _WOLF3D_H_
# define _WOLF3D_H_

/*# define X 1920
# define Y 1080*/
# define X 1280
# define Y 720
# define ALPHA -90
# define USLEEP 10000
# define HIT 0.065
# define Y_SENSITIVE 0.060
# define X_SENSITIVE 2
# define SKY 0x000099FF
# define FLOOR 0x00006600
# define WALL_1 0x00404040
# define WALL_2 0x00505050
# define WALL_3 0x00606060
# define WALL_4 0x00353535
# define END 0x00330066
# define READ_SIZE 200
# define PI 3.14159265358979323846
# define ECHAP 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define D 100
# define Q 113
# define LEFT 65361
# define ABS(x, y) (x > y) ? (x - y) : (y - x)
# define MAX(x, y) (x > y) ? (x) : (y)

typedef struct s_struct
{
  int	x;
  int	y;
  void	*mlx_ptr;
  void	*win_ptr;
  void	*stage_img;
  void	*stage_data;
  void	*img;
  char	*data;
  int	bpp;
  int	sizeline;
  int	endian;
} t_struct;

typedef struct s_data
{
  char	**map;
  char	*name;
  float	*initial;
  float	x_p;
  float	y_p;
  float	x_v;
  float	y_v;
  float	a;
  float	k;
  char	wall_type;
  char	wall_type_x;
  char	wall_type_y;
} t_data;

typedef struct s_event
{
  t_struct	*window;
  t_data	*data;
  char		up;
  char		down;
  char		left;
  char		right;
} t_event;

typedef struct	s_list
{
  char		*data;
  struct s_list	*next;
} t_list;

int		hitbox(char c, t_data *data, float x, float y);
void		simple_move(t_event*, char);
void		move(t_event*, float);
void		check_wall(t_data*, int, t_struct*);
void		put_wall(int, float, t_struct*, t_data*);
void		get_initial_values(t_data *);
void		check_wall(t_data*, int, t_struct*);
char		*get_next_line(const int);
int		back_ground(t_struct*);
int		manage_expose(t_struct*);
int		manage_key(int, t_struct*);
int		get_background(t_struct*);
int		pixel_img(t_struct*, int, int, unsigned int);
int		event_manage(t_struct*, t_data*);
int		show_wall(t_struct*, t_data*);
float		*found_initial(char**);
float		get_the_angle(t_data *);
t_data		*get_the_map(char*);
char		**get_the_tab(char*);
char		**get_read(int);
char		*get_next_line(const int);
t_struct	*display(t_data*);

#endif /* !_WOLF3D_H_ */
