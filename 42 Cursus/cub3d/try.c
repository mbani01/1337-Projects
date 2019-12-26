/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:45:40 by mbani             #+#    #+#             */
/*   Updated: 2019/12/26 17:02:41 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main()
{
   int x;
   int y;
   
   void *mlx_ptr = mlx_init();
   void *win_ptr = mlx_new_window(mlx_ptr,937,1162,"HElLO it's me MAMOUSSA");
   void *img = mlx_xpm_file_to_image (mlx_ptr, "mamooussa.XPM", &x, &y);
   mlx_put_image_to_window (mlx_ptr, win_ptr, img, 0, 0);

   
   mlx_loop(mlx_ptr);
   return 0;
}