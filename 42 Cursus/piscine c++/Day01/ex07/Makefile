# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 14:56:39 by mbani             #+#    #+#              #
#    Updated: 2021/01/11 15:23:53 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = replace
src = sed.cpp

all : $(name)

$(name) : $(src)
	clang++ -Wall -Wextra -Werror $(src) -o $(name)
clean :
	rm -rf $(name)
fclean : clean
re : fclean all