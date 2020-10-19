/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:13:16 by mbani             #+#    #+#             */
/*   Updated: 2020/02/06 17:08:26 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3d.h"

void	swap_lst(t_list *temp1, t_list *temp_next)
{
	float x;
	float y;
	float dis;

	x = temp_next->x;
	y = temp_next->y;
	dis = temp_next->dis;
	temp_next->x = temp1->x;
	temp_next->y = temp1->y;
	temp_next->dis = temp1->dis;
	temp1->x = x;
	temp1->y = y;
	temp1->dis = dis;
}

void	sort_sprite(t_list **head1)
{
	t_list *temp1;
	t_list *temp_next;

	temp1 = *head1;
	while (temp1)
	{
		temp_next = temp1->next;
		while (temp_next)
		{
			if (temp_next->dis > temp1->dis)
			{
				swap_lst(temp1, temp_next);
				temp_next = temp_next->next;
			}
			else
				temp_next = temp_next->next;
		}
		temp1 = temp1->next;
	}
}

void	ft_sprite(t_cor *mlx, float dis)
{
	float sp_size;
	float x_inter;
	float y_inter;
	float theta_sp;

	g_temp = g_head;
	mlx->sp_dis = dis;
	theta_sp = atan2(g_head->y - mlx->y1, g_head->x - mlx->x1);
	while (theta_sp - (mlx->theta * (M_PI / 180)) > M_PI)
		theta_sp -= 2 * M_PI;
	while (theta_sp - (mlx->theta * (M_PI / 180)) < -M_PI)
		theta_sp += 2 * M_PI;
	if (g_height > g_width)
		sp_size = (g_height / (float)(dis)) * TILE_SIZE;
	else
		sp_size = (g_width / (float)(dis)) * TILE_SIZE;
	y_inter = g_height / 2 - sp_size / 2;
	x_inter = (theta_sp - mlx->theta * (M_PI / 180)) /
	(FOV * (M_PI / 180)) * g_width + (g_width / 2 - sp_size / 2);
	sp_render(mlx, x_inter, y_inter, sp_size);
}

void	sprites(t_cor *mlx)
{
	t_list *temp2;

	temp2 = g_head;
	if (temp2)
	{
		sort_sprite(&g_head);
		temp2 = g_head;
		while (g_head)
		{
			ft_sprite(mlx, g_head->dis);
			g_head = g_head->next;
		}
		g_head = temp2;
	}
}

void	sp_dis(t_cor *mlx)
{
	t_list *tmp;

	tmp = g_head;
	while (tmp)
	{
		tmp->dis = sqrt(pow((tmp->x - mlx->x1), 2) + pow(tmp->y - mlx->y1, 2));
		tmp = tmp->next;
	}
}
