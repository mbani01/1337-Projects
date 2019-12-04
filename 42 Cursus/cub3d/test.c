/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:27:56 by mbani             #+#    #+#             */
/*   Updated: 2019/12/04 10:40:51 by mbani            ###   ########.fr       */
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
    int y;
    int x1;
    int y1;
    
}cor;

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
    int lenX;
    int lenY;

    lenX = x + 10;
    lenY = y + 10;
    while (y <= lenY)
    {
        while (x < lenX)
        {
            while(y != lenY)
            {
                mlx_pixel_put (mlx_ptr, mlx_win, x, y, 14090240);
                y++;
            }
            y -=10;
            // mlx_pixel_put (mlx_ptr, mlx_win, x, y + 100, 255);
            x++;
        }
        // mlx_pixel_put (mlx_ptr, mlx_win, x - 100 , y, 255);
        // mlx_pixel_put (mlx_ptr, mlx_win, x, y, 255);
        y++;
    }
}
int ft_check(int key, cor *mlx)
{
    if(key == 126)
    {
     write(1, "Yeah", 4);
     mlx_pixel_put ((mlx)->ptr, (mlx)->win, (mlx)->x1, (mlx)->y1, 000000);
     mlx->y1 -= 1;
     mlx_pixel_put ((mlx)->ptr, (mlx)->win, (mlx)->x1, (mlx)->y1, 14090240);
    //  mlx->x1 += 10;
    //  mlx->y1 += 10;
    // mlx_pixel_put ((mlx)->ptr, (mlx)->win, (mlx)->x1, (mlx)->y1, 14090240);
    //  *p +=100;
    //  ft_putnbr(*p, 1);
    }
    else
    write(1, "No", 2);
    return 0;
} 
int main()
{
    cor *mlx;
    mlx = malloc(sizeof(cor));
    // void *mlx_ptr;
    // void *mlx_win;
    int height = 0;
    int weight = 0;
    mlx->x=0;
    mlx->y=0;
     mlx->x1=500;
     mlx->y1=400;
    // char map[height][weight];

   char map[15][15]= 
    {
        {'1','1','1','1','1','1','1','1'},
        {'1','1','0','0','0','1','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','0','0','2','0','1','1'},
        {'1','1','1','0','0','0','0','1'},
        {'1','0','1','1','0','1','0','1'},
        {'1','0','0','0','0','0','1','1'},
        {'1','0','1','0','1','0','0','1'},
        {'1','1','1','1','1','1','1','1'}
    };

//     printf("[%d] \n {%d}", a, b);
    // i = 14;
    printf("[%c]", map[height][weight]);
    (*mlx).ptr = mlx_init();
    (*mlx).win = mlx_new_window((mlx)->ptr,  1920, 1080, "My Game");
    while(map[height][weight])
    {
      if (map[height][weight]== '1')
      {
        //   printf("hello");
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
       mlx_pixel_put ((mlx)->ptr, (mlx)->win, mlx->x1, mlx->y1, 14090240);
    //    line(mlx->x1 , mlx->y1, mlx->ptr, mlx->win);
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
    mlx_hook ((mlx)->win, 2, 0, ft_check, mlx);
    mlx_loop((mlx)->ptr);
}