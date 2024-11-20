/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:20:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 17:26:03 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_floor(t_cub3d *cub3d, int ray, int b_pix)
{
	int	i;
	int *colors;

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
	i = b_pix;
	while (i < HEIGHT)
		my_mlx_pixel_put(&cub3d->img, ray, i++,
			create_rgb(colors[0], colors[1], colors[2]));
}

static void	draw_ceiling(t_cub3d *cub3d, int ray, int t_pix)
{
	int	i;
	int *colors;

	i = 0;
	while (cub3d->texture[i])
	{
		if (!ft_strncmp(cub3d->texture[i]->id, "C", 1))
		{
			colors = cub3d->texture[i]->color;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(&cub3d->img, ray, i++,
			create_rgb(colors[0], colors[1], colors[2]));
}

static float	get_x_offset(t_cub3d *cub3d, t_img *texture)
{
	float	offset;

	if (cub3d->ray.wall == VERTICAL)
		offset = fmodf(cub3d->ray.vert_y * (texture->width / TILE_SIZE),
				TILE_SIZE);
	else
		offset = fmodf(cub3d->ray.hori_x * (texture->width / TILE_SIZE),
				TILE_SIZE);
	return (offset);
}

static void	draw_wall(t_cub3d *cub3d, double top_pixel, double bottom_pixel,
		double wall_height)
{
	t_img	*texture;
	double	x_offset;
	double	y_offset;
	double	factor;

	texture = get_wall_render_texture(cub3d, cub3d->ray.wall);
	factor = (double)texture->height / wall_height;
	x_offset = get_x_offset(cub3d, texture);
	y_offset = (top_pixel - (HEIGHT / 2) + (wall_height / 2)) * factor;
	if (y_offset < 0)
		y_offset = 0;
	while (top_pixel < bottom_pixel)
	{
		my_mlx_pixel_put(&cub3d->img, cub3d->ray.index, top_pixel,
			get_texture_color(texture, x_offset, y_offset));
		y_offset += factor;
		top_pixel++;
	}
}

void	render_wall(t_cub3d *cub3d, int ray)
{
	double	wall_height;
	double	top_pixel;
	double	bottom_pixel;

	cub3d->ray.dist *= cos(norm_angle(cub3d->ray.angle - cub3d->player.pa));
	wall_height = (TILE_SIZE / cub3d->ray.dist) * ((WIDTH / 2)
			/ tan(cub3d->player.fov_rd / 2));
	top_pixel = (HEIGHT / 2) - (wall_height / 2);
	bottom_pixel = (HEIGHT / 2) + (wall_height / 2);
	if (bottom_pixel > HEIGHT)
		bottom_pixel = HEIGHT;
	if (top_pixel < 0)
		top_pixel = 0;
	cub3d->ray.index = ray;
	draw_wall(cub3d, top_pixel, bottom_pixel, wall_height);
	draw_floor(cub3d, ray, bottom_pixel);
	draw_ceiling(cub3d, ray, top_pixel);
}
