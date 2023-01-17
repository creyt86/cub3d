/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:27:27 by creyt             #+#    #+#             */
/*   Updated: 2023/01/14 12:24:46 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// if (x >= WIN_WID || y >= WIN_HEI)
	// 	return (1);
//--> the code above does not work but we need another way
// to check high value x and y in order to reduce the lag
int	reach_wall(int x, int y, t_cub *cub, t_ray *ray)
{
	if (x <= 0 || y <= 0)
		return (1);
	if (x / cub->map->tile_size > cub->map->len_line - 1
		|| y / cub->map->tile_size > cub->map->nbr_line - 1)
		return (1);
	if (cub->map->map2d[y / cub->map->tile_size]
		[x / cub->map->tile_size] == '1')
	{
		ray->side = 0;
		return (1);
	}
	return (0);
}

void	dup_ray(t_ray *ray, t_ray *dup)
{
	dup->x = ray->x;
	dup->y = ray->y;
	dup->delta = ray->delta;
	dup->side = ray->side;
	dup->ver_hor = ray->ver_hor;
	dup->relative_angle = ray->relative_angle;
	dup->angle = ray->angle;
}

t_ray	*select_ray(t_cub *cub, float angle, t_ray *ray)
{
	int		d_hor;
	int		d_ver;
	t_ray	last_ray;
	t_ray	dup;

	ray->relative_angle = angle - cub->p->angle;
	dup_ray(ray, &last_ray);
	get_horizontal_ray(cub, ray, angle);
	d_hor = ray->delta;
	dup_ray(ray, &dup);
	get_vertical_ray(cub, ray, angle);
	d_ver = ray->delta;
	if (d_hor < d_ver)
		dup_ray(&dup, ray);
	if (less_is_more(d_ver - d_hor) <= 0)
	{
		if (reach_wall(last_ray.x, last_ray.y + 1, cub, &last_ray)
			&& reach_wall(last_ray.x, last_ray.y - 1, cub, &last_ray))
			dup_ray(&dup, ray);
		else if (reach_wall(last_ray.x + 1, last_ray.y, cub, ray)
			&& reach_wall(last_ray.x - 1, last_ray.y, cub, ray))
			get_vertical_ray(cub, &last_ray, angle);
	}
	return (ray);
}

void	get_vertical_ray(t_cub *cub, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle > 0 && angle < degree_to_rad(180))
		ray->y = floor(cub->p->y / cub->map->tile_size)
			* cub->map->tile_size - 0.001;
	else
	{
		ray->y = floor(cub->p->y / cub->map->tile_size)
			* cub->map->tile_size + cub->map->tile_size;
		direction = -1;
	}
	ray->x = (cub->p->y - ray->y) / tan(angle) + cub->p->x;
	while (!reach_wall(ray->x, ray->y, cub, ray))
	{
		ray->y -= cub->map->tile_size * direction;
		ray->x += cub->map->tile_size / tan(angle) * direction;
	}
	ray->delta = sqrt(pow(cub->p->x - ray->x, 2.)
			+ pow(cub->p->y - ray->y, 2.));
	if (direction == 1 && ray->side != 'D')
		ray->side = 'N';
	else if (ray->side != 'D')
		ray->side = 'S';
	ray->ver_hor = 0;
}

void	get_horizontal_ray(t_cub *cub, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle <= degree_to_rad(90) || angle >= degree_to_rad(270))
		ray->x = floor(cub->p->x / cub->map->tile_size)
			* cub->map->tile_size + cub->map->tile_size;
	else
	{
		ray->x = floor(cub->p->x / cub->map->tile_size)
			* cub->map->tile_size - 0.001;
		direction = -1;
	}
	ray->y = cub->p->y + (cub->p->x - ray->x) * tan(angle);
	while (!reach_wall(ray->x, ray->y, cub, ray))
	{
		ray->x += cub->map->tile_size * direction;
		ray->y -= cub->map->tile_size * tan(angle) * direction;
	}
	ray->delta = sqrt(pow(cub->p->x - ray->x, 2.)
			+ pow(cub->p->y - ray->y, 2.));
	if (direction == 1 && ray->side != 'D')
		ray->side = 'E';
	else if (ray->side != 'D')
		ray->side = 'W';
	ray->ver_hor = 1;
}
