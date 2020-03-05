/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:59:49 by mbani             #+#    #+#             */
/*   Updated: 2020/01/19 13:43:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# define FOV 60
# define tile_size 64
int g_width;
int g_height;
char **g_map;
int g_fred;
int g_fgreen;
int g_fblue;
int g_sred;
int g_sgreen;
int g_sblue;
char *g_npath;
char *g_spath;
char *g_wepath;
char *g_eapath;
char *g_sprit;


typedef struct		s_list
{
	float			x;
   float            y;
   float dis;
	struct s_list	*next;
}					t_list;

typedef struct		s_bmp
{
    unsigned int width;
    unsigned int height;
    unsigned short bitcount;
    unsigned int width_in_bytes;
    unsigned int img_sz;
    unsigned int bisize;
    unsigned int bf0ffbits;
    unsigned int filesize;
    unsigned short biplanes;
    unsigned char *header;
}					t_bmp;

typedef struct s_cor
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
    void *img_tex_n;
    void *img_tex_s;
    void *img_tex_e;
    void *img_tex_w;  
    void *img_add;
    void *img_sp;
    int wall_col;
    float offset;
    float j;
    float factor;
    int *color;
    int *sp_add;
    float img_w;
    int sizeline;
    int color_tex;
    int map_rows;
    int map_col;
    float sp_dis;
    float wall_dis[2560];
} t_cor;

struct s_key
{
     int go_for;
    int go_back;
    int go_left;
    int go_right;
    int see_up;
    int see_down;
    int exit;
    int see_right;
    int see_left;
    int jump;
}   t_go;

void res_check(char *line);
void file_check(char *line);
void file_cub(t_cor *mlx, char *argv);
int	ft_atoi(const char *str);
char    *ft_strdup1(const char *s1);
char	*ft_strchr(const char *s, int c);
void    ft_sprite(t_cor *mlx, float dis);
void sort_sprite(t_list **head1);
void sprites(t_cor *mlx);
int rgb_to_int(int r, int g, int b);
int shadow_effect(int rgb, float dis);
void	*ft_memcpy(void *dst, const void *src, unsigned int n);
void bmp_file(t_cor *mlx);
void	bmp_next(t_cor *mlx, t_bmp *bmp);
void 	bmp_last(t_bmp *bmp,unsigned char *buf);
int ft_keypress(int key);
int ft_keyrel(int key);
char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
void rm_sp(char **s);
void color_check(char *line);
int	ft_isdigit(int c);
void	sky_col(char *line);
void	floor_col(char *line);
void ft_error(char *s);
int		ft_isdigit(int c);
void	res_error(char *line);
void	res_check(char *line);
void	rm_sp(char **s);
void north(char **line);
void    south(char **line);
void weast(char **line);
void east(char **line);
void sprite_path(char **line);
void ft_error(char *s);
void map_check(int j, t_cor *mlx);
#endif