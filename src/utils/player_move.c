/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:23:40 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/06 09:30:44 by sgabsi           ###   ########.fr       */
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
	cub3d->player.d_pos_l.x = cos(cub3d->player.pa - PI / 2) * 0.1;
	cub3d->player.d_pos_l.y = sin(cub3d->player.pa - PI / 2) * 0.1;
	cub3d->player.pos.x += cub3d->player.d_pos_l.x;
	if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
		+ 4 >= 528)
		cub3d->player.pos.x -= cub3d->player.d_pos_l.x;
	cub3d->player.pos.y += cub3d->player.d_pos_l.y;
	if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
		+ 4 >= 224)
		cub3d->player.pos.y -= cub3d->player.d_pos_l.y;
}

void	player_move_right(t_cub3d *cub3d)
{
	cub3d->player.d_pos_r.x = cos(cub3d->player.pa + PI / 2) * 0.1;
	cub3d->player.d_pos_r.y = sin(cub3d->player.pa + PI / 2) * 0.1;
	cub3d->player.pos.x += cub3d->player.d_pos_r.x;
	if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
		+ 4 >= 528)
		cub3d->player.pos.x -= cub3d->player.d_pos_r.x;
	cub3d->player.pos.y += cub3d->player.d_pos_r.y;
	if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
		+ 4 >= 224)
		cub3d->player.pos.y -= cub3d->player.d_pos_r.y;
}
