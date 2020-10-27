# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 17:51:39 by mbani             #+#    #+#              #
#    Updated: 2020/10/23 12:15:36 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = *.c

all : $(NAME)

$(NAME):
	make -C ./libft
	gcc $(SRC) libft/libft.a -g
clean:
	rm -rf a.out
fclean:
	rm -rf a.out
re: fclean all