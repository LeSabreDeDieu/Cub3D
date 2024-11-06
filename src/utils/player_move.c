/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:23:40 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/06 09:25:09 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move_forward(t_cub3d *cub3d)
{
	cub3d->player.pos.x += cub3d->player.d_pos_p.x;
	if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
		+ 4 >= 528)
		cub3d->player.pos.x -= cub3d->player.d_pos_p.x;
	cub3d->player.pos.y += cub3d->player.d_pos_p.y;
	if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
		+ 4 >= 224)
		cub3d->player.pos.y -= cub3d->player.d_pos_p.y;
}

void	player_move_backward(t_cub3d *cub3d)
{
	cub3d->player.pos.x -= cub3d->player.d_pos_p.x;
	if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
		+ 4 >= 528)
		cub3d->player.pos.x += cub3d->player.d_pos_p.x;
	cub3d->player.pos.y -= cub3d->player.d_pos_p.y;
	if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
		+ 4 >= 224)
		cub3d->player.pos.y += cub3d->player.d_pos_p.y;
}

void	player_move_left(t_cub3d *cub3d)
{
	float	angle;

	angle = cub3d->player.pa;
	cub3d->player.pos.x += (cos(angle) * (cub3d->player.d_pos_p.x / 0.1)
			+ cos(angle + PI / 2)) * 0.1;
	cub3d->player.pos.y += (sin(angle) * (cub3d->player.d_pos_p.y / 0.1)
			+ sin(angle + PI / 2)) * 0.1;
	if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
		+ 4 >= 528)
		cub3d->player.pos.x -= cub3d->player.d_pos_p.x;
	if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
		+ 4 >= 224)
		cub3d->player.pos.y -= cub3d->player.d_pos_p.y;
}

void	player_move_right(t_cub3d *cub3d)
{
	float	angle;

	angle = cub3d->player.pa;
	cub3d->player.pos.x += cos(angle) * (cub3d->player.d_pos_p.x / 0.1) * 0.1;
	cub3d->player.pos.y += sin(angle) * (cub3d->player.d_pos_p.y / 0.1) * 0.1;
	if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
		+ 4 >= 528)
		cub3d->player.pos.x -= cub3d->player.d_pos_p.x;
	if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
		+ 4 >= 224)
		cub3d->player.pos.y -= cub3d->player.d_pos_p.y;
}
