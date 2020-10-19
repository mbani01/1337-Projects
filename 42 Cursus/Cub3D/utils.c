/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:05:38 by mbani             #+#    #+#             */
/*   Updated: 2020/01/20 11:32:51 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

t_list	*ft_lstnew(int x, int y, float dis)
{
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->x = x;
	ptr->y = y;
	ptr->dis = dis;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *p;

	p = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
		new->next = NULL;
	}
}

void	img_put(void *img, int x, int y, int color)
{
	int endian;
	int sizeline;
	int bpp;
	int *add;

	add = (int *)mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	if (x < g_width && y < g_height && x >= 0 && y >= 0)
		add[y * (int)g_width + x] = color;
}

void	player_check(int i, char p, int a, t_cor *mlx)
{
	if (p == 'N' && a == 1)
		mlx->theta = 270;
	else if (p == 'S' && a == 1)
		mlx->theta = 90;
	else if (p == 'E' && a == 1)
		mlx->theta = 0;
	else if (p == 'W' && a == 1)
		mlx->theta = 180;
	if (i == 0)
		(void)i;
	else
	{
		perror("Error\n(Player)");
		exit(0);
	}
	(void)p;
}

void	arg_check1(int argc, char **argv)
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
}
