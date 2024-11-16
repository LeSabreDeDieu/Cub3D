/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:20:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/16 13:27:15 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_floor(t_cub3d *cub3d, int ray, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < HEIGHT)
		my_mlx_pixel_put(&cub3d->img_3d, ray, i++,
			create_rgb(cub3d->texture[FLOOR]->color[0],
				cub3d->texture[FLOOR]->color[1],
				cub3d->texture[FLOOR]->color[2]));
}

static void	draw_ceiling(t_cub3d *cub3d, int ray, int t_pix)
{
	int	i;

	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(&cub3d->img_3d, ray, i++,
			create_rgb(cub3d->texture[CEILING]->color[0],
				cub3d->texture[CEILING]->color[1],
				cub3d->texture[CEILING]->color[2]));
}

static void	draw_wall(t_cub3d *cub3d, int ray, double top_pixel,
		double bottom_pixel)
{
	int	color;

	color = get_color(cub3d, cub3d->ray.wall);
	while (top_pixel < bottom_pixel)
		my_mlx_pixel_put(&cub3d->img_3d, ray, top_pixel++, color);
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
	draw_wall(cub3d, ray, top_pixel, bottom_pixel);
	draw_floor(cub3d, ray, bottom_pixel);
	draw_ceiling(cub3d, ray, top_pixel);
}
