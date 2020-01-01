/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:47:08 by mbani             #+#    #+#             */
/*   Updated: 2020/01/01 18:07:15 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"



void img_put( void *img, int x, int y, int color)
{
	int endian;
    int sizeline;
	int bpp;
	int *add;
	add = (int *)mlx_get_data_addr (img, &bpp, &sizeline, &endian);
    if (x < g_width && y < g_height && x >= 0 && y >= 0)
	    add[y * (int)g_width + x] = color;
}

void rect(int x, int y,void *img)
{
    int lenX;
    int lenY;

    lenX = x + (tile_size * 0.25);
    lenY = y + (tile_size * 0.25);
    while (y <= lenY)
    {
        while (x < lenX)
        {
            while(y != lenY)
            {
                img_put (img, x, y, 199423);
                y++;
            }
            y -= (tile_size * 0.25);
            x++;
        }
        y++;
	}
}
void ray(int x, int y,void* img, float ang, float r)
{
    int r1 = r;
    int tempx = x;
    int tempy = y;

        while (r >= 0)
        {
		    x = cos(ang * M_PI/180) * r + tempx;
		    y = sin(ang * M_PI/180) * r + tempy;
		   img_put (img, x, y, 65535);
		    r--;;
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

    x_pos = (int)(x / tile_size);
    y_pos = (int)(y / tile_size);
    return (g_map[y_pos][x_pos]);
}
char wall_inter2(float x, float y, t_cor *mlx)
{
    int x_pos;
    int y_pos;

    if (x == mlx->nextx_ver && mlx->left == 1)
        x--;
    if(y == mlx->nextywall && mlx->up == 1)
        y--;
    x_pos = (int)(x / tile_size);
    y_pos = (int)(y / tile_size);
    return (g_map[y_pos][x_pos]);
}
void nor_angle(t_cor *mlx)
{
    mlx->new_theta = fmod(mlx->theta1, 360);
    while (mlx->new_theta < 0)
       mlx->new_theta += 360;
}
void    hor_inter(t_cor *mlx)
{
    mlx->xwall = 0;
    mlx->ywall = 0;
    mlx->delta_x = 0;
    mlx->delta_y = 0;
    mlx->new_theta = 0;
    mlx->nextxwall = 0;
    mlx->nextywall = 0;
    mlx->hor_dis = 0;
    mlx->ver_hit = 0;
    mlx->up = 0;

   
    nor_angle(mlx);
 mlx->delta_x = (tile_size / tan(mlx->new_theta * M_PI / 180));
    if (mlx->new_theta > 0 && mlx->new_theta < 180)
    {
        mlx->ywall = floor(mlx->y1 / tile_size) * tile_size + tile_size;
        mlx->delta_y = tile_size;
        mlx->up = 0;
    }
    else if (mlx->new_theta <= 360 &&mlx->new_theta >= 180)
       { 
           mlx->ywall = floor(mlx->y1 / tile_size) * tile_size;
           mlx->delta_y = -tile_size;
           mlx->delta_x *= -1;
           mlx->up = 1;
        }
           
        mlx->xwall = mlx->x1 + (mlx->ywall - mlx->y1) / tan(mlx->new_theta * M_PI/180);
       mlx->nextxwall = mlx->xwall;
        mlx->nextywall = mlx->ywall;
    while (mlx->nextywall < (mlx->map_col * tile_size) && mlx->nextxwall < (mlx->map_rows * tile_size) && mlx->nextxwall  >= 0 && mlx->nextywall  >= 0)
    {    
        if(wall_inter2(mlx->nextxwall, mlx->nextywall, mlx) == '1')
        {
            mlx->xwall = mlx->nextxwall;
            mlx->ywall = mlx->nextywall;
            break;
        }
        else
        {
            mlx->nextxwall += mlx->delta_x;
            mlx->nextywall += mlx->delta_y;
        }
    }
            mlx->hor_dis = sqrt(((mlx->x1 - mlx->nextxwall)*(mlx->x1 - mlx->nextxwall)) + ((mlx->y1 - mlx->nextywall) * (mlx->y1 - mlx->nextywall)));
}

void  ver_inter(t_cor *mlx)
{
    mlx->x_ver = 0;
    mlx->y_ver = 0;
    mlx->deltax_ver = 0;
    mlx->deltay_ver = 0;
    mlx->nextx_ver = 0;
    mlx->nexty_ver = 0;
    mlx->nextx_ver = 0;
    mlx->nexty_ver = 0;
    mlx->ver_dis = 0;
    mlx->left = 0;
    mlx->wallx_ver = 0;
    mlx->wally_ver = 0;
    mlx->ver_hit = 0;
    
    nor_angle(mlx);
    mlx->deltay_ver = tile_size * tan(mlx->new_theta * M_PI / 180);
    if (mlx->new_theta >= 270 || mlx->new_theta <= 90)
    { 
        mlx->deltax_ver = tile_size;
        mlx->x_ver = floor(mlx->x1 / tile_size) * tile_size + tile_size;
        mlx->left = 0;
    //    printf("right\n");
    }
    else
    {
        mlx->deltax_ver = -tile_size;
        mlx->x_ver = floor(mlx->x1 / tile_size) * tile_size;
        mlx->deltay_ver *= -1;
        mlx->left = 1;
        // printf("left\n");
    }
    mlx->y_ver = mlx->y1 + (mlx->x_ver - mlx->x1) * tan((mlx->new_theta) * M_PI / 180);
    

    mlx->nextx_ver = mlx->x_ver;
    mlx->nexty_ver = mlx->y_ver;
   
   while(mlx->nexty_ver < (mlx->map_col * tile_size) && mlx->nextx_ver < (mlx->map_rows * tile_size) && mlx->nextx_ver  >= 0 && mlx->nexty_ver >= 0)
   {
       if (wall_inter2(mlx->nextx_ver, mlx->nexty_ver, mlx) == '1')
       {
           mlx->y_ver = mlx->nexty_ver;
           mlx->x_ver = mlx->nextx_ver;
           break;
       }
       else
       {
           mlx->nexty_ver += mlx->deltay_ver;
           mlx->nextx_ver += mlx->deltax_ver;
       }
   }
mlx->ver_dis = sqrt(((mlx->x1 - mlx->nextx_ver)*(mlx->x1 - mlx->nextx_ver)) + ((mlx->y1 - mlx->nexty_ver) * (mlx->y1 - mlx->nexty_ver)));
}

void ver_line(float x, float start_y, float end_y, t_cor *mlx)
{
    int y;
    float y_off;
    float   t;
    mlx->j = 0;
    y = 0;
    t = 0;
    
    while(y < start_y)
    {
        img_put (mlx->img, x, y, 0x1C96FF);
        y++;
    }
    while (start_y < end_y)
    {
        mlx->wall_col = mlx->color[(int)(mlx->offset + (int)(t) * mlx->img_w)];
         img_put (mlx->img, x, start_y,mlx->wall_col);
          t += mlx->factor;
         start_y++;
    }
    y = end_y;
    while (y < g_height)
    {
    img_put (mlx->img, x, y, 0xAFAFAF);
    y++;
    }
}
void draw_wall(t_cor *mlx, float i)
{
    int start;
    int end;
   
    mlx->dis_proj = (g_width / 4) / tan(((float) FOV / 2) * M_PI / 180);
    mlx->wall_height = (tile_size / mlx->dis * cos(((float) FOV / 2) * M_PI / 180)) * mlx->dis_proj;
    mlx->factor = mlx->img_w / mlx->wall_height;
    start = (g_height - mlx->wall_height) / 2;
    end = (g_height + mlx->wall_height) / 2;
    ver_line(i, start, end, mlx);
}



void player_check(int i, char p, t_cor *mlx)
{
    if (i == 0)
        // (void)i;
        img_put (mlx->img, mlx->x1 * 0.25, mlx->y1 * 0.25, 14090240);
            // player(mlx->x1, mlx->y1, mlx->img);
    else 
    {
    perror("Error\n(Player)");
	exit(0); 
    }
    (void)p;
}

void map_render(t_cor *mlx)
{
    int i;
    char p;
    int height = 0;
    int weight = 0;
    
    i = -1;
    mlx->x=0;
    mlx->y=0;
    while(g_map[height][weight])
    {
      if (g_map[height][weight]== '1')
      {
           rect(mlx->x * 0.25, mlx->y * 0.25, mlx->img);
          mlx->x +=tile_size;
          weight++;
      }
      else if (g_map[height][weight] == '0')
      {
          mlx->x +=tile_size;
          weight++;
      }
      else if (g_map[height][weight] == 'N' || g_map[height][weight] == 'S' || g_map[height][weight] == 'W' || g_map[height][weight] == 'E')
      {
        i += 1;
        p = g_map[height][weight];
        mlx->x1 = mlx->x + (tile_size / 2) + mlx->x_step;
        mlx->y1 = mlx->y + (tile_size / 2) + mlx->y_step;
        mlx->x +=tile_size;
        weight++;
      }
     else if (g_map[height][weight] != '\0') 
    {
          perror("Error\n(Player)");
		    exit(0);
    }
        if(g_map[height][weight] == '\0')
      {
          height++;
          weight = 0;
          mlx->y +=tile_size;
          mlx->x = 0;
      }

    }
    if (i >= 0)
      player_check(i, p, mlx);
      else
      {
          perror("Error\n(Player)");
		    exit(0);
    }
}

void cast(t_cor *mlx)
{
    map_render(mlx);
    float save;
    mlx->dis = 0;
    int i = 0;
    mlx->offset = 0;
    int a;
    int x,y,y1,y2,y3;
    double ang_var =  (float) FOV / (float)g_width;
    mlx->theta1 = mlx->theta - FOV / 2;
    save = mlx->theta + FOV / 2;


    mlx->img_tex_n = mlx_xpm_file_to_image(mlx->ptr, "redbrick.xpm", &x, &y1);
    mlx->img_tex_s = mlx_xpm_file_to_image(mlx->ptr, "wall.xpm", &x, &y);
    mlx->img_tex_e = mlx_xpm_file_to_image(mlx->ptr, "greystone.xpm", &x, &y2);
    mlx->img_tex_w = mlx_xpm_file_to_image(mlx->ptr, "bluestone.xpm", &x, &y3);
    
    while (mlx->theta1 <= save)
    {
    ver_inter(mlx);
    hor_inter(mlx);
    if(mlx->ver_dis > mlx->hor_dis)
    {
    mlx->dis = mlx->hor_dis;
    mlx->hor_hit = 1;
    mlx->offset = fmod(mlx->nextxwall , tile_size);
        if (mlx->up == 1)
        {
        mlx->img_add = mlx_get_data_addr(mlx->img_tex_s, &a, &a, &a);
        mlx->img_w = y;
        }
        else
        {
        mlx->img_add = mlx_get_data_addr(mlx->img_tex_e, &a, &a, &a);
        mlx->img_w = y2;
        }
    
    mlx->color = (int *)mlx->img_add;
    }
    else
    {
    mlx->dis  = mlx->ver_dis;
    mlx->ver_hit = 1;
    mlx->offset =  fmod(mlx->nexty_ver , tile_size);
   if (mlx->left == 1)
   {
   mlx->img_add = mlx_get_data_addr(mlx->img_tex_n, &a, &a, &a);
   mlx->img_w = y1;
   }
   else
   {
    mlx->img_add = mlx_get_data_addr(mlx->img_tex_w, &a, &a, &a);
   mlx->img_w = y3;
   }
    mlx->color = (int *)mlx->img_add;
    }
   
    ray(mlx->x1 * 0.25 , mlx->y1 * 0.25 ,mlx->img, mlx->new_theta, mlx->dis  * 0.25);
    mlx->dis *= cos((mlx->theta1 - mlx->theta) * M_PI/180);
    draw_wall(mlx, (float)i);
     mlx->theta1 += ang_var;
    i++;
    }
}

    int ft_check(int key, t_cor *mlx)
{
    if(key == 126 &&  wall_inter(mlx->x1 + 20 * cos((mlx->theta) * (M_PI / 180)),mlx->y1 + 20 * sin((mlx->theta) * (M_PI / 180))) != '1')
    {
     mlx_destroy_image((mlx)->ptr, (mlx)->img);
     mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
     mlx->x_step += cos((mlx->theta ) * (M_PI / 180.0)) * 10;
     mlx->y_step += sin((mlx->theta) * (M_PI / 180.0)) * 10;
     cast(mlx);
     map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 125  &&  wall_inter(mlx->x1 - 20 * cos((mlx->theta) * (M_PI / 180)),mlx->y1 - 20 * sin((mlx->theta) * (M_PI / 180))) != '1')
    {
        mlx_destroy_image((mlx)->ptr, (mlx)->img);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
     mlx->x_step -= cos((mlx->theta) * (M_PI / 180.0)) * 10;
     mlx->y_step -= sin((mlx->theta) * (M_PI / 180.0)) * 10;
     cast(mlx);
     map_render(mlx);
      mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 123)
    {
        mlx->theta -= 10.0;
         mlx_destroy_image((mlx)->ptr, (mlx)->img);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
     cast(mlx);
    map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 124)
    {
        mlx->theta += 10.0;
         mlx_destroy_image((mlx)->ptr, (mlx)->img);
        mlx_clear_window((mlx)->ptr, (mlx)->win);
         mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
         cast(mlx);
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
    t_cor *mlx;
    mlx = malloc(sizeof(t_cor));
    mlx->x=0;
    mlx->y=0;
    mlx->x1=0;
    mlx->y1=0;
    int i = 0;
    mlx->y_step = 0;
    mlx->x_step = 0;
    mlx->theta = 180;
    file_cub(mlx);
    mlx->ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->ptr,  g_width, g_height, "My Game");
    mlx->img = mlx_new_image(mlx->ptr, g_width, g_height);
    map_render(mlx);
    cast(mlx);
    mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
    mlx_loop(mlx->ptr);
    
}