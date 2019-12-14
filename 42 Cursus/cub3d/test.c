/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:27:56 by mbani             #+#    #+#             */
/*   Updated: 2019/12/13 21:47:29 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include  <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct cor
{
    void *ptr;
    void *win;
    int x;
    int x_step;
    int y_step;
    int y;
    float x1;
    float y1;
    float theta;
     
}cor;
    char map[15][15]= 
    {
        {'1','1','1','1','1','1','1','1'},
        {'1','0','1','0','0','1','0','1'},
        {'1','0','1','1','0','0','0','1'},
        {'1','0','0','0','2','0','1','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','1','0','1','0','1'},
        {'1','0','0','0','0','1','0','1'},
        {'1','0','1','0','0','1','0','1'},
        {'1','1','1','1','1','1','1','1'}
    };

// float theta  = 300 ;
static	void	ft_print(char c, int fd)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n, int fd)
{
	unsigned int new_nb;

	new_nb = n;
	if (n < 0)
	{
		ft_print('-', fd);
		new_nb = n * -1;
	}
	if (new_nb > 9)
	{
		ft_putnbr(new_nb / 10, fd);
		ft_print((new_nb % 10) + '0', fd);
	}
	if (new_nb <= 9)
	{
		ft_print((new_nb) + '0', fd);
	}
}

void line(int x, int y, void *mlx_ptr, void * mlx_win)
{
    int lenX;
    int lenY;

    // lenY = y + sin(M_PI/2) * 5;
    lenX = x + sin(M_PI/2) * 55;
    // while(y <= lenY)
    // {
        while(x <= lenX)
        {
            mlx_pixel_put (mlx_ptr, mlx_win, x, y, 14090240);
            x++;
            y++;
         }
        //  x = 0;
    //      y++;
    // }
}
void rect(int x, int y,void* mlx_ptr, void *mlx_win)
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
                mlx_pixel_put (mlx_ptr, mlx_win, x, y, 199423);
                y++;
            }
            y -=100;
            // mlx_pixel_put (mlx_ptr, mlx_win, x, y + 100, 255);
            x++;
        }
        // mlx_pixel_put (mlx_ptr, mlx_win, x - 100 , y, 255);
        // mlx_pixel_put (mlx_ptr, mlx_win, x, y, 255);
        y++;
    }
}
void player(int x, int y,void* mlx_ptr, void *mlx_win)
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
		mlx_pixel_put (mlx_ptr, mlx_win, x, y, 14090240);
		ang += 0.1;
	}
	ang = 0;
	r--;
}
}
void rays(int x, int y,void* mlx_ptr, void *mlx_win, float ang)
{
    int r = 200;
    int tempx = x;
    int tempy = y;
    float save = ang;
// float ang=0.0;
while (r)
{
	while (ang <= save  + 60)
	{
		x = cos(ang * M_PI/180) * r + tempx;
		y = sin(ang * M_PI/180) * r + tempy;
		mlx_pixel_put (mlx_ptr, mlx_win, x, y, 65535);
		ang += 0.1;
	}
	ang = save;
	r--;
}
}
int wall_inter(float x, float y)
{
    int x_pos;
    int y_pos;

    x_pos = (int)x / 100;
    y_pos = (int)y / 100;
    printf("x [%d]\n", x_pos);
    printf("y [%d]\n", y_pos);
    printf("maap [%c]\n", map[y_pos][x_pos]);
    return map[y_pos][x_pos];
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
          rect(mlx->x, mlx->y, (mlx)->ptr, (mlx)->win);
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
    player(mlx->x1, mlx->y1, mlx->ptr, mlx->win);
    rays(mlx->x1, mlx->y1, mlx->ptr, mlx->win, mlx->theta);
    }
}
 
int ft_check(int key, cor *mlx)
{
    if(key == 126 &&  wall_inter(mlx->x1 + 5 * cos((mlx->theta + 30) * (M_PI / 180)),mlx->y1 + 5 * sin((mlx->theta + 30) * (M_PI / 180))) != '1')
    {
                // printf("%d\n", mlx->x_step);
        // printf("%f\n", mlx->y1);
        // printf("%d\n", mlx->y_step);
       
     mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->x_step += cos((mlx->theta + 30) * (M_PI / 180)) * 4;
     mlx->y_step += sin((mlx->theta + 30) * (M_PI / 180)) * 4;
     map_render(mlx);
    }
    else if(key == 125  &&  wall_inter(mlx->x1 - 5 * cos((mlx->theta + 30) * (M_PI / 180)),mlx->y1 - 5 * sin((mlx->theta + 30) * (M_PI / 180))) != '1')
    {
        // wall_inter(mlx->x1, mlx->y1);
        //  printf("%f\n", mlx->x1 + cos((mlx->theta + 30) * (M_PI / 180)));
        // printf("%f\n", mlx->y1);
        // printf("%d\n", mlx->y_step);
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     mlx->x_step -= cos((mlx->theta + 30) * (M_PI / 180)) * 4;
     mlx->y_step -= sin((mlx->theta + 30) * (M_PI / 180)) * 4;
     map_render(mlx);

    }
    else if(key == 123)
    {
        mlx->theta -= 10.0;
    mlx_clear_window((mlx)->ptr, (mlx)->win);
    map_render(mlx);
   
    }
    else if(key == 124)
    {
        mlx->theta += 10.0;
    mlx_clear_window((mlx)->ptr, (mlx)->win);
     map_render(mlx);
    
    }
     printf("cos %f\n",mlx->x1 + cos((mlx->theta + 30) * (M_PI / 180)));
      printf("ssin %f\n",mlx->y1 + sin((mlx->theta + 30) * (M_PI / 180)));
    return 0;
} 

int main()
{
    cor *mlx;
    mlx = malloc(sizeof(cor));

    mlx->x=0;
    mlx->y=0;
   

    (*mlx).ptr = mlx_init();
    (*mlx).win = mlx_new_window((mlx)->ptr,  1920, 1080, "My Game");
    map_render(mlx);
    mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
    
    mlx_loop((mlx)->ptr);
}