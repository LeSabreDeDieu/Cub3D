/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:24:26 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/14 19:24:56 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	wall_hit(t_cub3d *cub3d, float x, float y)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0 || x >= cub3d->map.width * TILE_SIZE
		|| y >= cub3d->map.height * TILE_SIZE)
		return (0);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	if (cub3d->map.map[y_m] && x_m < (int)ft_strlen(cub3d->map.map[y_m]))
	{
		if (cub3d->map.map[y_m][x_m] == '1')
			return (0);
	}
	return (1);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}
