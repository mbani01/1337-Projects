# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 17:51:39 by mbani             #+#    #+#              #
#    Updated: 2020/11/13 16:27:43 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = *.c

all : $(NAME)

$(NAME):
	make -C ./libft
	gcc -Wall -Wextra -Werror $(SRC) libft/libft.a -g
clean:
	rm -rf a.out
fclean:
	rm -rf a.out
re: fclean all