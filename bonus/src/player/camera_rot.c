/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:26:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 11:35:51 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	camera_rot_left(t_cub3d *cub3d)
{
	cub3d->player.pa -= ROT_SPEED;
	cub3d->player.pa = norm_angle(cub3d->player.pa);
}

void	camera_rot_right(t_cub3d *cub3d)
{
	cub3d->player.pa += ROT_SPEED;
	cub3d->player.pa = norm_angle(cub3d->player.pa);
}

void	mouse_rot(t_cub3d *cub3d)
{
	static int	prev_x = 0;
	int			x;
	int			y;
	int			center_x;
	int			center_y;

	mlx_mouse_get_pos(cub3d->mlx_ptr, cub3d->win_ptr, &x, &y);
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	mlx_mouse_move(cub3d->mlx_ptr, cub3d->win_ptr, center_x, center_y);
	if (prev_x == 0)
		prev_x = x;
	if (x > center_x)
	{
		if (prev_x <= center_x)
			camera_rot_right(cub3d);
	}
	else if (x < center_x)
	{
		if (prev_x >= center_x)
			camera_rot_left(cub3d);
	}
	prev_x = x;
}
