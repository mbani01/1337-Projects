/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_directions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:38:14 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 13:40:42 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	north(char **line)
{
	*line += 3;
	rm_sp(line);
	g_npath = ft_strdup1(*line);
}

void	south(char **line)
{
	*line += 3;
	rm_sp(line);
	g_spath = ft_strdup1(*line);
}

void	weast(char **line)
{
	*line += 3;
	rm_sp(line);
	g_wepath = ft_strdup1(*line);
}

void	east(char **line)
{
	*line += 3;
	rm_sp(line);
	g_eapath = ft_strdup1(*line);
}

void	sprite_path(char **line)
{
	*line += 2;
	rm_sp(line);
	g_sprit = ft_strdup1(*line);
}
