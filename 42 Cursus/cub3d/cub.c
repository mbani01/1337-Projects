/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:02:36 by mbani             #+#    #+#             */
/*   Updated: 2019/12/19 18:07:48 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define DEG(x) x * M_PI / 180

typedef struct cor
{
    void *ptr;
    void *win;
    float x;
    float x_step;
    float y_step;
    float y;
    float x1;
    float y1;
    float theta;
    float new_theta;
	void *img;
    int ang_up;
    int ang_down;
    int ang_right;
    int ang_left;
    float yinter;
    float xinter;
    float delta_x;
    float delta_y;
    float new_xinter;
    float new_yinter;
    float next_xinter;
    float next_yinter;
    float wall_xinter;
    float wall_yinter;
    int hor_wall;

}cor;
 
     char map[15][15]= 
    {
        {'1','1','1','1','1','1','1','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','1','1','0','0','1'},
        {'1','0','0','0','2','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','0','0','1','0','1'},
        {'1','0','1','0','0','1','0','1'},
        {'1','0','1','0','0','1','0','1'},
        {'1','1','1','1','1','1','1','1'}
    };
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
void rect(int x, int y,void *img)
{
    int lenX;
    int lenY;

    lenX = x + 100;
    lenY = y + 100;
    while (y <= lenY)
    {
        while (x < lenX)
        {
            while(y != lenY)
            {
                img_put (img, x, y, 199423);
                y++;
            }
            y -=100;
            x++;
        }
        y++;
	}
}
void player(int x, int y,void *img)
{
    int r = 5;
    int tempx = x;
    int tempy = y;
    float ang=0.0;
    while (r)
    {
        while (ang <= 360)
        {
            x = cos(ang * M_PI/180) * r + tempx;
            y = sin(ang * M_PI/180) * r + tempy;
            img_put (img, x, y, 14090240);
            ang += 0.1;
        }
        ang = 0;
        r--;
    }
}
void rays(int x, int y,void* img, float ang)
{
    int r = 50;
    int tempx = x;
    int tempy = y;
    float save = ang - 30;

	while (ang <=  save + 30)
    {
        while (r)
        {
		    x = cos(ang * M_PI/180) * r + tempx;
		    y = sin(ang * M_PI/180) * r + tempy;
		   img_put (img, x, y, 65535);
		    r--;;
	    }
    r = 50;
    ang += 5;
	r--;
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
            // printf("%.2f\n", r);
		    r--;;
	    }

}


char wall_inter(float x, float y)
{
    int x_pos;
    int y_pos;

    x_pos = (int)x / 100;
    y_pos = (int)y / 100;
    return (map[y_pos][x_pos]);
}
void    ft_ang_direc(cor *mlx)
{
    mlx->ang_down = 0;
    mlx->ang_up = 0;
    mlx->ang_right = 0;
    mlx->ang_left = 0;
    mlx->delta_x = 0;
    mlx->delta_y = 0;
    mlx->new_theta = 0;
//  printf("theta [%f] newtheta [%f]\n", mlx->theta , mlx->new_theta);
    float theta;

    theta = fmod(mlx->theta, 360);
    while (theta < 0)
        theta += 360;

    if (theta > 0 && theta < 180)
    {
        mlx->ang_down = 1;
        printf("down\n");
    }
    else if (theta <= 360 && theta >= 180)
       { 
           mlx->ang_up = 1;
           printf("up\n");
           }
    if (theta > 270 || theta < 90)
       { mlx->ang_right = 1;
       printf("right\n");
       }
    else if (theta <= 270 || theta >= 90)
        {mlx->ang_left = 1;
        printf("left\n");
        }
 
        mlx->new_theta = theta;
        // printf("theta [%f] newtheta [%f]\n", mlx->theta , mlx->new_theta);
}
void  hor_inter(cor *mlx)
{
    mlx->yinter = 0;
    mlx->hor_wall = 0;

    ft_ang_direc(mlx);
    mlx->yinter = floor(mlx->y1/100) * 100;
    mlx->yinter += mlx->ang_down == 1 ? 100 : 0 ;
    mlx->xinter = mlx->x1 + (mlx->y1 - mlx->yinter)/tan(mlx->new_theta * M_PI / 180);
    mlx->delta_y = mlx->ang_up == 1 ? -100 : 100;
    mlx->delta_x = 100 / tan(mlx->new_theta * M_PI / 180);
    mlx->delta_x *= (mlx->ang_left == 1  && mlx->delta_x > 0) ? -1 : 1;
    mlx->delta_x *= (mlx->ang_right == 1 && mlx->delta_x < 0) ? -1 : 1;

    mlx->new_xinter = mlx->xinter;
    mlx->new_yinter = mlx->yinter;

    if (mlx->ang_up == 1)
        mlx->new_yinter--;
    while (mlx->next_yinter < 1080 && mlx->next_xinter < 1920 && mlx->next_yinter >= 0 && mlx->next_xinter >= 0)
    {
        printf("x: [%.2f], y: [%.2f]\n", mlx->new_xinter, mlx->new_yinter);
        if (wall_inter(mlx->new_xinter, mlx->new_yinter) == '1')
        {
             mlx->hor_wall = 1;
             mlx->next_xinter = mlx->new_xinter;
             mlx->next_yinter = mlx->new_yinter;
            printf("next_xinter [%f] next_yinter [%f]", mlx->next_xinter , mlx->next_yinter);
             ray(mlx->x1, mlx->y1,mlx->img, mlx->new_theta, sqrt(((mlx->x1 - mlx->new_xinter)*(mlx->x1 - mlx->new_xinter)) + ((mlx->y1 - mlx->new_yinter) * (mlx->y1 - mlx->new_yinter))));
             break;

            mlx->new_xinter += mlx->delta_x;
            mlx->new_yinter += mlx->delta_y;
        }
    }
}
void map_render(cor *mlx)
{
    int i;
    i = 0;

    int height = 0;
    int weight = 0;
    
    mlx->x=0;
    mlx->y=0;
    while(map[height][weight])
    {
      if (map[height][weight]== '1')
      {
          rect(mlx->x, mlx->y, mlx->img);
          mlx->x +=100;
          weight++;
      }
      else if (map[height][weight] == '0')
      {
          mlx->x +=100;
          weight++;
      }
      else if (map[height][weight] == '2')
      {
        i = 1;
        
        mlx->x1 = mlx->x + 50 + mlx->x_step;
        mlx->y1 = mlx->y + 50 + mlx->y_step;
        mlx->x +=100;
        weight++;
      }
      
      if(map[height][weight] == '\0')
      {
          height++;
          weight = 0;
          mlx->y +=100;
          mlx->x = 0;
      }
      if (map[height] == '\0')
      break;
    }
    if (i == 1)
    {
    player(mlx->x1, mlx->y1, mlx->img);
    rays(mlx->x1, mlx->y1, mlx->img, mlx->theta);
    // hor_inter(mlx);
// ft_ang_direc(mlx);
    }
    
}



int ft_check(int key, cor *mlx)
{
    if(key == 126 &&  wall_inter(mlx->x1 + 15 * cos((mlx->theta) * (M_PI / 180)),mlx->y1 + 15 * sin((mlx->theta) * (M_PI / 180))) != '1')
    {
     mlx_destroy_image((mlx)->ptr, (mlx)->img);
     mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
     mlx->x_step += cos((mlx->theta ) * (M_PI / 180.0)) * 10;
     mlx->y_step += sin((mlx->theta) * (M_PI / 180.0)) * 10;
     map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 125  &&  wall_inter(mlx->x1 - 15 * cos((mlx->theta) * (M_PI / 180)),mlx->y1 - 15 * sin((mlx->theta) * (M_PI / 180))) != '1')
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
	
	int  x=600 ,y=500,r=500;
	float ang=240.0;
	cor *mlx;
	
	mlx = malloc(sizeof(cor));
    mlx->x=0;
    mlx->y=0;
   mlx->theta = -90;
    mlx->x1=0;
    mlx->y1=0;
    mlx->y_step = 0;
    mlx->x_step = 0;
    
	mlx->ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->ptr,  1920, 1080, "My Game");
    mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
	// img_put( mlx->img, x, y, 65535);
	map_render(mlx);
	mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
	mlx_loop(mlx->ptr);
}