# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/31 17:32:28 by mbani             #+#    #+#              #
#    Updated: 2020/12/31 17:36:41 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = megaphone
SRC = megaphone.cpp

all : $(name)

$(name) : $(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o $(name)
clean :
	rm -rf $(name)
fclean : clean

re : fclean all