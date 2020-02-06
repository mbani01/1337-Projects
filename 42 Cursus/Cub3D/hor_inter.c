/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hor_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:17:43 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 21:30:14 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	hor_init(t_cor *mlx)
{
	mlx->xwall = 0;
	mlx->ywall = 0;
	mlx->delta_x = 0;
	mlx->delta_y = 0;
	mlx->new_theta = 0;
	mlx->nextxwall = 0;
	mlx->nextywall = 0;
	mlx->hor_dis = 0;
	mlx->ver_hit = 0;
	mlx->up = 0;
}

void	hor_inter_help(t_cor *mlx)
{
	mlx->delta_x = (TILE_SIZE / tan(mlx->new_theta * M_PI / 180));
	if (mlx->new_theta > 0 && mlx->new_theta < 180)
	{
		mlx->ywall = floor(mlx->y1 / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		mlx->delta_y = TILE_SIZE;
		mlx->up = 0;
	}
	else if (mlx->new_theta <= 360 && mlx->new_theta >= 180)
	{
		mlx->ywall = floor(mlx->y1 / TILE_SIZE) * TILE_SIZE;
		mlx->delta_y = -TILE_SIZE;
		mlx->delta_x *= -1;
		mlx->up = 1;
	}
	mlx->xwall = mlx->x1 +
	(mlx->ywall - mlx->y1) / tan(mlx->new_theta * M_PI / 180);
	mlx->nextxwall = mlx->xwall;
	mlx->nextywall = mlx->ywall;
}

void	hor_inter(t_cor *mlx)
{
	hor_init(mlx);
	nor_angle(mlx);
	hor_inter_help(mlx);
	while (mlx->nextywall < (mlx->map_col * TILE_SIZE) &&
	mlx->nextxwall < (mlx->map_rows * TILE_SIZE) &&
	mlx->nextxwall >= 0 && mlx->nextywall >= 0)
	{
		if (wall_inter2(mlx->nextxwall, mlx->nextywall, mlx) == '1')
		{
			mlx->xwall = mlx->nextxwall;
			mlx->ywall = mlx->nextywall;
			break ;
		}
		else
		{
			mlx->nextxwall += mlx->delta_x;
			mlx->nextywall += mlx->delta_y;
		}
	}
	mlx->hor_dis = sqrt(((mlx->x1 - mlx->nextxwall) *
	(mlx->x1 - mlx->nextxwall)) +
	((mlx->y1 - mlx->nextywall) * (mlx->y1 - mlx->nextywall)));
}
