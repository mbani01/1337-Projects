/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:02:36 by mbani             #+#    #+#             */
/*   Updated: 2019/12/14 11:02:52 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct cor
{
    void *ptr;
    void *win;
    int x;
    int y;
    float x1;
    float y1;
	float theta;
     
}cor;
 
int abs (int n) 
{ 
    return ((n>0) ? n : (n * (-1)));
} 
void line(int x, int x1, int y, int y1, void *mlx_ptr, void *mlx_win)
{
	int dx,dy,steps,i;
	float Xinc,Yinc;
	
	dx = x1-x;
	dy = y1-y;
	
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	Xinc = dx / (float)steps;
	Yinc = dy / (float)steps;
	i = 0;
	while (i <= steps)
	{
		 mlx_pixel_put (mlx_ptr, mlx_win, x, y, 14090240);
		x +=Xinc;
		y +=Yinc;
		i++;
	}
}
void rays(int x, int y,void* mlx_ptr, void *mlx_win, float ang)
{
    int r = 500;
    int tempx = x;
    int tempy = y;
    float save = ang;
// float ang=0.0;
while (r)
{
	while (ang <= save  + 60)
	{
		x = cos(ang * M_PI/180) * r +500;
		y = sin(ang * M_PI/180) * r +500;
		mlx_pixel_put (mlx_ptr, mlx_win, x, y, 14090240);
		ang += 0.05;
	}
	// ang = save;
	r--;
}
}
int ft_check(int key, cor *mlx)
{
	// mlx->theta=240;
	if(key == 123)
    {
		// theta=0;
        
    mlx_clear_window((mlx)->ptr, (mlx)->win);
    mlx->theta -= 10.0;
	rays(mlx->x1, mlx->y1, mlx->ptr, mlx->win, mlx->theta);
	printf("%f\n", mlx->theta);
	}
    else if(key == 124)
    {
		// mlx->theta=0;
        
    mlx_clear_window((mlx)->ptr, (mlx)->win);
	mlx->theta += 10.0;
    rays(mlx->x1, mlx->y1, mlx->ptr, mlx->win, mlx->theta);
	printf("%f\n", mlx->theta);
	}
	return 0;
}
int main()
{
	
	int  x=0 ,y=0,r=500;
	float ang=240.0;
	cor *mlx;
	
	mlx = malloc(sizeof(cor));
	mlx->x=0;
    mlx->y=0;
    mlx->x1=500.0;
    mlx->y1=400.0;
    
	mlx->ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->ptr,  1920, 1080, "My Game");
while (r)
{
	while (ang <= 60)
	{
		x = cos(ang * M_PI/180) * r +500;
		y = sin(ang * M_PI/180) * r +500;
		mlx_pixel_put (mlx->ptr, mlx->win, x, y, 14090240);
		ang += 0.05;
	}
	ang = 0;
	r--;
}
mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
	mlx_loop(mlx->ptr);
}