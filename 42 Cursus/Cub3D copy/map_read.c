/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:51:12 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 21:30:24 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	map_help2(t_cor *mlx, int *height, int *weight, int *k)
{
	if (*k == 1)
	{
		mlx->dis = 0;
		g_new = ft_lstnew((*weight * TILE_SIZE) + TILE_SIZE / 2,
		(*height * TILE_SIZE) + TILE_SIZE / 2, mlx->dis);
		ft_lstadd_back(&g_head, g_new);
		*weight += 1;
		mlx->x += TILE_SIZE;
	}
	else
	{
		*weight += 1;
		mlx->x += TILE_SIZE;
	}
}

void	map_help(t_cor *mlx, int *height, int *weight, int *k)
{
	if (g_map[*height][*weight] == '1')
	{
		mlx->x += TILE_SIZE;
		*weight += 1;
	}
	else if (g_map[*height][*weight] == '0')
	{
		mlx->x += TILE_SIZE;
		*weight += 1;
	}
	else if (g_map[*height][*weight] == 'N' || g_map[*height][*weight] == 'S'
	|| g_map[*height][*weight] == 'W' || g_map[*height][*weight] == 'E')
	{
		mlx->i += 1;
		mlx->p = g_map[*height][*weight];
		mlx->x1 = mlx->x + (TILE_SIZE / 2) + mlx->x_step;
		mlx->y1 = mlx->y + (TILE_SIZE / 2) + mlx->y_step;
		mlx->x += TILE_SIZE;
		*weight += 1;
	}
	else if (g_map[*height][*weight] == '2')
		map_help2(mlx, height, weight, k);
	else if (g_map[*height][*weight] != '\0')
		ft_error("Error\n(Player)");
}

void	ft_player(t_cor *mlx, int *k)
{
	if (mlx->i >= 0)
		player_check(mlx->i, mlx->p, *k, mlx);
	else
		ft_error("Error\n(Player)");
}

void	map_render(t_cor *mlx)
{
	int			height;
	int			weight;
	static int	k;

	if (k == 0)
		g_head = NULL;
	k += 1;
	mlx->i = -1;
	mlx->x = 0;
	mlx->y = 0;
	height = 0;
	weight = 0;
	while (g_map[height][weight])
	{
		map_help(mlx, &height, &weight, &k);
		if (g_map[height][weight] == '\0')
		{
			height++;
			weight = 0;
			mlx->y += TILE_SIZE;
			mlx->x = 0;
		}
	}
	ft_player(mlx, &k);
	sp_dis(mlx);
}
