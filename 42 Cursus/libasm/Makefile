# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 14:04:53 by mbani             #+#    #+#              #
#    Updated: 2020/02/02 14:24:15 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
OBJ = ft_read.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o ft_write.o
all: $(NAME)

$(NAME):
	nasm -f macho64 ft_read.s
	nasm -f macho64 ft_write.s
	nasm -f macho64 ft_strdup.s
	nasm -f macho64 ft_strcmp.s
	nasm -f macho64 ft_strcpy.s
	nasm -f macho64 ft_strlen.s
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all