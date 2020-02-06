/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:47:08 by mbani             #+#    #+#             */
/*   Updated: 2020/01/20 11:29:29 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

static int g_wall_start;

void	draw_wall(t_cor *mlx, float i)
{
	int start;
	int end;

	start = 0;
	end = 0;
	mlx->dis_proj = (g_width / 2) / tan(((float)FOV / 2) * M_PI / 180);
	mlx->wall_height = (TILE_SIZE / mlx->dis * cos(((float)FOV / 2)
	* M_PI / 180)) * mlx->dis_proj;
	mlx->factor = mlx->img_w / mlx->wall_height;
	start = (g_height - mlx->wall_height) / 2 + g_wall_start;
	end = (g_height + mlx->wall_height) / 2 + g_wall_start;
	ver_line(i, start, end, mlx);
}

void	see_check(t_cor *mlx)
{
	if (t_go.see_up == 1 && g_wall_start >= -g_height)
	{
		g_wall_start -= 20;
		ft_render(mlx);
	}
	if (t_go.see_down == 1 && g_wall_start <= g_height)
	{
		g_wall_start += 20;
		ft_render(mlx);
	}
}

void	sp_render(t_cor *mlx, int x, int y, int sp_size)
{
	int *add;
	int i;
	int j;

	i = -1;
	sp_check(mlx, &add);
	while (++i < sp_size)
	{
		if (x + i < 0 || x + i > g_width)
			continue;
		if (g_head->dis > mlx->wall_dis[x + i] &&
				(g_head->dis - mlx->wall_dis[x + i]) > 40)
			continue;
		j = -1;
		while (++j < sp_size)
		{
			if (y + j + g_wall_start < 0 || y + j + g_wall_start > g_height)
				continue;
			mlx->color_sp = add[(mlx->x_s *
					(j * mlx->y_s / sp_size)) + (i * mlx->x_s / sp_size)];
			if (mlx->color_sp != add[0])
				img_put(mlx->img, (x + i), y + j + g_wall_start,
						shadow_effect(mlx->color_sp, mlx->sp_dis));
		}
	}
}

int		main(int argc, char **argv)
{
	t_cor *mlx;

	mlx = malloc(sizeof(t_cor));
	mlx->x = 0;
	mlx->y = 0;
	mlx->x1 = 0;
	mlx->y1 = 0;
	mlx->y_step = 0;
	mlx->x_step = 0;
	arg_check1(argc, argv);
	file_cub(mlx, argv[1]);
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, g_width, g_height, "Cub3D");
	mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
	map_render(mlx);
	cast(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 0, ft_keypress, 0);
	mlx_hook(mlx->win, 3, 0, ft_keyrel, 0);
	mlx_hook(mlx->win, 17, 0, ft_exit, NULL);
	mlx_loop_hook(mlx->ptr, ft_check, mlx);
	arg_check(argc, argv, mlx);
	mlx_loop(mlx->ptr);
}
