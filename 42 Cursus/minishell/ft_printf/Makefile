# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 10:58:28 by mbani             #+#    #+#              #
#    Updated: 2019/11/16 11:11:13 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC = check.c flags.c fprint.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_itoa_u.c ft_printf.c ft_put.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strlowcase.c noflagsprint.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) *.o

bonus:
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rs $(NAME) *.o
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
