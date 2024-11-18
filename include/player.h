/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:18:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 13:04:27 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// -------------------------- include section -------------------------- //
# include "cub3d.h"

// -------------------------- struct section -------------------------- //
typedef struct s_cub3d	t_cub3d;

// struct for the position
typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

// struct for the player
typedef struct s_player
{
	t_pos				pos;
	t_pos				d_pos_p;
	t_pos				d_pos_l;
	t_pos				d_pos_r;
	t_pos				move;
	float				pa;
	float				fov_rd;
}						t_player;

// -------------------------- function section -------------------------- //
// INIT
void					init_player(t_cub3d *cub3d);

// PLAYER MOVE
void				player_move_forward(t_cub3d *cub3d);
void				player_move_backward(t_cub3d *cub3d);
void				player_move_left(t_cub3d *cub3d);
void				player_move_right(t_cub3d *cub3d);

// CAMERA ROT
void				camera_rot_left(t_cub3d *cub3d);
void				camera_rot_right(t_cub3d *cub3d);

// ---------------------------- end of file ---------------------------- //
#endif