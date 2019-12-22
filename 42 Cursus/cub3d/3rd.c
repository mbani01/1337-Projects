/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3rd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:02:36 by mbani             #+#    #+#             */
/*   Updated: 2019/12/22 11:54:39 by mbani            ###   ########.fr       */
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
    void *img;
    float x;
    float x_step;
    float y_step;
    float y;
    float x1;
    float y1;
    float theta;
    float new_theta;
    float xwall;
    float ywall;
    float delta_x;
    float delta_y;
    float nextxwall;
    float nextywall;
    float x_ver;
    float y_ver;
    float deltax_ver;
    float deltay_ver;
    float nextx_ver;
    float nexty_ver;
    float hor_dis;
    float ver_dis;
    float dis;
    float ver_inter;
    float hor_inter;


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
void nor_angle(cor *mlx)
{
    mlx->new_theta = fmod(mlx->theta, 360);
    while (mlx->new_theta < 0)
       mlx->new_theta += 360;

}


void    hor_inter(cor *mlx)
{
    mlx->xwall = 0;
    mlx->ywall = 0;
    mlx->delta_x = 0;
    mlx->delta_y = 0;
    mlx->new_theta = 0;
    mlx->nextxwall = 0;
    mlx->nextywall = 0;
    mlx->hor_dis = 0;

   
    nor_angle(mlx);
 mlx->delta_x = (100 / tan(mlx->new_theta * M_PI / 180));
    if (mlx->new_theta > 0 && mlx->new_theta < 180)
    {
        mlx->ywall = floor(mlx->y1 / 100) * 100 + 100;
        mlx->delta_y = 100;
    }
    else if (mlx->new_theta <= 360 &&mlx->new_theta >= 180)
       { 
           mlx->ywall = floor(mlx->y1 / 100) * 100 -1;
           mlx->delta_y = -100;
           mlx->delta_x *= -1;
        }
           
        mlx->xwall = mlx->x1 + (mlx->ywall - mlx->y1) / tan(mlx->new_theta * M_PI/180);
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
    // if (mlx->nextywall < 1080 && mlx->nextxwall < 1920 && mlx->nextxwall  >= 0 && mlx->nextywall  >= 0)
    //     ray(mlx->x1, mlx->y1,mlx->img, mlx->new_theta, sqrt(((mlx->x1 - mlx->nextxwall)*(mlx->x1 - mlx->nextxwall)) + ((mlx->y1 - mlx->nextywall) * (mlx->y1 - mlx->nextywall))));
            mlx->hor_dis = sqrt(((mlx->x1 - mlx->nextxwall)*(mlx->x1 - mlx->nextxwall)) + ((mlx->y1 - mlx->nextywall) * (mlx->y1 - mlx->nextywall)));
}
void  ver_inter(cor *mlx)
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
    
    nor_angle(mlx);
    mlx->deltay_ver = 100 * tan(mlx->new_theta * M_PI / 180);
    if (mlx->new_theta >= 270 || mlx->new_theta <= 90)
    { 
        mlx->deltax_ver = 100;
        mlx->x_ver = floor(mlx->x1 / 100) * 100 + 100;
    //    printf("right\n");
    }
    else
    {
        mlx->deltax_ver = -100;
        mlx->x_ver = floor(mlx->x1 / 100) * 100 - 1;
        mlx->deltay_ver *= -1;
        // printf("left\n");
    }
    mlx->y_ver = mlx->y1 + (mlx->x_ver - mlx->x1) * tan((mlx->new_theta) * M_PI / 180);
    

    mlx->nextx_ver = mlx->x_ver;
    mlx->nexty_ver = mlx->y_ver;
   
   while(mlx->nexty_ver < 1080 && mlx->nextx_ver < 1920 && mlx->nextx_ver  >= 0 && mlx->nexty_ver >= 0)
   {
       if (wall_inter(mlx->nextx_ver, mlx->nexty_ver) == '1')
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
// img_put(mlx->img, mlx->nextx_ver, mlx->nexty_ver, 16776960);
// ray(mlx->x1, mlx->y1,mlx->img, mlx->new_theta, sqrt(((mlx->x1 - mlx->nextx_ver)*(mlx->x1 - mlx->nextx_ver)) + ((mlx->y1 - mlx->nexty_ver) * (mlx->y1 - mlx->nexty_ver))));
mlx->ver_dis = sqrt(((mlx->x1 - mlx->nextx_ver)*(mlx->x1 - mlx->nextx_ver)) + ((mlx->y1 - mlx->nexty_ver) * (mlx->y1 - mlx->nexty_ver)));
printf("in fct %f\n", mlx->ver_dis);
}
void cast(cor *mlx)
{
    mlx->dis = 0; 
    ver_inter(mlx);
    hor_inter(mlx);
    

    if(mlx->ver_dis > mlx->hor_dis)
    {mlx->dis = mlx->hor_dis;
    printf("hello");}
    else
    {mlx->dis  = mlx->ver_dis;
    printf("else");
    }
    // printf("%f", mlx->hor_inter);
    ray(mlx->x1, mlx->y1,mlx->img, mlx->new_theta, mlx->dis);



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
    cast(mlx);
    // rays(mlx->x1, mlx->y1, mlx->img, mlx->theta);
    // ver_inter(mlx);
// hor_inter(mlx);
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
   mlx->theta = 270;
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