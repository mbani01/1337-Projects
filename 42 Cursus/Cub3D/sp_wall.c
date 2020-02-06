/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:34:00 by mbani             #+#    #+#             */
/*   Updated: 2020/02/05 17:12:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ver_line(float x, float start_y, float end_y, t_cor *mlx)
{
	int		y;
	float	t;

	y = -1;
	t = 0;
	while (++y < start_y)
		if (x < g_width && y < g_height && x >= 0 && y >= 0)
			img_put(mlx->img, x, y, rgb_to_int(g_sred, g_sgreen, g_sblue));
	while (start_y < end_y)
	{
		mlx->wall_col = mlx->color[(int)(mlx->offset + (int)(t) * mlx->img_w)];
		if (x < g_width && start_y < g_height && x >= 0 && start_y >= 0)
			img_put(mlx->img, x, start_y,
			shadow_effect(mlx->wall_col, mlx->dis));
		t += mlx->factor;
		start_y++;
	}
	y = end_y;
	while (y < g_height)
	{
		if (x < g_width && y < g_height && x >= 0 && y >= 0)
			img_put(mlx->img, x, y, rgb_to_int(g_fred, g_fgreen, g_fblue));
		y++;
	}
}

char	wall_inter(float x, float y)
{
	int x_pos;
	int y_pos;

	x_pos = (int)(x / TILE_SIZE);
	y_pos = (int)(y / TILE_SIZE);
	return (g_map[y_pos][x_pos]);
}

char	wall_inter2(float x, float y, t_cor *mlx)
{
	int x_pos;
	int y_pos;

	if (x == mlx->nextx_ver && mlx->left == 1)
		x--;
	if (y == mlx->nextywall && mlx->up == 1)
		y--;
	x_pos = (int)(x / TILE_SIZE);
	y_pos = (int)(y / TILE_SIZE);
	return (g_map[y_pos][x_pos]);
}

void	nor_angle(t_cor *mlx)
{
	mlx->new_theta = fmod(mlx->theta1, 360);
	while (mlx->new_theta < 0)
		mlx->new_theta += 360;
}
