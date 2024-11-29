/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:26:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 08:36:26 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
