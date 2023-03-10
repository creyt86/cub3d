/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:04:31 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((0 < x && x < WIN_WID) && (0 < y && y < WIN_HEI))
	{
		dst = mlx->addr + (y * mlx->line_length
				+ x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	my_mlx_pixel_get(t_texture *texture, int x, int y)
{
	unsigned int	color;

	color = 0;
	if ((0 <= x && x <= texture->width) && (0 <= y && y <= texture->height))
	{
		color = texture->addr[y * texture->len_line / 4 + x];
	}
	return (color);
}

void	put_rectangle(int x, int y, t_cub *cub, int color)
{
	int	i;
	int	j;
	int	size;

	size = cub->map->tile_draw_size;
	i = y;
	while (i < size + y)
	{
		j = x;
		while (j < size + x)
		{
			my_mlx_pixel_put(cub->mlx, j, i, color);
			j++;
		}
		i++;
	}
}

int	make_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_line(int x2, int y2, t_cub *cub, int color)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (double)x2 - cub->p->x / cub->map->tile_size
		* cub->map->tile_draw_size;
	delta_y = (double)y2 - cub->p->y / cub->map->tile_size
		* cub->map->tile_draw_size;
	pixels = sqrt((delta_x * delta_x) +(delta_y * delta_y));
	pixel_x = cub->p->x / cub->map->tile_size * cub->map->tile_draw_size;
	pixel_y = cub->p->y / cub->map->tile_size * cub->map->tile_draw_size;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(cub->mlx, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}
