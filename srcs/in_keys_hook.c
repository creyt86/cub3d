/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_keys_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:59 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 13:44:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	move_your_bool(int o_key, t_cub *cub)
{
	if (o_key == L_KEY || o_key == R_KEY)
		update_angle(o_key, cub);
	else if (o_key == KEY_W || o_key == KEY_A || o_key == KEY_S || o_key == KEY_D)
		choose_direction(cub, o_key);
	else if (o_key == KEY_ESC)
		exit_game(cub);
	else if (o_key == KEY_M)
		cub->is_minimap = ft_bool(cub->is_minimap);
	return (0);
}
