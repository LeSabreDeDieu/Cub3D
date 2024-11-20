/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:26:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 17:26:03 by aditer           ###   ########.fr       */
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
