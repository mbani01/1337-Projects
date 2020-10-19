/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_conf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 13:42:28 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 14:01:45 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void	ft_error(char *s)
{
	perror(s);
	exit(0);
}

void	file_check(char *line)
{
	static int i;

	if (line[0] == 'R' && (i += 1) > 0)
		res_check((line + 2));
	else if (line[0] == 'F' && (i += 1) > 0)
		floor_col(line + 2);
	else if (line[0] == 'C' && (i += 1) > 0)
		sky_col(line + 2);
	else if (line[0] == 'N' && line[1] == 'O' && (i += 1) > 0)
		north(&line);
	else if (line[0] == 'S' && line[1] == 'O' && (i += 1) > 0)
		south(&line);
	else if (line[0] == 'W' && line[1] == 'E' && (i += 1) > 0)
		weast(&line);
	else if (line[0] == 'E' && line[1] == 'A' && (i += 1) > 0)
		east(&line);
	else if (line[0] == 'S' && (i += 1) > 0)
		sprite_path(&line);
	else if (line[0] == '1' || line[0] == '0'
	|| line[0] == ' ' || line[0] == '\0')
		(void)line;
	else
		ft_error("Error\n(File)");
	if (i > 8)
		ft_error("Error\n(Duplicated)");
}

void	map_check(int j, t_cor *mlx)
{
	int i;
	int k;

	i = 0;
	while (g_map[0][i++] && g_map[j][i])
		if (g_map[0][i] == '0' || g_map[j][i] == '0')
			ft_error("Error\n(invalid map)");
	i = 0;
	k = ft_strlen(g_map[0]) - 1;
	while (g_map[i][0] && g_map[i][k] && i <= j)
	{
		if (g_map[i][0] == '0' || g_map[i][k] == '0'
		|| (int)ft_strlen(g_map[i]) != k + 1)
			ft_error("Error\n(invalid map)");
		i++;
	}
	mlx->map_rows = k + 1;
}
