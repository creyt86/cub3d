/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:44:42 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	err_msg(char *str)
{
	printf("%s", ERROR);
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	exit_game(t_cub *cub)
{
	free_all(cub);
	exit(EXIT_SUCCESS);
}
