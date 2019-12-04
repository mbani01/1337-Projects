/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:45:40 by mbani             #+#    #+#             */
/*   Updated: 2019/11/27 21:35:23 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main()
{
   void *mlx_ptr = mlx_init();
   void *win_ptr = mlx_new_window(mlx_ptr,500,500,"learn");
   mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF,
		       "char *string");
   mlx_loop(mlx_ptr);
   return 0;
}