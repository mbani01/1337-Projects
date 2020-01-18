/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:51:41 by mbani             #+#    #+#             */
/*   Updated: 2020/01/18 16:26:59 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	int rgb;

	rgb = 0;
	rgb = r * pow(256, 2) + g * 256 + b;
	return (rgb);
}

int	shadow_effect(int rgb, float dis)
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
