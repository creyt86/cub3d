/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:43:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	rad_to_degree(double rad)
{
	return (180 / M_PI * rad);
}

double	degree_to_rad(double degree)
{
	return (M_PI / 180 * degree);
}

float	precision(double num, int digit)
{
	return (floor(digit * num) / digit);
}

int	less_is_more(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}
