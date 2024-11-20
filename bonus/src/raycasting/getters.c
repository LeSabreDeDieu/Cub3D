/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:23:14 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 17:26:03 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

float	get_v_inter(t_cub3d *cub3d, float angle)
{
	int		pixel;
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	v_x = floor(cub3d->player.pos.x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &v_x, &x_step, 0);
	v_y = cub3d->player.pos.y + (v_x - cub3d->player.pos.x) * tan(angle);
	if (((angle > 0 && angle < PI) && y_step < 0) || (!(angle < PI || angle > 2
				* PI) && y_step > 0))
		y_step *= -1;
	while (wall_hit(cub3d, v_x - pixel, v_y))
	{
		v_x += x_step;
		v_y += y_step;
	}
	cub3d->ray.vert_x = v_x;
	cub3d->ray.vert_y = v_y;
	return (sqrt(pow(v_x - cub3d->player.pos.x, 2) + pow(v_y
				- cub3d->player.pos.y, 2)));
}

float	get_h_inter(t_cub3d *cub3d, float angle)
{
	int		pixel;
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	h_y = floor(cub3d->player.pos.y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &h_y, &y_step, 1);
	h_x = cub3d->player.pos.x + (h_y - cub3d->player.pos.y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y')
			&& x_step < 0))
		x_step *= -1;
	while (wall_hit(cub3d, h_x, h_y - pixel))
	{
		h_x += x_step;
		h_y += y_step;
	}
	cub3d->ray.hori_x = h_x;
	cub3d->ray.hori_y = h_y;
	return (sqrt(pow(h_x - cub3d->player.pos.x, 2) + pow(h_y
				- cub3d->player.pos.y, 2)));
}

int	get_texture_color(t_img *texture, float x_offset, float y_offset)
{
	int	color;
	int	x;
	int	y;

	x = fmodf(x_offset, TILE_SIZE) * (texture->width / TILE_SIZE);
	y = fmodf(y_offset, TILE_SIZE) * (texture->height / TILE_SIZE);
	color = texture->addr[y * texture->line_length + x * texture->bits_per_pixel
		/ 8];
	color += texture->addr[y * texture->line_length + x
		* texture->bits_per_pixel / 8 + 1] << 8;
	color += texture->addr[y * texture->line_length + x
		* texture->bits_per_pixel / 8 + 2] << 16;
	return (color);
}

static t_img	*find_texture_by_id(t_cub3d *cub3d, char *direction)
{
	int	i;

	i = 0;
	while (cub3d->texture[i])
	{
		if (!ft_strncmp(cub3d->texture[i]->id, direction, 2))
			return (cub3d->texture[i]->img);
		i++;
	}
	return (NULL);
}

t_img	*get_wall_render_texture(t_cub3d *cub3d, int wall)
{
	cub3d->ray.angle = norm_angle(cub3d->ray.angle);
	if (wall == VERTICAL)
	{
		if (cub3d->ray.angle > PI / 2 && cub3d->ray.angle < 3 * (PI / 2))
			return (find_texture_by_id(cub3d, "WE"));
		else
			return (find_texture_by_id(cub3d, "EA"));
	}
	else if (wall == HORIZONTAL)
	{
		if (cub3d->ray.angle > 0 && cub3d->ray.angle < PI)
			return (find_texture_by_id(cub3d, "NO"));
		else
			return (find_texture_by_id(cub3d, "SO"));
	}
	return (NULL);
}
