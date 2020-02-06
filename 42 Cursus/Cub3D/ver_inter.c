/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:34:05 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 21:30:38 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ver_init(t_cor *mlx)
{
	mlx->x_ver = 0;
	mlx->y_ver = 0;
	mlx->deltax_ver = 0;
	mlx->deltay_ver = 0;
	mlx->nextx_ver = 0;
	mlx->nexty_ver = 0;
	mlx->nextx_ver = 0;
	mlx->nexty_ver = 0;
	mlx->ver_dis = 0;
	mlx->left = 0;
	mlx->wallx_ver = 0;
	mlx->wally_ver = 0;
	mlx->ver_hit = 0;
}

void	ver_inter_help(t_cor *mlx)
{
	mlx->deltay_ver = TILE_SIZE * tan(mlx->new_theta * M_PI / 180);
	if (mlx->new_theta >= 270 || mlx->new_theta <= 90)
	{
		mlx->deltax_ver = TILE_SIZE;
		mlx->x_ver = floor(mlx->x1 / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		mlx->left = 0;
	}
	else
	{
		mlx->deltax_ver = -TILE_SIZE;
		mlx->x_ver = floor(mlx->x1 / TILE_SIZE) * TILE_SIZE;
		mlx->deltay_ver *= -1;
		mlx->left = 1;
	}
	mlx->y_ver = mlx->y1 + (mlx->x_ver - mlx->x1) *
	tan((mlx->new_theta) * M_PI / 180);
	mlx->nextx_ver = mlx->x_ver;
	mlx->nexty_ver = mlx->y_ver;
}

void	ver_inter(t_cor *mlx)
{
	ver_init(mlx);
	nor_angle(mlx);
	ver_inter_help(mlx);
	while (mlx->nexty_ver < (mlx->map_col * TILE_SIZE) &&
	mlx->nextx_ver < (mlx->map_rows * TILE_SIZE) &&
	mlx->nextx_ver >= 0 && mlx->nexty_ver >= 0)
	{
		if (wall_inter2(mlx->nextx_ver, mlx->nexty_ver, mlx) == '1')
		{
			mlx->y_ver = mlx->nexty_ver;
			mlx->x_ver = mlx->nextx_ver;
			break ;
		}
		else
		{
			mlx->nexty_ver += mlx->deltay_ver;
			mlx->nextx_ver += mlx->deltax_ver;
		}
	}
	mlx->ver_dis = sqrt(((mlx->x1 - mlx->nextx_ver) *
	(mlx->x1 - mlx->nextx_ver)) +
	((mlx->y1 - mlx->nexty_ver) * (mlx->y1 - mlx->nexty_ver)));
}
