/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:39:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 10:34:44 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collision(t_cub3d *cub3d, int map_x, int map_y)
{
	return (!(cub3d->map.map[map_y][map_x] != '1'
			&& cub3d->map.map[map_y][(int)(cub3d->player.pos.x - 0.5)
			/ TILE_SIZE] != '1' && cub3d->map.map[(int)(cub3d->player.pos.y - 0.5)
			/ TILE_SIZE][map_x] != '1'));
}
