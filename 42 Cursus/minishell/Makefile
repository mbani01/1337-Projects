# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 17:51:39 by mbani             #+#    #+#              #
#    Updated: 2020/12/13 16:07:13 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = add_echo.c check_for_red.c check_for_red2.c check_for_slash.c cpy_env.c double_pointer_free.c echo_error_checker.c env_var.c expansions.c export_error.c ft_cd.c ft_cd_helper.c ft_echo.c ft_env.c ft_error.c ft_exec1.c ft_exec2.c ft_execution.c ft_exit.c ft_export.c ft_not_builtin.c ft_pipes.c ft_pwd.c ft_unset.c get_next_line.c get_next_line_helper.c get_next_line_utils.c imp_pipes_red.c input_file_cmd.c lexer.c lst.c main_2.c new_node_index.c node_cpy.c not_built_error.c operators.c path_spliter.c print_in_sort.c quotes_handling.c remove_red.c shell.c simple_pointer_free.c str_cpy.c swap_lst.c swap_lst_helper.c syntax_error.c utils.c utils2.c get_next_line_utils2.c

all : $(NAME)

$(NAME):$(SRC)
	make -C ./libft
	gcc -Wall -Wextra -Werror $(SRC) libft/libft.a -g -o minishell
clean:
	rm -rf minishell minishell.dSYM
fclean:
	rm -rf minishell minishell.dSYM
re: fclean all
