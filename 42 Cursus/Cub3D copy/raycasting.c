/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:32:33 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 21:30:27 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	cast_init(t_cor *mlx, int *i, double *ang_var, float *save)
{
	mlx->dis = 0;
	*i = 0;
	mlx->offset = 0;
	*ang_var = (float)FOV / (float)g_width;
	mlx->theta1 = mlx->theta - FOV / 2;
	*save = mlx->theta + FOV / 2;
	g_temp = g_head;
	if (!(mlx->img_tex_n =
	mlx_xpm_file_to_image(mlx->ptr, g_npath, &mlx->x_pt, &mlx->y1_pt))
	|| !(mlx->img_tex_s = mlx_xpm_file_to_image(mlx->ptr, g_spath,
	&mlx->x_pt, &mlx->y_pt)) ||
	!(mlx->img_tex_e = mlx_xpm_file_to_image(mlx->ptr,
	g_eapath, &mlx->x_pt, &mlx->y2_pt))
	|| !(mlx->img_tex_w = mlx_xpm_file_to_image(mlx->ptr,
	g_wepath, &mlx->x_pt, &mlx->y3_pt)))
		ft_error("wrong_path");
}

void	cast_help(t_cor *mlx)
{
	int a;

	mlx->dis = mlx->hor_dis;
	mlx->hor_hit = 1;
	mlx->offset = fmod(mlx->nextxwall, TILE_SIZE);
	if (mlx->up == 1)
	{
		mlx->img_add = mlx_get_data_addr(mlx->img_tex_s, &a, &a, &a);
		mlx->img_w = mlx->y_pt;
	}
	else
	{
		mlx->img_add = mlx_get_data_addr(mlx->img_tex_e, &a, &a, &a);
		mlx->img_w = mlx->y2_pt;
	}
	mlx->color = (int *)mlx->img_add;
}

void	cast_help2(t_cor *mlx)
{
	int a;

	mlx->dis = mlx->ver_dis;
	mlx->ver_hit = 1;
	mlx->offset = fmod(mlx->nexty_ver, TILE_SIZE);
	if (mlx->left == 1)
	{
		mlx->img_add = mlx_get_data_addr(mlx->img_tex_n, &a, &a, &a);
		mlx->img_w = mlx->y1_pt;
	}
	else
	{
		mlx->img_add = mlx_get_data_addr(mlx->img_tex_w, &a, &a, &a);
		mlx->img_w = mlx->y3_pt;
	}
	mlx->color = (int *)mlx->img_add;
}

void	cast(t_cor *mlx)
{
	float	save;
	int		i;
	double	ang_var;

	map_render(mlx);
	cast_init(mlx, &i, &ang_var, &save);
	while (mlx->theta1 <= save)
	{
		ver_inter(mlx);
		hor_inter(mlx);
		if (mlx->ver_dis > mlx->hor_dis)
			cast_help(mlx);
		else
			cast_help2(mlx);
		mlx->dis *= cos((mlx->theta1 - mlx->theta) * M_PI / 180);
		draw_wall(mlx, (float)i);
		mlx->wall_dis[i] = mlx->dis;
		mlx->theta1 += ang_var;
		i++;
	}
	sprites(mlx);
}
