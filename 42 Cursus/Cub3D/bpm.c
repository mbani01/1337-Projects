/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:26:26 by mbani             #+#    #+#             */
/*   Updated: 2020/01/18 17:57:24 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

long long	get_img_pix(void *img, int x, int y)
{
	int endian;
    int sizeline;
	int bpp;
	int *add;
	add = (int *)mlx_get_data_addr (img, &bpp, &sizeline, &endian);
	    return (add[y * g_width + x]);
}
void		bmp_file(t_cor *mlx)
{
	t_bmp bmp;

	bmp.width = g_width;
	bmp.height = g_height;
	bmp.bitcount = 24;
	bmp.bisize = 40;
	bmp.width_in_bytes = ((bmp.width * bmp.bitcount + 31) / 32) * 4;
	bmp.img_sz = bmp.width_in_bytes * bmp.height;
	bmp.bf0ffbits = 54;
	bmp.filesize = 54 + bmp.img_sz;
	bmp.biplanes = 1;
	bmp.header = ft_calloc(54, sizeof(unsigned char));
    ft_memcpy(bmp.header, "BM", 2);
    ft_memcpy(bmp.header + 2 , &bmp.filesize, 4);
    ft_memcpy(bmp.header + 10, &bmp.bf0ffbits, 4);
    ft_memcpy(bmp.header + 14, &bmp.bisize, 4);
    ft_memcpy(bmp.header + 18, &bmp.width, 4);
    ft_memcpy(bmp.header + 22, &bmp.height, 4);
    ft_memcpy(bmp.header + 26, &bmp.biplanes, 2);
    ft_memcpy(bmp.header + 28, &bmp.bitcount, 2);
    ft_memcpy(bmp.header + 34, &bmp.img_sz, 4);
	bmp_next(mlx, &bmp);
}

void		bmp_next(t_cor *mlx, t_bmp *bmp)
{
	unsigned  char	*buf;
	int				*add;
	int				row;
	int				col;
	long long		a;

	buf = malloc(bmp->img_sz);
	row = bmp->height - 1;
	int i = 0;
	while (row >= 0)
	{
		col = 0;
		while (col < bmp->width)
		{
			a = get_img_pix(mlx->img, col, i);
            buf[row * bmp->width_in_bytes + col * 3 + 0] = fmod(a, 256);
            buf[row * bmp->width_in_bytes + col * 3 + 1] = fmod((a / 256), 256);
            buf[row * bmp->width_in_bytes + col * 3 + 2] = fmod(a / 256 / 256, 256);
			col++;
		}
		row--;
		i++;
	}	
	bmp_last(bmp, buf);
}

void		bmp_last(t_bmp *bmp,unsigned char *buf)
{
 	int fd;
	fd = open("cub3d.bmp", O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, 500);
	write(fd, bmp->header, 54);
	write(fd, buf, bmp->img_sz);
	free(buf);
}
