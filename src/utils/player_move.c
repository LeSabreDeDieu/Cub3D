/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:23:40 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 11:15:04 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_cub3d *cub3d)
{
	int	map_x;
	int	map_y;
	int new_x;
	int new_y;

	new_x = roundf(cub3d->player.pos.x + cub3d->player.move.x);
	new_y = roundf(cub3d->player.pos.y + cub3d->player.move.y);
	map_x = new_x / TILE_SIZE;
	map_y = new_y / TILE_SIZE;
	if (cub3d->map.map[map_y][map_x] != '1'
		&& (cub3d->map.map[map_y][new_x / TILE_SIZE] != '1')
		&& (cub3d->map.map[new_y / TILE_SIZE][map_x] != '1'))
	{
		cub3d->player.pos.x = new_x;
		cub3d->player.pos.y = new_y;
	}
}

void	player_move_forward(t_cub3d *cub3d)
{
	cub3d->player.move.x = cos(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = sin(cub3d->player.pa) * MOVE_SPEED;
	move_player(cub3d);
}

void	player_move_backward(t_cub3d *cub3d)
{
	cub3d->player.move.x = -cos(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = -sin(cub3d->player.pa) * MOVE_SPEED;
	move_player(cub3d);
}

void	player_move_left(t_cub3d *cub3d)
{
	cub3d->player.move.x = sin(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = -cos(cub3d->player.pa) * MOVE_SPEED;
	move_player(cub3d);
}

void	player_move_right(t_cub3d *cub3d)
{
	cub3d->player.move.x = -sin(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = cos(cub3d->player.pa) * MOVE_SPEED;
	move_player(cub3d);
}
