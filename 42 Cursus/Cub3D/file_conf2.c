/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_conf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:42:49 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 13:37:32 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int		ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ',')
		return (1);
	else
		return (0);
}

void	res_error(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if ((*line > '9' || *line < '0') && *line != ' ')
			ft_error("Error\n(Resolution)");
		if (*line == ' ')
		{
			i += 1;
			line += 1;
			rm_sp(&line);
		}
		line++;
	}
	if (i != 1)
	{
		perror("Error\n(Resolution)");
		exit(0);
	}
}

void	res_check(char *line)
{
	rm_sp(&line);
	res_error(line);
	g_width = ft_atoi(line);
	while (*line != ' ')
		line++;
	rm_sp(&line);
	g_height = ft_atoi(line);
	g_width = g_width > 2560 ? 2560 : g_width;
	g_height = g_height > 1440 ? 1440 : g_height;
	if (g_height <= 0 || g_width <= 0)
	{
		perror("Error\n(Resolution)");
		exit(0);
	}
}

void	rm_sp(char **s)
{
	while (**s == ' ')
		*s += 1;
}
