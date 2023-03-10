/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:18:50 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 14:23:02 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// if you want to display the fov in the minimap,
// we should use my_put_pixel in a separate function after the raycasting
void	get_all_rays(t_cub *cub)
{
	int		i;
	float	angle;
	float	angle_diff;

	i = 0;
	angle_diff = (60. / (float)WIN_WID);
	angle = cub->p->angle / (M_PI / 180.) - 30.;
	if (angle < 0.)
		angle += 360;
	while (i < WIN_WID)
	{
		angle += angle_diff;
		if (angle >= 360)
			angle = 0. + (angle - 360);
		select_ray(cub, angle * (M_PI / 180.), &(cub->ray[i]));
		i++;
	}
}

int	choose_texture(t_cub *cub, t_ray *ray, int y, int size)
{
	int	s;
	int	color;

	if (ray->side == 'N')
		s = 0;
	if (ray->side == 'S')
		s = 1;
	if (ray->side == 'E')
		s = 2;
	if (ray->side == 'W')
		s = 3;
	if (ray->ver_hor == 0)
		color = (my_mlx_pixel_get(&cub->t[s],
					floor(((int)ray->x % cub->map->tile_size)
						* cub->t[s].width / cub->map->tile_size),
					floor(y * cub->t[s].height / size)));
	if (ray->ver_hor == 1)
		color = (my_mlx_pixel_get(&cub->t[s],
					floor(((int)ray->y % cub->map->tile_size)
						* cub->t[s].width / cub->map->tile_size),
					floor(y * cub->t[s].height / size)));
	return (color);
}

void	display_ray(t_cub *cub, int x, int j)
{
	float	distance;
	int		size;
	int		i;
	int		color;

	i = 0;
	distance = cub->ray[j].delta * cos(cub->ray[j].relative_angle);
	size = cub->map->tile_size / distance * 512;
	while (i < size)
	{
		if (cub->ray[j].side == -1 && j > WIN_WID / 2)
			cub->ray[j].side = cub->ray[j - 10].side;
		else if (cub->ray[j].side == -1 && j < WIN_WID / 2)
			cub->ray[j].side = cub->ray[j + 10].side;
		color = choose_texture(cub, &cub->ray[j], size + i, size * 2);
		my_mlx_pixel_put(cub->mlx, x,
			WIN_HEI / 2 + i - cub->pov_y, color);
		color = choose_texture(cub, &cub->ray[j], size - i, size * 2);
		my_mlx_pixel_put(cub->mlx, x,
			WIN_HEI / 2 - i - cub->pov_y, color);
		i++;
	}
}

void	display_rays(t_cub *cub)
{
	int	x;
	int	i;

	i = WIN_WID - 1;
	x = 0;
	while (i >= 0)
	{	
		display_ray(cub, x, i);
		x++;
		i--;
	}
}
