/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:02:56 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 14:12:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	loop_hook(t_cub	*cub)
{
	mlx_clear_window(cub->mlx->mlx, cub->mlx->mlx_win);
	update_image(cub);
	//cub->frame = (cub->frame + 1) % 1000000000;
	return (0);
}

void	update_image(t_cub *cub)
{
	put_background(cub);
	get_all_rays(cub);
	display_rays(cub);
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->mlx_win,
		cub->mlx->img, 0, 0);
	if (cub->is_minimap)
	{
		put_grid2(cub);
		display_player(cub);
	}
	mlx_put_image_to_window(cub->mlx->mlx, cub->mlx->mlx_win,
		cub->mlx->img, 0, 0);
}

void	display_player(t_cub *cub)
{
	put_rectangle(cub->map->tile_draw_size * 7,
		cub->map->tile_draw_size * 7, cub, make_trgb(0, 141, 11, 11));
}

void	put_background(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEI)
	{
		j = 0;
		while (j < WIN_WID)
		{
			if (i < WIN_HEI / 2 - cub->pov_y)
				my_mlx_pixel_put(cub->mlx, j, i, cub->map->ceiling);
			else
				my_mlx_pixel_put(cub->mlx, j, i, cub->map->floor);
			j++;
		}
		i++;
	}
}
