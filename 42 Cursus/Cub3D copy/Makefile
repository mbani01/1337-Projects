# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 14:30:29 by mbani             #+#    #+#              #
#    Updated: 2020/01/20 10:49:37 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./cub3d

all: $(NAME)

$(NAME):
	gcc *.c -Wall -Wextra -Werror -lmlx -framework appkit -framework opengl -o cub3D
bonus :
	gcc *_bonus.c -Wall -Wextra -Werror -lmlx -framework appkit -framework opengl -o cub3D
clean:
	rm -f ./cub3D

fclean: clean
	rm -f $(NAME)

re: fclean all