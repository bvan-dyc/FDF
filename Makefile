#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 22:53:24 by bvan-dyc          #+#    #+#              #
#    Updated: 2016/01/28 15:59:59 by arucinsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fdf

CFLAGS=-Wall -Wextra -Werror

SRC=src/main.c src/matrice.c src/read.c src/get_next_line.c src/keyhook.c \
src/draw.c src/tools.c src/isometric.c src/parallel.c src/display.c

OBJS=matrice.o read.o main.o get_next_line.o keyhook.o tools.o draw.o \
isometric.o parallel.o display.o

$(NAME):
	gcc $(CFLAGS) -L libft/ -lft -l mlx \
	-framework OpenGL -framework AppKit $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) rm -rf $(OBJS)

re: fclean all

.PHONY: clean fclean
