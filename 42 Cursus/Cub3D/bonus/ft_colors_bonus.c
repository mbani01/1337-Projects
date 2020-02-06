/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:51:41 by mbani             #+#    #+#             */
/*   Updated: 2020/01/18 19:50:28 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int		rgb_to_int(int r, int g, int b)
{
	int rgb;

	rgb = 0;
	rgb = r * pow(256, 2) + g * 256 + b;
	return (rgb);
}

int		shadow_effect(int rgb, float dis)
{
	int r;
	int g;
	int b;

	r = fmod(rgb / 256 / 256, 256);
	g = fmod((rgb / 256), 256);
	b = fmod(rgb, 256);
	if ((dis / 64) > 1.5)
	{
		r = fmod(rgb / 256 / 256, 256) / (dis / 90);
		g = fmod((rgb / 256), 256) / (dis / 90);
		b = fmod(rgb, 256) / (dis / 90);
	}
	return (rgb_to_int(r, g, b));
}

void	color_check(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line == ',')
			i++;
		if (!ft_isdigit(*line))
		{
			perror("Error\n(Colors)");
			exit(0);
		}
		line++;
	}
	if (i != 2)
	{
		perror("Error\n(Colors)");
		exit(0);
	}
}

void	sky_col(char *line)
{
	rm_sp(&line);
	color_check(line);
	g_sred = ft_atoi(line);
	while (*line != ',')
		line++;
	g_sgreen = ft_atoi(line + 1);
	line += 1;
	while (*line != ',')
		line++;
	g_sblue = ft_atoi(line + 1);
	if (g_sred > 255 || g_sred < 0 || g_sgreen > 255 || g_sgreen < 0
	|| g_sblue > 255 || g_sblue < 0)
	{
		perror("Error\n(Color)");
		exit(0);
	}
}

void	floor_col(char *line)
{
	rm_sp(&line);
	color_check(line);
	g_fred = ft_atoi(line);
	while (*line != ',')
		line++;
	g_fgreen = ft_atoi(line + 1);
	line += 1;
	while (*line != ',')
		line++;
	g_fblue = ft_atoi(line + 1);
	if (g_fred > 255 || g_fred < 0 || g_fgreen > 255
	|| g_fgreen < 0 || g_fblue > 255 || g_fblue < 0)
	{
		perror("Error\n(Color)");
		exit(0);
	}
}
