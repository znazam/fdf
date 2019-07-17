# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znazam <znazam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 10:44:14 by znazam            #+#    #+#              #
#    Updated: 2019/07/17 11:41:36 by znazam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c grid.c points.c

OBJ = $(patsubst %.c, %.o, $(SRC))

NAME = fdf

HEADERS = fdf.h

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

%.o: %.c $(HEADERS)
	gcc -g -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

updateSubmodules:
	make fclean
	git submodule foreach git checkout master
	git submodule foreach git pull origin master
	git add .
	git commit -m "submodule update"
	git push

.PHONY: LIBFT re fclean clean GNL all updateSubmodules
