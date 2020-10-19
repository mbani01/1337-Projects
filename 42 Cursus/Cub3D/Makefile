# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbani <mbani@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 14:30:29 by mbani             #+#    #+#              #
#    Updated: 2020/01/20 12:24:06 by mbani            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./cub3D

SRC = bpm.c events.c file_conf.c file_conf2.c file_conf3.c ft_atoi.c ft_colors.c ft_cub3d.c ft_directions.c ft_memcpy.c ft_strdup.c ft_strncmp.c ft_strnstr.c get_next_line.c get_next_line_utils.c hor_inter.c keys.c map_read.c raycasting.c sp_wall.c sprites.c utils.c ver_inter.c

SRC_BONUS = bonus/bpm_bonus.c bonus/events_bonus.c bonus/file_conf2_bonus.c bonus/file_conf3_bonus.c bonus/file_conf_bonus.c bonus/ft_atoi_bonus.c bonus/ft_colors_bonus.c bonus/ft_cub3d_bonus.c bonus/ft_directions_bonus.c bonus/ft_memcpy_bonus.c bonus/ft_strdup_bonus.c bonus/ft_strncmp_bonus.c bonus/ft_strnstr_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/hor_inter_bonus.c bonus/keys_bonus.c bonus/map_read_bonus.c bonus/raycasting_bonus.c bonus/sp_wall_bonus.c bonus/sprites_bonus.c bonus/utils_bonus.c bonus/ver_inter_bonus.c

all: $(NAME)

$(NAME):
	gcc $(SRC) -Wall -Wextra -Werror -lmlx -framework appkit -framework opengl -o $(NAME)
bonus:
	gcc $(SRC_BONUS) -Wall -Wextra -Werror -lmlx -framework appkit -framework opengl -o $(NAME)
clean:
	rm -f ./cub3D

fclean: clean

re: fclean all

.PHONY: re clean fclean bonus
