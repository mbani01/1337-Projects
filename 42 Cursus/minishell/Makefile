# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 17:51:39 by mbani             #+#    #+#              #
#    Updated: 2020/12/09 12:28:30 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = cpy_env.c double_pointer_free.c env_var.c expansions.c ft_cd.c ft_cd_helper.c ft_echo.c ft_env.c ft_error.c ft_execution.c ft_exit.c ft_export.c ft_not_builtin.c ft_pwd.c ft_unset.c get_next_line.c get_next_line_utils.c input_file_cmd.c lexer.c lst.c operators.c path_spliter.c print_in_sort.c quotes_handling.c shell.c simple_pointer_free.c str_cpy.c swap_lst.c syntax_error.c utils.c utils2.c add_echo.c

all : $(NAME)

$(NAME):$(SRC)
	make -C ./libft
	gcc -Wall -Wextra -Werror $(SRC) libft/libft.a -g -o minishell
clean:
	rm -rf minishell
fclean:
	rm -rf minishell
re: fclean all
