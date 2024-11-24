/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/24 09:29:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_vision_cone(t_cub3d *cub3d)
{
	float	start_x;
	float	start_y;
	float	angle;

	calculate_map_coords(cub3d, &start_x, &start_y);
	printf("start_x: %f, start_y: %f\n", start_x, start_y);
	angle = cub3d->player.pa - (FOV / 2);
	while (start_y < MINIMAP_SIZE / 2)
	{
		angle = cub3d->player.pa - (FOV / 2);
		while (angle < cub3d->player.pa + (FOV / 2))
		{
			if (wall_hit(cub3d, start_x, start_y))
				break ;
			start_x += cos(deg_to_rad(angle));
			start_y += sin(deg_to_rad(angle));
			angle += 0.1;
		}
		start_y++;
	}
}

void	draw_player(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	px;
	int	py;

	y = -4;
	while (y < 4)
	{
		x = -4;
		while (x < 4)
		{
			px = (int)((MINIMAP_SIZE / 2) + x);
			py = (int)((MINIMAP_SIZE / 2) + y);
			if ((x * x + y * y) <= 4 * 4)
				my_mlx_pixel_put(&cub3d->img, WIDTH - (px + MINIMAP_OFFSET), py
					+ MINIMAP_OFFSET, 0x00FF0000);
			x++;
		}
		y++;
	}
}
