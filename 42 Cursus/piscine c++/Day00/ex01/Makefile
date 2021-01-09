# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/31 17:44:20 by mbani             #+#    #+#              #
#    Updated: 2020/12/31 17:48:26 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = crappy
SRC = Classcontact.cpp phonebook.cpp

all : $(name)

$(name) : $(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o $(name)
clean :
	rm -rf $(name)
fclean : clean

re : fclean all