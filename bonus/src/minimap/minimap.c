/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:09:55 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/22 14:31:54 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	calculate_map_coords(t_cub3d *cub3d, float *start_x, float *start_y)
{
	float	half_map_size;

	half_map_size = MINIMAP_SIZE / 2;
	*start_x = (cub3d->player.pos.x - half_map_size) / TILE_SIZE;
	*start_y = (cub3d->player.pos.y - half_map_size) / TILE_SIZE;
}

void	draw_wall_floor(t_cub3d *cub3d, t_pos map_pos, t_pos pos)
{
	int	i;
	int	*colors;

	i = 0;
	while (cub3d->texture[i])
	{
		if (!ft_strncmp(cub3d->texture[i]->id, "F", 1))
		{
			colors = cub3d->texture[i]->color;
			break ;
		}
		i++;
	}
	if (map_pos.x >= 0 && map_pos.x < cub3d->map.width && map_pos.y >= 0
		&& map_pos.y < cub3d->map.height)
	{
		if (cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == '1')
			my_mlx_pixel_put(&cub3d->img, pos.x + MINIMAP_OFFSET, pos.y
				+ MINIMAP_OFFSET, 0x00FFFFFF);
		else if (cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == '0'
			|| ((cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == 'N'
					|| cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == 'S'
					|| cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == 'E'
					|| cub3d->map.map[(int)map_pos.y][(int)map_pos.x] == 'W')))
			my_mlx_pixel_put(&cub3d->img, pos.x + MINIMAP_OFFSET, pos.y
				+ MINIMAP_OFFSET, create_rgb(colors[0], colors[1], colors[2]));
		else
			my_mlx_pixel_put(&cub3d->img, pos.x + MINIMAP_OFFSET, pos.y
				+ MINIMAP_OFFSET, create_rgb(124, 63, 0));
	}
}

void	draw_map(t_cub3d *cub3d, float start_x, float start_y)
{
	float	radius;
	t_pos	pos;
	t_pos	pos_d;
	t_pos	map_pos;

	radius = MINIMAP_SIZE / 2;
	pos.y = 0;
	while (pos.y < MINIMAP_SIZE)
	{
		pos.x = 0;
		while (pos.x < MINIMAP_SIZE)
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

void	draw_background_circle(t_cub3d *cub3d, int color)
{
	float	radius;
	t_pos	pos;
	t_pos	pos_d;

	radius = (MINIMAP_SIZE + MINIMAP_OFFSET) / 2;
	pos.y = 0;
	while (pos.y < MINIMAP_SIZE + MINIMAP_OFFSET)
	{
		pos.x = 0;
		while (pos.x < MINIMAP_SIZE + MINIMAP_OFFSET)
		{
			pos_d.x = pos.x - radius;
			pos_d.y = pos.y - radius;
			if (pos_d.x * pos_d.x + pos_d.y * pos_d.y <= radius * radius)
				my_mlx_pixel_put(&cub3d->img, pos.x + (MINIMAP_OFFSET / 2),
					pos.y + (MINIMAP_OFFSET / 2), color);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_minimap(t_cub3d *cub3d)
{
	float	start_x;
	float	start_y;

	calculate_map_coords(cub3d, &start_x, &start_y);
	draw_background_circle(cub3d, create_rgb(204, 170, 135));
	draw_map(cub3d, start_x, start_y);
	draw_player(cub3d);
}
