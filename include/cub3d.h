/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:01:27 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/14 14:35:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* INCLUDE PATHES */
// # include "libft.h"
// # include "mlx.h"

/* INCLUDE PATHES */
# include "../utils/libft/libft.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/mlx/mlx.h"
# include "../utils/ft_printf/ft_printf.h"

/* INCLUDE LIBRARY */
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

/* DEFINE COLORS HEX*/
# define BLOOD 0x8d0b0b
# define GREY 0xcecece
# define WHITE 0xffffff
# define BLACK 0x000000

/* DEFINE KEYS */
# define KEY_W 13
# define KEY_A 0
# define KEY_S 2
# define KEY_D 1
# define KEY_M 46
# define KEY_N 45
# define KEY_E 14
# define KEY_H 4
# define KEY_SPACE 49
# define R_KEY 124
# define L_KEY 123
# define KEY_ESC 53

/* DEFINE SIZES */
# define WIN_WID 1400
# define WIN_HEI 900

/* DEFINE CHAR */
# define EXT ".cub"
# define IS_SPACE " \n\t\v\f\r"
# define IS_PLAYER "NSWE"
# ifndef IS_MAP
#  define IS_MAP "01NSWE"
# endif

/* DEFINE VALUES */
# define SMP 5
# define SPD 60

/* ERRORS MESSAGES */
# define ERROR "\033[31mError\e[39m\n"
# define ERR_USAGE "Usage: ./cub3D map.cub\n"
# define ERR_SCREEN "Invalid size screen\n"
# define ERR_FILE "File name must be .cub\n"
# define ERR_FD "File not found\n"
# define ERR_COLOR "Wrong color\n"
# define ERR_MALLOC "Cannot allocate memory\n"
# define ERR_TEXTURE "Texture not found\n"
# define ERR_MAP_INFO "Invalid map info\n"
# define ERR_MAP_CLOSE "The map is like the Emmental!\n"
# define ERR_MAP_CONTENT "Invalid content map\n"
# define ERR_MAP_SIZE "Invalid size map\n"
# define ERR_MAP_PLAYER "Invalid player map\n"

/* STRUCT */
typedef struct s_grid
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	p_x;
	int	p_y;
	int	size;
}t_grid;

typedef struct s_map
{
	char	*map;
	char	**map2d;
	char	*w_no;
	char	*w_so;
	char	*w_we;
	char	*w_ea;
	int		floor;
	int		ceiling;
	int		nbr_line;
	int		len_line;
	int		tile_size;
	int		tile_draw_size;
}t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_mlx;

typedef struct s_player
{
	int			initiated;
	long double	x;
	long double	y;
	long double	d_x;
	long double	d_y;
	long double	angle;
}t_player;

typedef struct s_ray
{
	long double	x;
	long double	y;
	long double	delta;
	char		side;
	int			ver_hor;
	long double	relative_angle;
	float		angle;
}t_ray;

typedef struct s_texture
{
	void	*img;
	int		bits_nb;
	int		len_line;
	int		endien;
	int		*addr;
	int		width;
	int		height;
}t_texture;

typedef struct s_hud
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
	int		is_hud;
	int		sign;
	int		is_animated;
}t_hud;

typedef struct s_cub
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*p;
	t_ray		*ray;
	t_texture	*t;
	t_hud		hud;
	int			nbr_t;
	int			frame;
	int			last_frame;
	int			is_mouse;
	int			prev_x;
	int			pov_y;
	int			is_minimap;
}t_cub;

/* MANDATORY */
/* error.c */
void	err_msg(char *str);
int		exit_game(t_cub *cub);

// parse.c
void	parse_map(t_map *map, char **av);

// free.c
void	free_all(t_cub *cub);
void	free_arr(char	**arr, int len);
void	free_map(t_map *map);

// map_utils.c
int		get_elems(t_map *map);
int		is_map(char c);

// checker_map.c
void	check_ext(char *path);
int		is_color(int one_color);
void	check_map2d(t_map *map);

// test.c
void	print_map2d(t_map *map);
void	print_info_map(t_map *map);

// draw.c
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	put_rectangle(int x, int y, t_cub *cub, int color);
int		make_trgb(int t, int r, int g, int b);
void	draw_line(int x2, int y2, t_cub *cub, int color);
int		my_mlx_pixel_get(t_texture *texture, int x, int y);

// player .c
void	get_player_pos(t_cub *cub);
int		is_player(char c);
void	display_player(t_cub *cub);
void	display_angle(t_cub *cub);
void	update_angle(int key, t_cub *cub);
void	choose_direction(t_cub *cub, int key);
void	get_ray(t_cub *cub);

// init.c
t_cub	*init_cub(char **av);

// display_map.c
int		loop_hook(t_cub	*cub);
void	put_background(t_cub *cub);
void	update_image(t_cub *cub);

// in_keys_hook.c
int		move_your_bool(int key, t_cub *cub);

// ray.c
void	get_vertical_ray(t_cub *cub, t_ray *ray, float angle);
void	get_horizontal_ray(t_cub *cub, t_ray *ray, float angle);
t_ray	*select_ray(t_cub *cub, float angle, t_ray *ray);
void	get_all_rays(t_cub *cub);

// ray_tracing.c
void	display_rays(t_cub *cub);

// display_minimap.c
void	put_grid2(t_cub *cub);

// math_utils.c
double	rad_to_degree(double rad);
double	degree_to_rad(double degree);
float	precision(double num, int digit);
int		less_is_more(int x);

// map_utils2.c
char	*ft_strjoin_f(char *s1, char *s2, int mode);
char	*ft_strtrim_head(char *s1, char const *set);
int		ft_isspace(int c);
int		ft_nbrlen(int n);
size_t	ft_strlen_c(char *str, char c);

#endif