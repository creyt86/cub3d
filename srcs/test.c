/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:26:33 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_info_map(t_map *map)
{
	printf("w_no[%s]\n", map->w_no);
	printf("w_so[%s]\n", map->w_so);
	printf("w_we[%s]\n", map->w_we);
	printf("w_ea[%s]\n", map->w_ea);
	printf("floor[%d]\n", map->floor);
	printf("ceiling[%d]\n", map->ceiling);
}

void	print_map2d(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line)
		{
			printf("%c", map->map2d[y][x]);
		}
		printf("\n");
	}
}

//void	put_grid(t_cub *cub)
//{
//	int	i;
//	int	j;
//	int	size;
//
//	i = 0;
//	size = cub->map->tile_draw_size;
//	while (i < cub->map->nbr_line)
//	{
//		j = 0;
//		while (j < cub->map->len_line)
//		{
//			if (cub->map->map2d[i][j] == '1')
//				put_rectangle(j * size, i * size, cub, 6316128);
//			else if (cub->map->map2d[i][j] == '0'
//					|| is_player(cub->map->map2d[i][j]))
//				put_rectangle(j * size, i * size, cub, 26316);
//			else if (cub->map->map2d[i][j] == '.')
//				put_rectangle(j * size, i * size, cub, 10526880);
//			else if (cub->map->map2d[i][j] == 'D')
//				put_rectangle(j * size, i * size, cub, 39244);
//			j++;
//		}
//		i++;
//	}
//}
