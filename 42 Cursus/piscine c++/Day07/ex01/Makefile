# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 11:57:38 by mbani             #+#    #+#              #
#    Updated: 2021/03/05 11:57:55 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = iter
SRC = main.cpp

all : $(name)

$(name) : $(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o $(name)
clean :
	rm -rf $(name)
fclean : clean

re : fclean all