/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3rd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:02:36 by mbani             #+#    #+#             */
/*   Updated: 2019/12/27 18:47:57 by mbani            ###   ########.fr       */
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
    float theta1;
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
    int   rays_dis[1921];
    int up;
    int left;
    float dis_proj;
    float wall_height;
    float wallx_hor;
    float wally_hor;
    float wallx_ver;
    float wally_ver;
    int ver_hit;
    int hor_hit;
    void *img_tex;
    void *img_add;
    int wall_col;
    float offset;
    float j;
    float factor;
    int *color;
    float img_w;
    int sizeline;

}cor;
 
     char map[15][30]= 
    {
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','1','1','0','2','0','0','0','0','1','1','1','0','0','0','0','0','0','1','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','1','1','0','0','0','0','0','1','1','1','0','0','0','1','0','0','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','1','1','1','0','1','1','1','1','0','0','0','1'},
    {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','0','1','0','0','1','0','0','0','1'},
    {'1','1','0','0','0','0','0','0','1','1','0','1','0','1','0','1','1','1','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','1','1','0','0','0','0','0','0','1','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','0','1','0','1','0','0','1','0','0','0','1'},
    {'1','1','0','0','0','0','0','0','1','1','0','1','0','1','0','1','1','1','1','1','0','1','1','1','1','0','1','0','1'},
    {'1','1','1','1','0','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','1','1','1','0','0','0','1'},
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
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

    lenX = x + (100 * 0.2);
    lenY = y + (100 * 0.2);
    while (y <= lenY)
    {
        while (x < lenX)
        {
            while(y != lenY)
            {
                img_put (img, x, y, 199423);
                y++;
            }
            y -=(100 * 0.2);
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
char wall_inter2(float x, float y, cor *mlx)
{
    int x_pos;
    int y_pos;

    if (x == mlx->nextx_ver && mlx->left == 1)
        x--;
    if(y == mlx->nextywall && mlx->up == 1)
        y--;
    x_pos = (int)(x / 100);
    y_pos = (int)(y / 100);
    return (map[y_pos][x_pos]);
}
void nor_angle(cor *mlx)
{
    mlx->new_theta = fmod(mlx->theta1, 360);
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
    mlx->ver_hit = 0;
    mlx->up = 0;

   
    nor_angle(mlx);
 mlx->delta_x = (100 / tan(mlx->new_theta * M_PI / 180));
    if (mlx->new_theta > 0 && mlx->new_theta < 180)
    {
        mlx->ywall = floor(mlx->y1 / 100) * 100 + 100;
        mlx->delta_y = 100;
    }
    else if (mlx->new_theta <= 360 &&mlx->new_theta >= 180)
       { 
           mlx->ywall = floor(mlx->y1 / 100) * 100;
           mlx->delta_y = -100;
           mlx->delta_x *= -1;
           mlx->up = 1;
        }
           
        mlx->xwall = mlx->x1 + (mlx->ywall - mlx->y1) / tan(mlx->new_theta * M_PI/180);
       mlx->nextxwall = mlx->xwall;
        mlx->nextywall = mlx->ywall;
    while (mlx->nextywall < 1500 && mlx->nextxwall < 3000 && mlx->nextxwall  >= 0 && mlx->nextywall  >= 0)
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
    mlx->left = 0;
    mlx->wallx_ver = 0;
    mlx->wally_ver = 0;
    mlx->ver_hit = 0;
    
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
        mlx->x_ver = floor(mlx->x1 / 100) * 100;
        mlx->deltay_ver *= -1;
        mlx->left = 1;
        // printf("left\n");
    }
    mlx->y_ver = mlx->y1 + (mlx->x_ver - mlx->x1) * tan((mlx->new_theta) * M_PI / 180);
    

    mlx->nextx_ver = mlx->x_ver;
    mlx->nexty_ver = mlx->y_ver;
   
   while(mlx->nexty_ver < 1500 && mlx->nextx_ver < 3000 && mlx->nextx_ver  >= 0 && mlx->nexty_ver >= 0)
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
void ver_line(float x, float start_y, float end_y, cor *mlx)
{
    float save_y = end_y;
    int i;
    float y;
float y_off;
float   t;
    mlx->j = 0;
    y = 0;
    i = 0;
    t = 0;
    while(y < start_y)
    {
        img_put (mlx->img, x, y, 0x0FF0F0);
        y++;
        // printf("hello");
    }
    while (start_y <= end_y)
    {
        //  mlx->factor;
            //y_off = mlx->j;
            // printf("%f \n", y_off);
            // printf("%.2f | %.2f\n", mlx->offset, mlx->factor);
        mlx->wall_col = mlx->color[(int)(mlx->offset + (int)(t) * mlx->img_w)];
         img_put (mlx->img, x, start_y, mlx->wall_col);
         t += mlx->factor;
         start_y++;
         //i++;
    }
}
void draw_wall(cor *mlx, float i)
{
    float start;
    float end;
    int *color;
    int x,y;
    int sizeline;
    int a;
    // float factor;
    // float y_off;
    float q;

    printf("%f\n", mlx->offset);
    mlx->img_tex = mlx_xpm_file_to_image(mlx->ptr, "bluestone.xpm", &x, &y);
    mlx->img_w = y;
    mlx->img_add = mlx_get_data_addr(mlx->img_tex, &a, &a, &a);
    mlx->color = (int *)mlx->img_add;
    mlx->dis_proj = (1920 / 4) / tan(30 * M_PI / 180);
    mlx->wall_height = (100 / mlx->dis * cos(30 * M_PI / 180)) * mlx->dis_proj;
    mlx->factor = y / mlx->wall_height;
    mlx->sizeline = sizeline;
    start = (1080 - mlx->wall_height) / 2;
    end = (1080 + mlx->wall_height) / 2;
    ver_line(i, start, end, mlx);
}
void cast(cor *mlx)
{
    float save;
    mlx->dis = 0;
    int i = 0;
    mlx->offset = 0;

    double ang_var =  60.0 / 1920.0;
    mlx->theta1 = mlx->theta - 30;
    save = mlx->theta + 30;


    while (mlx->theta1 <= save)
    {
    ver_inter(mlx);
    hor_inter(mlx);
    if(mlx->ver_dis > mlx->hor_dis)
    {
    mlx->dis = mlx->hor_dis;
    mlx->hor_hit = 1;
    mlx->offset = fmod(mlx->nextxwall , 100);
    }
    else
    {
    mlx->dis  = mlx->ver_dis;
   mlx->ver_hit = 1;
   mlx->offset =  fmod(mlx->nexty_ver , 100);
    }
   
    // ray(mlx->x1  * 0.2, mlx->y1  * 0.2,mlx->img, mlx->new_theta, mlx->dis  * 0.2);
    mlx->dis *= cos((mlx->theta1 - mlx->theta) * M_PI/180);
    draw_wall(mlx, (float)i);
     mlx->theta1 += ang_var;
    i++;
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
        //   rect(mlx->x * 0.2, mlx->y * 0.2, mlx->img);
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
    // player(mlx->x1 * 0.2, mlx->y1 * 0.2, mlx->img);
    // rays(mlx->x1 * 0.2, mlx->y1 * 0.2, mlx->img, mlx->theta);
    // ver_inter(mlx);
// hor_inter(mlx);
    }
    
}



int ft_check(int key, cor *mlx)
{
    if(key == 126 &&  wall_inter(mlx->x1 + 20 * cos((mlx->theta) * (M_PI / 180)),mlx->y1 + 20 * sin((mlx->theta) * (M_PI / 180))) != '1')
    {
     mlx_destroy_image((mlx)->ptr, (mlx)->img);
     mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
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
     mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
     mlx->x_step -= cos((mlx->theta) * (M_PI / 180.0)) * 10;
     mlx->y_step -= sin((mlx->theta) * (M_PI / 180.0)) * 10;
     cast(mlx);
     map_render(mlx);
    mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 123)
    {
        mlx->theta -= 5.0;
    mlx_destroy_image((mlx)->ptr, (mlx)->img);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
    mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
    cast(mlx);
    map_render(mlx);
     mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
    }
    else if(key == 124)
    {
        mlx->theta += 5.0;
         mlx_destroy_image((mlx)->ptr, (mlx)->img);
        mlx_clear_window((mlx)->ptr, (mlx)->win);
         mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
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
	
	// int  x=600 ,y=500,r=500;

    /*
    void *img = mlx_xpm_file_to_image(mlx_ptr, "bluestone.xpm", &x, &y);
    char *raw = mlx_get_data_addr(img, &bpp, &sl, &end);
    int  *cast = (int*)raw;
    int    **tab;
    tab = malloc(y * sizeof(int*));
    int i, j;
    i = -1;
    while (++i < y)
        tab[i] = malloc(x * sizeof(int));
    i = -1;
    while (++i < y)
    {
        j = -1;
        while (++j < x)
            tab[i][j] = *(cast++);
    }
    */
	float ang=240.0;
	cor *mlx;
	
	mlx = malloc(sizeof(cor));
    mlx->x=0;
    mlx->y=0;
   mlx->theta = 180;
    mlx->x1=0;
    mlx->y1=0;
    mlx->y_step = 0;
    mlx->x_step = 0;
    
	mlx->ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->ptr,  1920, 1080, "My Game");
    mlx->img = mlx_new_image(mlx->ptr, 1920, 1080);
    map_render(mlx);
    cast(mlx);
	// img_put( mlx->img, x, y, 65535);
	
	mlx_put_image_to_window (mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
	mlx_loop(mlx->ptr);
}