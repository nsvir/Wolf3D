/*
** mini_lib.h for mini_lib in /home/svirch_n//current_project/myls-2017-svirch_n/mini_lib
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@pc-svirch_n>
** 
** Started on  Sun Dec  2 12:03:12 2012 nicolas svirchevsky
** Last update Fri Jan 11 15:31:30 2013 nicolas svirchevsky
*/

#ifndef	_LIBRARY_H_
# define _LIBRARY_H_

int	my_strlen(char*);
int	my_tablen(char**);
void	show_tab(char**);
int	cmp_char(char, char*);
int	my_getnbr(char*);
int	my_printf(char*, ...);
int	my_getnbr_base(char*, char*);
char	*my_revstr(char*);
char	*my_strdup(char*);
void	my_putnbr_base(int, char *);
void	manage_sign(int, char*);
void	my_put_unsigned_nbr(unsigned int);
void	*xmalloc(int);
void	*retmalloc(int);
void	my_putstr(char*);
void	my_putchar(char);
void	my_putnbr(int);

#endif /* !_LIBRARY_H_ */
