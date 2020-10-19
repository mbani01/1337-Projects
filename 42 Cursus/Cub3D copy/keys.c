/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:08:27 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 20:17:49 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int		ft_keypress(int key)
{
	if (key == 13)
		t_go.go_for = 1;
	if (key == 1)
		t_go.go_back = 1;
	if (key == 0)
		t_go.go_left = 1;
	if (key == 2)
		t_go.go_right = 1;
	if (key == 125)
		t_go.see_up = 1;
	if (key == 126)
		t_go.see_down = 1;
	if (key == 124)
		t_go.see_right = 1;
	if (key == 123)
		t_go.see_left = 1;
	if (key == 53)
		t_go.exit = 1;
	if (key == 7)
		t_go.jump = 1;
	return (0);
}

int		ft_keyrel(int key)
{
	if (key == 13)
		t_go.go_for = -1;
	if (key == 1)
		t_go.go_back = -1;
	if (key == 0)
		t_go.go_left = -1;
	if (key == 2)
		t_go.go_right = -1;
	if (key == 125)
		t_go.see_up = -1;
	if (key == 126)
		t_go.see_down = -1;
	if (key == 124)
		t_go.see_right = -1;
	if (key == 123)
		t_go.see_left = -1;
	if (key == 53)
		t_go.exit = -1;
	if (key == 7)
		t_go.jump = -1;
	return (0);
}

int		ft_exit(void)
{
	exit(0);
	return (0);
}

void	arg_check(int argc, char **argv, t_cor *mlx)
{
	if (argc != 2 && argc != 3)
	{
		perror("Error\n(arguments)");
		exit(0);
	}
	if (!(ft_strnstr(argv[1], ".cub\0", ft_strlen(argv[1]))))
	{
		perror("Error\n(.cub)");
		exit(0);
	}
	if (ft_strncmp(argv[2], "--save", 6) == 0)
	{
		bmp_file(mlx);
		exit(0);
	}
}

void	sp_check(t_cor *mlx, int **add)
{
	if (!(mlx->img_sp =
	mlx_xpm_file_to_image(mlx->ptr, g_sprit, &mlx->x_s, &mlx->y_s)))
		ft_error("wrong_path");
	*add = (int *)mlx_get_data_addr(mlx->img_sp, &mlx->a, &mlx->a, &mlx->a);
}
