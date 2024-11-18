/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:26:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 12:51:00 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_rot_left(t_cub3d *cub3d)
{
	cub3d->player.pa -= 0.05;
	if (cub3d->player.pa < 0)
		cub3d->player.pa += 2 * PI;
}

void	camera_rot_right(t_cub3d *cub3d)
{
	cub3d->player.pa += 0.05;
	if (cub3d->player.pa > 2 * PI)
		cub3d->player.pa -= 2 * PI;
}
