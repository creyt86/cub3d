/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:03:53 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 12:23:52 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_grid(t_grid *grid, t_cub *cub)
{
	grid->size = cub->map->tile_draw_size;
	grid->p_x = floor(cub->p->x / cub->map->tile_size);
	grid->p_y = floor(cub->p->y / cub->map->tile_size);
	grid->i = grid->p_y - 5;
	grid->k = 0;
}

void	put_rectangles(t_grid *grid, t_cub *cub)
{
	int	x;
	int	y;

	x = grid->l * grid->size + (cub->map->tile_draw_size * 2);
	y = grid->k * grid->size + (cub->map->tile_draw_size * 2);
	if (grid->i < 0 || grid->j < 0 || grid->i > cub->map->nbr_line - 1
		|| grid->j > cub->map->len_line - 1)
		;
	else if (cub->map->map2d[grid->i][grid->j] == '1')
		put_rectangle(x, y, cub, make_trgb(50, 105, 105, 105));
	else if (cub->map->map2d[grid->i][grid->j] == '0'
		|| is_player(cub->map->map2d[grid->i][grid->j]))
		put_rectangle(x, y, cub, make_trgb(50, 180, 180, 180));
}

void	put_grid2(t_cub *cub)
{
	t_grid	grid;

	init_grid(&grid, cub);
	while (grid.i < grid.p_y + 6)
	{
		grid.j = grid.p_x - 5;
		grid.l = 0;
		while (grid.j < grid.p_x + 6)
		{
			put_rectangles(&grid, cub);
			grid.j++;
			grid.l++;
		}
		grid.k++;
		grid.i++;
	}
}
