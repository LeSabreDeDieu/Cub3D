/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 12:10:07 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
					+ MINIMAP_OFFSET + 5, 0x00FF0000);
			x++;
		}
		y++;
	}
}
