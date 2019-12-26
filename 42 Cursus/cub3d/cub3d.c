/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:47:08 by mbani             #+#    #+#             */
/*   Updated: 2019/12/24 15:49:28 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

int g_width;
int g_height;
char **g_map;

void img_put( void *img, int x, int y, int color)
{
	int endian;
    int sizeline;
	int bpp;
	int *add;
	add = (int *)mlx_get_data_addr (img, &bpp, &sizeline, &endian );
    if (x < 1920 && y < 1080 && x >= 0 && y >= 0)
	    add[y * 1920 + x] = color;
}

void rect(int x, int y,void *img, float tile_size)
{
    int lenX;
    int lenY;

    lenX = x + tile_size;
    lenY = y + tile_size;
    while (y <= lenY)
    {
        while (x < lenX)
        {
            while(y != lenY)
            {
                img_put (img, x, y, 199423);
                y++;
            }
            y -=tile_size;
            x++;
        }
        y++;
	}
}
void player(int x, int y,void *img)
{
    // int r = 5;
    // int tempx = x;
    // int tempy = y;
    // float ang=0.0;
    // while (r)
    // {
    //     while (ang <= 360)
    //     {
    //         x = cos(ang * M_PI/180) * r + tempx;
    //         y = sin(ang * M_PI/180) * r + tempy;
            img_put (img, x, y, 14090240);
    //         ang += 0.1;
    //     }
    //     ang = 0;
    //     r--;
    // }
}
char wall_inter(float x, float y)
{
    int x_pos;
    int y_pos;

    x_pos = (int)(x / 100);
    y_pos = (int)(y / 100);
    return (g_map[y_pos][x_pos]);
}
void map_fill(void)
{
    int fd;
    int i;
    char *line;

    i = 0;
    fd = open("map.cub", O_RDONLY);
    while(get_next_line(fd, &line))
    {
        if((line[0] == '1' || line[0] == '0') && (line[0] != '\n'))
        i++;
    }
    free(line);
    line = NULL;
    g_map = malloc(sizeof(char *) * (i + 2));
    i = 0;
    fd = open("map.cub", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        if((line[0] == '1' || line[0] == '0' ) && (line[0] != '\n'))
        { g_map[i] = ft_strdup(line);
        free(line);
        i++;}
    }
    g_map[i] = ft_strdup(line);
    g_map[i + 1] = ft_strdup("\0");
    free(line);
}

void map_render(s_cor *mlx)
{
    int i;
    i = 0;

    int height = 0;
    int weight = 0;
    
    mlx->x=0;
    mlx->y=0;
    mlx->tile_size = 64;
    while(g_map[height][weight])
    {
      if (g_map[height][weight]== '1')
      {
          rect(mlx->x, mlx->y, mlx->img, mlx->tile_size);
          mlx->x +=mlx->tile_size;
          weight++;
      }
      else if (g_map[height][weight] == '0')
      {
          mlx->x +=mlx->tile_size;
          weight++;
      }
      else if (g_map[height][weight] == '2')
      {
        i = 1;
        
        mlx->x1 = mlx->x + (mlx->tile_size / 2) + mlx->x_step;
        mlx->y1 = mlx->y + (mlx->tile_size / 2) + mlx->y_step;
        mlx->x +=mlx->tile_size;
        weight++;
      }
      else if (g_map[height][weight] == ' ')
      weight++;
      if(g_map[height][weight] == '\0')
      {
          height++;
          weight = 0;
          mlx->y +=mlx->tile_size;
          mlx->x = 0;
      }
       if (i == 1)
        {
        player(mlx->x1, mlx->y1, mlx->img);
        }

    }
//     if (i == 1)
//     {
//     player(mlx->x1, mlx->y1, mlx->img);
//     cast(mlx);
//     // rays(mlx->x1, mlx->y1, mlx->img, mlx->theta);
//     // ver_inter(mlx);
// // hor_inter(mlx);
//     }
    
}
    int ft_check(int key, s_cor *mlx)
{
    if(key == 126)
    {
     mlx_destroy_image((mlx)->ptr, (mlx)->img);
     mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
     mlx->x_step += cos((mlx->theta ) * (M_PI / 180.0)) * 10;
     mlx->y_step += sin((mlx->theta) * (M_PI / 180.0)) * 10;
     map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 125)
    {
        mlx_destroy_image((mlx)->ptr, (mlx)->img);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
     mlx->x_step -= cos((mlx->theta) * (M_PI / 180.0)) * 10;
     mlx->y_step -= sin((mlx->theta) * (M_PI / 180.0)) * 10;
     map_render(mlx);
      mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 123)
    {
        mlx->theta -= 10.0;
         mlx_destroy_image((mlx)->ptr, (mlx)->img);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
    map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 124)
    {
        mlx->theta += 10.0;
         mlx_destroy_image((mlx)->ptr, (mlx)->img);
        mlx_clear_window((mlx)->ptr, (mlx)->win);
         mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
         map_render(mlx);
        mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    
    }
    else if (key == 53)
    {
        exit(0);
    }
    return 0;
}

int main()
{
    s_cor *mlx;
    mlx = malloc(sizeof(s_cor));
    mlx->x1=0;
    mlx->y1=0;
    mlx->y_step = 0;
    mlx->x_step = 0;
    mlx->ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->ptr,  1920, 1080, "My Game");
    mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
    map_fill();
    map_render(mlx);
    mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
    mlx_loop(mlx->ptr);
    
}