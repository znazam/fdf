# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znazam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 10:44:14 by znazam            #+#    #+#              #
#    Updated: 2019/07/10 13:40:22 by znazam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

OBJ = $(patsubst %.c, %.o, $(SRC))

NAME = fdf

FLAGS = -Wextra -Werror -Wall -I libft -I GNL -I .

all: LIBFT GNL $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a GNL/get_next_line.o -lmlx -framework OpenGL -framework AppKit

LIBFT:
	git submodule init libft
	git submodule update libft
	make -C libft

GNL:
	git submodule init GNL
	git submodule update GNL
	gcc -c $(FLAGS) GNL/get_next_line.c -o GNL/get_next_line.o

%.o: %.c
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: LIBFT re fclean clean GNL all
