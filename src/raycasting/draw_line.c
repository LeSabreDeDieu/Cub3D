/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/05 14:26:21 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_cub3d *cub3d)
{
	float	dx;
	float	dy;
	float	step;
	float	x;
	float	y;

	dx = cos(cub3d->player.pa);
	dy = sin(cub3d->player.pa);
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx /= step;
	dy /= step;
	x = cub3d->player.pos.x * 16;
	y = cub3d->player.pos.y * 16;
	while (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		my_mlx_pixel_put(&cub3d->img, (int)x, (int)y,
			0x00FF0000);
		x += dx;
		y += dy;
	}
}
