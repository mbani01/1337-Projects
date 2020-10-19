# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 17:51:39 by mbani             #+#    #+#              #
#    Updated: 2020/10/19 11:38:42 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = *.c

all : $(NAME)

$(NAME):
	make -C ../libft
	make -C ../ft_printf
	gcc $(SRC) libft/libft.a ft_printf/libftprintf.a -g 
clean:
	rm -rf a.out
fclean:
	rm -rf a.out
re: fclean all