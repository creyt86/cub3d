/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:01:26 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_collision(t_cub *cub, int col_x, int col_y)
{
	if (cub->map->map2d[(int)floor(col_y / cub->map->tile_size)]
		[(int)floor(col_x / cub->map->tile_size)] != '1')
	{
		if (cub->map->map2d[(int)floor(col_y / cub->map->tile_size)]
			[(int)floor(col_x / cub->map->tile_size)] != 'D')
		{
			cub->p->x = cub->p->d_x;
			cub->p->y = cub->p->d_y;
		}
	}
}

void	choose_direction(t_cub *cub, int o_key)
{
	float			tmp_angle;
	float			col_x;
	float			col_y;

	if (o_key == KEY_D)
		tmp_angle = cub->p->angle + 180. * (M_PI / 180.0);
	if (o_key == KEY_A)
		tmp_angle = cub->p->angle + 90. * (M_PI / 180.0);
	if (o_key == KEY_S)
		tmp_angle = cub->p->angle - 90. * (M_PI / 180.0);
	if (o_key == KEY_W)
		tmp_angle = cub->p->angle;
	cub->p->d_x = cub->p->x + (int)((float)cos((double)tmp_angle) * SPD);
	cub->p->d_y = cub->p->y - (int)((float)sin((double)tmp_angle) * SPD);
	col_x = cub->p->x + (int)((float)cos((double)tmp_angle) * (SPD * SMP));
	col_y = cub->p->y - (int)((float)sin((double)tmp_angle) * (SPD * SMP));
	check_collision(cub, col_x, col_y);
}
