/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:03:08 by mbani             #+#    #+#             */
/*   Updated: 2019/12/02 20:53:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "get_next_line.h"

void rect(int x, int y,void* mlx_ptr, void *mlx_win)
{
    int lenX;
    int lenY;

    lenX = x + 240;
    lenY = y + 120;
    while (y <= lenY)
    {
        while (x < lenX)
        {
            while(y != lenY)
            {
                mlx_pixel_put (mlx_ptr, mlx_win, x, y, 14090240);
                y++;
            }
            y -=120;
            // mlx_pixel_put (mlx_ptr, mlx_win, x, y + 100, 255);
            x++;
        }
        // mlx_pixel_put (mlx_ptr, mlx_win, x - 100 , y, 255);
        // mlx_pixel_put (mlx_ptr, mlx_win, x, y, 255);
        y++;
    }
}
int main()
{
    void *mlx_ptr;
    void *mlx_win;
    int x,y,i,a,b;
    int height = 0;
    int weight = 0;
    int hor_res=1920, ver_res=1080;
    
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
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr,  hor_res, ver_res, "My Game");
        while(map[height][weight])
        {
            if (map[height][weight] == '1')
            {
                a++;
                weight++;
            }
            else
            printf("Error");
        }
    while(map[height][0])
    {
        if(map[height][0]== '1')
        {
            b++;
            height++;
        }
        else
        printf("Error");
    }
    weight = 0;
    height = 0;
        while(map[height][weight])
    {
      if (map[height][weight]== '1')
      {
        //   printf("hello");
          rect(x, y, mlx_ptr, mlx_win);
          x +=a/hor_res;
          weight++;
      }
      else if (map[height][weight] == '0')
      {
          x +=hor_res/a;
          weight++;
      }
      else if (map[height][weight] == '2')
      {
       mlx_string_put (mlx_ptr, mlx_win, x, y, 16711680, "*");
        x +=hor_res/a;
        weight++;
      }
      
      if(map[height][weight] == '\0')
      {
          height++;
          weight = 0;
          y +=ver_res/b;
          x = 0;
      }
      if (map[height] == '\0')
      break;
    }
   







   
     mlx_loop(mlx_ptr);
}

