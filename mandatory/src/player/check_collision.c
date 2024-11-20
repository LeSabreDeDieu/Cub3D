/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:39:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 08:48:08 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collision(t_cub3d *cub3d, float new_x, float new_y)
{
	t_pos	map_coord;
	t_pos	offset_coord;
	t_pos	check_coord;

	offset_coord.y = -1;
	while (offset_coord.y <= 1)
	{
		offset_coord.x = -1;
		while (offset_coord.x <= 1)
		{
			check_coord.x = new_x + offset_coord.x * 0.5;
			check_coord.y = new_y + offset_coord.y * 0.5;
			map_coord.x = (int)floor(check_coord.x / TILE_SIZE);
			map_coord.y = (int)floor(check_coord.y / TILE_SIZE);
			if (map_coord.x >= 0 && map_coord.x < cub3d->map.width
				&& map_coord.y >= 0 && map_coord.y < cub3d->map.height
				&& cub3d->map.map[(int)map_coord.y][(int)map_coord.x] == '1')
			{
				return (1);
			}
			offset_coord.x++;
		}
		offset_coord.y++;
	}
	return (0);
}
