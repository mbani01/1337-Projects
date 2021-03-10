# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 16:27:41 by mbani             #+#    #+#              #
#    Updated: 2021/03/02 16:29:56 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = serialize
SRC = main.cpp serialize.cpp

all : $(name)

$(name) : $(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o $(name)
clean:
	rm -rf $(name)
fclean : clean

re : fclean all