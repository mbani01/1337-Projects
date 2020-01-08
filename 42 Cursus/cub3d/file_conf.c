/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 14:11:05 by mbani             #+#    #+#             */
/*   Updated: 2020/01/08 10:04:58 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

void res_check(char *line)
{
	g_width = ft_atoi(line);
	while (*line != ' ')
		line++;
	g_height = ft_atoi(line + 1);
	g_width = g_width > 2560 ? 2560 : g_width;
	g_height = g_height > 1440 ? 1440 : g_height;
	if (g_height <= 0 || g_width <= 0)
	{
		perror("Error\n(Resolution)");
		exit(0);
	}
	
}

void floor_col(char *line)
{
    g_fred = ft_atoi(line);
    while (*line != ',')
    line++;
    line += 1;
    g_fgreen = ft_atoi(line);
    while (*line != ',')
    line++;
    g_fblue = ft_atoi(line + 1);
    if (g_fred > 255 || g_fred < 0 || g_fgreen > 255 || g_fgreen < 0 || g_fblue > 255 || g_fblue < 0)
    {
		perror("Error\n(Color)");
		exit(0);
	}
}

void sky_col(char *line)
{
    g_sred = ft_atoi(line);
    while (*line != ',')
    line++;
    line += 1;
    g_sgreen = ft_atoi(line);
    while (*line != ',')
    line++;
    g_sblue = ft_atoi(line + 1);
    if (g_sred > 255 || g_sred < 0 || g_sgreen > 255 || g_sgreen < 0 || g_sblue > 255 || g_sblue < 0)
    {
		perror("Error\n(Color)");
		exit(0);
	}
}

void file_check(char *line)
{
	if (line [0] ==  'R')
		res_check((line + 2));
    else if (line[0] == 'F')
        floor_col(line + 2);
    else if (line[0] == 'C')
        sky_col(line + 2);
    else if (line[0] == 'N' && line[1] == 'O')
        g_npath = ft_strdup1(line + 3);
    else if (line[0] == 'S' && line[1] == 'O')
        g_spath = ft_strdup(line + 3);   
    else if (line[0] == 'W' && line[1] == 'E')
        g_wepath = ft_strdup(line + 3);
    else if (line[0]  == 'E' && line[1] == 'A')
        g_eapath = ft_strdup(line + 3);
    else if (line [0] == 'S')
        g_sprit = ft_strdup(line + 3);
    else if (line[0] == '1' || line[0] == '0' || line[0] == ' ' || line[0] == '\0')
        (void) line;
    else
    {
		perror("Error\n(File)");
		exit(0);
    }
    
}
void map_check(int j, t_cor *mlx)
{
    int i;
    int k;
    
    i = 0;
	while (g_map[0][i] && g_map[j][i])
    {
        if(g_map[0][i] == '0' || g_map[j][i] == '0')
        {
        perror("Error\n(invalid map)");
		exit(0);
        }
        i++;
    }
    i = 0;
    k = ft_strlen(g_map[0]) - 1;
    while (g_map[i][0] && g_map[i][k] && i <= j)
    {
       if(g_map[i][0] == '0' || g_map[i][k] == '0' || ft_strlen(g_map[i]) != k + 1)
        {
        perror("Error\n(invalid map)");
		exit(0);
        }
        i++;
    }
    mlx->map_rows = k + 1;
}
void map_fil(int i, t_cor *mlx)
{
	int fd;
	char *line;

	g_map = malloc(sizeof(char *) * (i + 2));
    i = 0;
    fd = open("map.cub", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        if((line[0] == '1' || line[0] == '0'))
        {
			g_map[i] = ft_strdup1(line);
        free(line);
        i++;
		}
        else if (line[0] == '\0' && i > 0)
        {
        perror("Error\n(invalid map)");
		exit(0);
        }       
    }
    if((line[0] == '1' || line[0] == '0'))
    {g_map[i] = ft_strdup1(line);
    g_map[i + 1] = ft_strdup1("\0");
    }
    else
    {g_map[i] = ft_strdup1("\0");
    i--;}
    free(line);
	map_check(i, mlx);
    
}
void file_cub(t_cor *mlx)
{
    int fd;
    int i;
    char *line;

    i = 0;
    fd = open("map.cub", O_RDONLY);
    while(get_next_line(fd, &line))
    {
        if((line[0] == '1' || line[0] == '0'))
        i++;
		else
		file_check(line);
		free(line);
    }
    free(line);
    line = NULL;
   map_fil(i, mlx);
   mlx->map_col = i;
}