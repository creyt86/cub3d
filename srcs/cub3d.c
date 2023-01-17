/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:59:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	if (argc != 2)
		err_msg(ERR_USAGE);
	if (WIN_WID <= 0 || WIN_HEI <= 0)
		err_msg(ERR_SCREEN);
	cub = init_cub(argv);
	cub->mlx->mlx_win = mlx_new_window(cub->mlx->mlx,
			WIN_WID, WIN_HEI, "Cub3D");
	mlx_loop_hook(cub->mlx->mlx, loop_hook, cub);
	mlx_hook(cub->mlx->mlx_win, 2, 1, move_your_bool, cub);
	mlx_hook(cub->mlx->mlx_win, 17, 0, exit_game, cub);
	mlx_loop(cub->mlx->mlx);
	free_all(cub);
	return (EXIT_SUCCESS);
}
