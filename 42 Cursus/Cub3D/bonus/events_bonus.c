/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:16:14 by mbani             #+#    #+#             */
/*   Updated: 2020/01/30 22:45:21 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ft_render(t_cor *mlx)
{
	mlx_destroy_image((mlx)->ptr, (mlx)->img);
	mlx_clear_window((mlx)->ptr, (mlx)->win);
	mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
	cast(mlx);
	map_render(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}

void	ft_check_help(t_cor *mlx)
{
	if (t_go.go_left == 1 && wall_inter(mlx->x1 + 30 * cos((mlx->theta - 90) *
	(M_PI / 180)), mlx->y1 + 30 * sin((mlx->theta - 90) * (M_PI / 180))) != '1'
	&& wall_inter(mlx->x1 + 30 * sin((mlx->theta - 90) * (M_PI / 180)), mlx->y1
	+ 30 * cos((mlx->theta - 90) * (M_PI / 180))) != '2')
	{
		mlx->x_step += cos((mlx->theta - 90) * (M_PI / 180.0)) * 20;
		mlx->y_step += sin((mlx->theta - 90) * (M_PI / 180.0)) * 20;
		ft_render(mlx);
	}
	if (t_go.go_right == 1 && wall_inter(mlx->x1 - 30 * cos((mlx->theta - 90) *
	(M_PI / 180)), mlx->y1 - 30 * sin((mlx->theta - 90) * (M_PI / 180))) != '1'
	&& wall_inter(mlx->x1 - 30 * cos((mlx->theta - 90) * (M_PI / 180)), mlx->y1
	- 30 * sin((mlx->theta - 90) * (M_PI / 180))) != '2')
	{
		mlx->x_step -= cos((mlx->theta - 90) * (M_PI / 180.0)) * 20;
		mlx->y_step -= sin((mlx->theta - 90) * (M_PI / 180.0)) * 20;
		ft_render(mlx);
	}
}

void	ft_check_help2(t_cor *mlx)
{
	if (t_go.see_left == 1)
	{
		mlx->theta -= 10.0;
		ft_render(mlx);
	}
	if (t_go.see_right == 1)
	{
		mlx->theta += 10.0;
		ft_render(mlx);
	}
	see_check(mlx);
	if (t_go.exit == 1)
	{
		exit(0);
	}
}

int		ft_check(t_cor *mlx)
{
	if (t_go.go_for == 1 && wall_inter(mlx->x1 + 30 * cos((mlx->theta) *
	(M_PI / 180)), mlx->y1 + 30 * sin((mlx->theta) * (M_PI / 180))) != '1'
	&& wall_inter(mlx->x1 + 30 * cos((mlx->theta) * (M_PI / 180)), mlx->y1
	+ 30 * sin((mlx->theta) * (M_PI / 180))) != '2')
	{
		mlx->x_step += cos((mlx->theta) * (M_PI / 180.0)) * 20;
		mlx->y_step += sin((mlx->theta) * (M_PI / 180.0)) * 20;
		ft_render(mlx);
	}
	if (t_go.go_back == 1 && wall_inter(mlx->x1 - 30 * cos((mlx->theta) *
	(M_PI / 180)), mlx->y1 - 30 * sin((mlx->theta) * (M_PI / 180))) != '1'
	&& wall_inter(mlx->x1 - 30 * cos((mlx->theta) * (M_PI / 180)), mlx->y1
	- 30 * sin((mlx->theta) * (M_PI / 180))) != '2')
	{
		mlx->x_step -= cos((mlx->theta) * (M_PI / 180.0)) * 20;
		mlx->y_step -= sin((mlx->theta) * (M_PI / 180.0)) * 20;
		ft_render(mlx);
	}
	ft_check_help(mlx);
	ft_check_help2(mlx);
	return (0);
}
