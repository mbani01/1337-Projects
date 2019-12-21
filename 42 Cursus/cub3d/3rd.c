/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3rd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:02:36 by mbani             #+#    #+#             */
/*   Updated: 2019/12/21 15:14:04 by mbani            ###   ########.fr       */
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
    float xwall;
    float ywall;
    float delta_x;
    float delta_y;
    float nextxwall;
    float nextywall;


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

    x_pos = (int)(x / 100);
    y_pos = (int)(y / 100);
    return (map[y_pos][x_pos]);
}
void    ft_ang_direc(cor *mlx)
{
    float wallx = 0;
    float wally = 0;
    mlx->xwall = 0;
    mlx->ywall = 0;
    mlx->delta_x = 0;
    mlx->delta_y = 0;
    mlx->new_theta = 0;
    mlx->nextxwall = 0;
    mlx->nextywall = 0;

    float theta;

    theta = fmod(mlx->theta, 360);
    while (theta < 0)
        theta += 360;
mlx->new_theta = theta;

 mlx->delta_x = (100 / tan(theta * M_PI / 180));
    if (theta > 0 && theta < 180)
    {
        mlx->ywall = floor(mlx->y1 / 100) * 100 + 100;
        mlx->delta_y = 100;
    }
    else if (theta <= 360 && theta >= 180)
       { 
           mlx->ywall = floor(mlx->y1 / 100) * 100 -1;
           mlx->delta_y = -100;
           mlx->delta_x *= -1;
        }
           
        mlx->xwall = mlx->x1 + (mlx->ywall - mlx->y1) / tan(theta * M_PI/180);
       mlx->nextxwall = mlx->xwall;
        mlx->nextywall = mlx->ywall; 

    // if (theta > 270 || theta < 90)
    //    { 
    //         mlx->nextxwall = mlx->xwall + mlx->delta_x;
    //    printf("right\n");
    //    }
    // else
    //     { mlx->nextxwall = mlx->xwall - mlx->delta_x;
    //     printf("left\n");
    //     }
    while (mlx->nextywall < 1080 && mlx->nextxwall < 1920 && mlx->nextxwall  >= 0 && mlx->nextywall  >= 0)
    {
        
        if(mlx->nextywall < 1080 && mlx->nextxwall < 1920 && mlx->nextxwall  >= 0 && mlx->nextywall  >= 0 && wall_inter(mlx->nextxwall, mlx->nextywall) == '1')
        {
            wallx = mlx->nextxwall;
            wally = mlx->nextywall;
            break;
        }
        else
        {
            img_put(mlx->img, mlx->nextxwall, mlx->nextywall, 16776960);
            mlx->nextxwall += mlx->delta_x;
            mlx->nextywall += mlx->delta_y; 
            printf("%.2f | %.2f\n", mlx->nextywall, mlx->nextxwall);
        }
    }
    // img_put(mlx->img, mlx->nextxwall, mlx->nextywall, 16776960);
    if (mlx->nextywall < 1080 && mlx->nextxwall < 1920 && mlx->nextxwall  >= 0 && mlx->nextywall  >= 0)
        ray(mlx->x1, mlx->y1,mlx->img, theta, sqrt(((mlx->x1 - mlx->nextxwall)*(mlx->x1 - mlx->nextxwall)) + ((mlx->y1 - mlx->nextywall) * (mlx->y1 - mlx->nextywall))));
}
void  hor_inter(cor *mlx)
{
    ft_ang_direc(mlx);

    // while (mlx->ywall <= 1080 && mlx->xwall <= 1920 && mlx->xwall  >= 0 && mlx->ywall  >= 0)
    // {
    //     printf("x: [%.2f], y: [%.2f]\n", mlx-> , mlx-> );
    //     if (wall_inter(mlx->xwall, mlx->ywall) == '1')
    //     {

    //     }
    // }
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
    // rays(mlx->x1, mlx->y1, mlx->img, mlx->theta);
    // hor_inter(mlx);
ft_ang_direc(mlx);
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
        mlx->theta -= 5.0;
         mlx_destroy_image((mlx)->ptr, (mlx)->img);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
    map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 124)
    {
        mlx->theta += 5.0;
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