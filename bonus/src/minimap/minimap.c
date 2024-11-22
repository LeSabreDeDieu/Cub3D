/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:09:55 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/22 11:31:54 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_map_coords(t_cub3d *cub3d, float *start_x, float *start_y)
{
	float	half_map_size;

	half_map_size = 72.0f;
	*start_x = (cub3d->player.pos.x - half_map_size) / TILE_SIZE;
	*start_y = (cub3d->player.pos.y - half_map_size) / TILE_SIZE;
}

void	draw_wall_floor(t_cub3d *cub3d, t_pos map_pos, t_pos pos)
{
	if (map_pos.x >= 0 && map_pos.x < cub3d->map.width
		&& map_pos.y >= 0 && map_pos.y < cub3d->map.height)
	{
		if (cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == '1')
			my_mlx_pixel_put(&cub3d->img, pos.x + MINIMAP_OFFSET,
				pos.y + MINIMAP_OFFSET, 0x00FFFFFF);
		else
			my_mlx_pixel_put(&cub3d->img, pos.x + MINIMAP_OFFSET,
				pos.y + MINIMAP_OFFSET, 0x00000000);
	}
}

void	draw_map(t_cub3d *cub3d, float start_x, float start_y)
{
	float	radius;
	t_pos	pos;
	t_pos	pos_d;
	t_pos	map_pos;

	radius = 72.0f;
	pos.y = 0;
	while (pos.y < 144)
	{
		pos.x = 0;
		while (pos.x < 144)
		{
			pos_d.x = pos.x - radius;
			pos_d.y = pos.y - radius;
			if (pos_d.x * pos_d.x + pos_d.y * pos_d.y <= radius * radius)
			{
				map_pos.x = (int)(start_x + (float)pos.x / TILE_SIZE);
				map_pos.y = (int)(start_y + (float)pos.y / TILE_SIZE);
				draw_wall_floor(cub3d, map_pos, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_player(t_cub3d *cub3d)
{
	int	x;
	int y;
	int	px;
	int	py;

	y = -4;
	while (y < 4)
	{
		x = -4;
		while (x < 4)
		{
			px = (int)(72.0f + x);
			py = (int)(72.0f + y);
			if ((x * x + y * y) <= 4 * 4)
				my_mlx_pixel_put(&cub3d->img, px + MINIMAP_OFFSET, py
					+ MINIMAP_OFFSET, 0x00FF0000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	float start_x, start_y;
	calculate_map_coords(cub3d, &start_x, &start_y);
	draw_map(cub3d, start_x, start_y);
	draw_player(cub3d);
}
