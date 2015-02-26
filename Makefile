##
## Makefile for Makefile in /home/dulin_m/rendu/wolf3D
##
## Made by maxime dulin
## Login   <dulin_m@epitech.net>
##
## Started on  Thu Jan  2 11:44:17 2014 maxime dulin
## Last update Thu Jan 30 22:30:57 2014 maxime dulin
##

SRC	= main.c \
	  recup_map.c \
	  get_next_line.c \
	  my_exit.c \
	  calc_wall.c \
	  draw_line.c \
	  calc_xy.c \
	  move_cord.c

CC	= gcc

RM	= rm -f

OBJ	= $(SRC:.c=.o)

LDFLAGS	= -L/usr/lib64 -lmlx_x86_64 -L/usr/lib64/X11 -lXext -lX11 -lm -lmy -L./My_lib/

NAME	= wolf3d

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

libmy:
	make -C ./My_lib/

libmyre:
	make -C ./My_lib/ re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
