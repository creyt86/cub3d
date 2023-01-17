/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:20:05 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_player(char c)
{
	if (ft_strchr(IS_PLAYER, c))
		return (1);
	return (0);
}

int	player_start(char c, int x, int y, t_cub *cub)
{
	int	mid;

	mid = cub->map->tile_size / 2;
	if (c == 'N')
		cub->p->angle = 90. * (M_PI / 180.0);
	else if (c == 'W')
		cub->p->angle = 180. * (M_PI / 180.0);
	else if (c == 'E')
		cub->p->angle = 0. * (M_PI / 180.0);
	else if (c == 'S')
		cub->p->angle = 270. * (M_PI / 180.0);
	else
		return (0);
	cub->p->x = (float)(x * cub->map->tile_size + mid);
	cub->p->y = (float)(y * cub->map->tile_size + mid);
	return (1);
}

void	get_player_pos(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	if (cub->p->initiated == 1)
		return ;
	while (i < cub->map->nbr_line)
	{
		j = 0;
		while (j < cub->map->len_line)
		{
			if (player_start(cub->map->map2d[i][j], j, i, cub))
			{
				cub->p->initiated = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	display_angle(t_cub *cub)
{
	int	x2;
	int	y2;
	int	size;

	size = cub->map->tile_draw_size / 2;
	x2 = cub->p->x / cub->map->tile_size * cub->map->tile_draw_size
		+ (int)((float)cos((double)cub->p->angle) * size);
	y2 = cub->p->y / cub->map->tile_size * cub->map->tile_draw_size
		- (int)((float)sin((double)cub->p->angle) * size);
	my_mlx_pixel_put(cub->mlx, x2, y2, make_trgb(0, 255, 0, 0));
	draw_line(x2, y2, cub, make_trgb(0, 255, 0, 0));
}

void	update_angle(int key, t_cub *cub)
{
	if (key == L_KEY)
	{
		cub->p->angle += 0.1;
		if (cub->p->angle == 360. * (M_PI / 180))
			cub->p->angle = 0.;
		if (cub->p->angle > 360. * (M_PI / 180))
			cub->p->angle = 0. + (cub->p->angle - 2 * M_PI);
	}
	if (key == R_KEY)
	{
		cub->p->angle -= 0.1;
		if (cub->p->angle == 0.)
			cub->p->angle = 360. * (M_PI / 180);
		if (cub->p->angle < 0.)
			cub->p->angle = 2 * M_PI - (cub->p->angle * -1);
	}
}
