# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znazam <znazam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/09 10:44:14 by znazam            #+#    #+#              #
#    Updated: 2019/08/07 09:21:11 by znazam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/

SRC_NAME = main.c grid.c points.c images.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

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

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(HEADERS)
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
