/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:23:40 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 10:24:00 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_cub3d *cub3d)
{
	int		map_x;
	int		map_y;
	float	new_x;
	float	new_y;

	new_x = cub3d->player.pos.x + cub3d->player.move.x;
	new_y = cub3d->player.pos.y + cub3d->player.move.y;
	map_x = (int)floor(new_x / TILE_SIZE);
	map_y = (int)floor(new_y / TILE_SIZE);
	if (cub3d->map.map[map_y][map_x] != '1')
	{
		cub3d->player.pos.x = new_x;
		cub3d->player.pos.y = new_y;
	}
}

void	player_move_forward(t_cub3d *cub3d)
{
	cub3d->player.move.x = cosf(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = sinf(cub3d->player.pa) * MOVE_SPEED;
	if (cub3d->key.shift)
	{
		cub3d->player.move.x *= 2;
		cub3d->player.move.y *= 2;
	}
	if (cub3d->key.ctrl)
	{
		cub3d->player.move.x /= 2;
		cub3d->player.move.y /= 2;
	}
	move_player(cub3d);
}

void	player_move_backward(t_cub3d *cub3d)
{
	cub3d->player.move.x = -cosf(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = -sinf(cub3d->player.pa) * MOVE_SPEED;
	if (cub3d->key.shift)
	{
		cub3d->player.move.x *= 2;
		cub3d->player.move.y *= 2;
	}
	if (cub3d->key.ctrl)
	{
		cub3d->player.move.x /= 2;
		cub3d->player.move.y /= 2;
	}
	move_player(cub3d);
}

void	player_move_left(t_cub3d *cub3d)
{
	cub3d->player.move.x = sinf(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = -cosf(cub3d->player.pa) * MOVE_SPEED;
	if (cub3d->key.shift)
	{
		cub3d->player.move.x *= 2;
		cub3d->player.move.y *= 2;
	}
	if (cub3d->key.ctrl)
	{
		cub3d->player.move.x /= 2;
		cub3d->player.move.y /= 2;
	}
	move_player(cub3d);
}

void	player_move_right(t_cub3d *cub3d)
{
	cub3d->player.move.x = -sinf(cub3d->player.pa) * MOVE_SPEED;
	cub3d->player.move.y = cosf(cub3d->player.pa) * MOVE_SPEED;
	if (cub3d->key.shift)
	{
		cub3d->player.move.x *= 2;
		cub3d->player.move.y *= 2;
	}
	if (cub3d->key.ctrl)
	{
		cub3d->player.move.x /= 2;
		cub3d->player.move.y /= 2;
	}
	move_player(cub3d);
}
