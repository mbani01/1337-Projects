# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamoussa <mamoussa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 10:48:47 by mamoussa          #+#    #+#              #
#    Updated: 2019/10/21 17:35:17 by mamoussa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_toupper.c ft_tolower.c ft_substr.c ft_strlen.c ft_strrchr.c ft_strtrim.c ft_strnstr.c ft_strncmp.c ft_strmapi.c ft_strjoin.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_memccpy.c ft_memmove.c ft_strchr.c ft_split.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_memset.c ft_memcpy.c ft_memcmp.c ft_memchr.c ft_itoa.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c	ft_isascii.c ft_isdigit.c ft_isprint.c 
			
SRCBONUS = *bonus.c

TARGET = *.o

TARGETBONUS = *bonus.o

all : $(NAME)

$(TARGET) : 
		gcc -Wall -Wextra -Werror -c $(SRC)

$(NAME): $(TARGET)
		ar rc $(NAME) $(TARGET)

SRCBONUS : clean
		gcc -Wall -Wextra -Werror -c $(SRCBONUS)	

bonus : SRCBONUS
		ar rs $(NAME) $(TARGETBONUS)

clean :
		rm -rf $(TARGET)

fclean : clean
		rm -rf $(NAME)

re: fclean all