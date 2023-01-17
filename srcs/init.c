/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:56 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_texture(t_cub *cub)
{
	int	i;

	i = -1;
	cub->t[0].img = mlx_xpm_file_to_image(cub->mlx->mlx,
			cub->map->w_no, &cub->t[0].width, &cub->t[0].height);
	cub->t[1].img = mlx_xpm_file_to_image(cub->mlx->mlx,
			cub->map->w_so, &cub->t[1].width, &cub->t[1].height);
	cub->t[2].img = mlx_xpm_file_to_image(cub->mlx->mlx,
			cub->map->w_ea, &cub->t[2].width, &cub->t[2].height);
	cub->t[3].img = mlx_xpm_file_to_image(cub->mlx->mlx,
			cub->map->w_we, &cub->t[3].width, &cub->t[3].height);
	while (++i < cub->nbr_t)
	{
		if (!cub->t[i].img)
			err_msg(ERR_TEXTURE);
		cub->t[i].addr = (int *)mlx_get_data_addr(cub->t[i].img,
				&cub->t[0].bits_nb, &cub->t[i].len_line, &cub->t[i].endien);
	}
	return (1);
}

void	malloc_cub(t_cub *cub)
{
	cub->map = ft_calloc(sizeof(t_map), 1);
	if (!cub->map)
		err_msg(ERR_MALLOC);
	cub->mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!cub->mlx)
		err_msg(ERR_MALLOC);
	cub->p = ft_calloc(sizeof(t_player), 1);
	if (!cub->p)
		err_msg(ERR_MALLOC);
	cub->t = ft_calloc(sizeof(t_texture), cub->nbr_t);
	if (!cub->t)
		err_msg(ERR_MALLOC);
	cub->ray = ft_calloc(WIN_WID, sizeof(t_ray));
	if (!cub->ray)
		err_msg(ERR_MALLOC);
}

void	init_row_cub(t_cub *cub)
{
	cub->is_minimap = 1;
	cub->last_frame = 0;
	cub->nbr_t = 4;
}

t_cub	*init_cub(char **av)
{
	t_cub	*cub;

	cub = ft_calloc(sizeof(t_cub), 1);
	if (!cub)
		err_msg(ERR_MALLOC);
	init_row_cub(cub);
	malloc_cub(cub);
	cub->mlx->mlx = mlx_init();
	cub->mlx->img = mlx_new_image(cub->mlx->mlx, WIN_WID, WIN_HEI);
	cub->mlx->addr = mlx_get_data_addr(cub->mlx->img,
			&cub->mlx->bits_per_pixel,
			&cub->mlx->line_length, &cub->mlx->endian);
	parse_map(cub->map, av);
	init_texture(cub);
	get_player_pos(cub);
	cub->prev_x = WIN_WID / 2;
	cub->pov_y = 0;
	return (cub);
}
