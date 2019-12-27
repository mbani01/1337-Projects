/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:45:40 by mbani             #+#    #+#             */
/*   Updated: 2019/12/26 18:07:17 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int main()
{
   int x;
   int y;
   
   void *mlx_ptr = mlx_init();
   
   void *img = mlx_xpm_file_to_image (mlx_ptr, "bluestone.XPM", &x, &y);
   void *win_ptr = mlx_new_window(mlx_ptr,x,y,"HElLO it's me MAMOUSSA");
   mlx_put_image_to_window (mlx_ptr, win_ptr, img, 0, 0);
   printf("x [%d] y[%d]\n", x,y);
   
   mlx_loop(mlx_ptr);
   return 0;
}