##
## Makefile for  in /home/svirch_n//current_project
## 
## Made by nicolas svirchevsky
## Login   <svirch_n@epitech.net>
## 
## Started on  Mon Nov 12 11:14:27 2012 nicolas svirchevsky
## Last update Wed Mar 12 00:39:44 2014 nicolas svirchevsky
##

CC	=	gcc

SRC	=	./source/main.c \
		./source/display.c \
		./source/get_next_line.c \
		./source/hitbox.c \
		./source/get_initial_values.c \
		./source/check_k.c \
		./source/event_manage.c \
		./source/show_wall.c \
		./source/found_initial.c \
		./source/move.c \
		./source/put_wall.c \
		./source/get_the_map.c \
		./source/get_background.c

SRCL	=	library/source_libmy/my_putchar.c		\
		library/source_libmy/my_putstr.c		\
		library/source_libmy/my_strlen.c		\
		library/source_libmy/show_tab.c			\
		library/source_libmy/my_tablen.c		\
		library/source_libmy/my_strdup.c		\
		library/source_libmy/my_putnbr.c		\
		library/source_libmy/my_getnbr.c		\
		library/source_libmy/retmalloc.c		\
		library/source_libmy/my_putnbr_base.c		\
		library/source_libmy/my_getnbr_base.c		\
		library/source_libmy/cmp_char.c			\
		library/source_libmy/my_printf_extend.c		\
		library/source_libmy/my_printf.c		\
		library/source_libmy/xmalloc.c

OBJL	=	$(SRCL:.c=.o)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall -W
CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I./include
CFLAGS	+=	-D_BSD_SOURCE

LIB	=	libmy.a

LDFLAGS =	-lm
LDFLAGS +=	-L ./library/ -lmy -lmlx
LDFLAGS +=	-L /usr/X11/lib -lXext -lX11

NAME	=	wolf3D

all	:	$(NAME)

$(NAME) :	$(LIB) $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(LIB)	:	$(OBJL)
		ar rc $(LIB) $(OBJL)
		ranlib $(LIB)
		mv $(LIB) ./library/

clean	:
		rm -f $(OBJ)
		rm -f $(OBJL)

fclean	:	clean
		rm -f $(NAME)
		rm -f $(LIB)

re	:	clean $(NAME)
