/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:35:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_arr(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	free(map->map);
	free(map->w_no);
	free(map->w_so);
	free(map->w_we);
	free(map->w_ea);
	free_arr(map->map2d, map->nbr_line);
}

void	free_all(t_cub *cub)
{
	int	i;

	i = 0;
	free_map(cub->map);
	free(cub->map);
	free(cub->p);
	free(cub->ray);
	while (i < cub->nbr_t)
	{
		mlx_destroy_image(cub->mlx->mlx, cub->t[i].img);
		i++;
	}
	free(cub->t);
	mlx_destroy_image(cub->mlx->mlx, cub->mlx->img);
	mlx_destroy_window(cub->mlx->mlx, cub->mlx->mlx_win);
	free(cub->mlx);
	free(cub);
}
