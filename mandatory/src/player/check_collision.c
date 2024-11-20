/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:39:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 13:00:47 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collision(t_cub3d *cub3d, float x, float y)
{
	int map_x = (int)(x / TILE_SIZE);
	int map_y = (int)(y / TILE_SIZE);

	return (cub3d->map.map[map_y][map_x] == '1');
}
