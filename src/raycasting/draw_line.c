/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/06 13:18:25 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_cub3d *cub3d)
{
	float	angle_increment;
	int		i;
	float	dist;
	float	line_height;
	int		draw_start;
	int		draw_end;
	int		j;
	int		nb_ray;
	float	angle;
	float	cast_angle;
	int		color;

	float dx, dy, step, x, y;
	nb_ray = 1080;
	angle_increment = (PI / 2) / nb_ray;
	angle = cub3d->player.pa - (PI / 4);
	i = 0;
	mlx_clear_window(cub3d->mlx_ptr, cub3d->win_ptr[0]);
	while (i < nb_ray)
	{
		dx = cos(angle);
		dy = sin(angle);
		if (fabs(dx) > fabs(dy))
			step = fabs(dx);
		else
			step = fabs(dy);
		dx /= step;
		dy /= step;
		x = cub3d->player.pos.x * 16;
		y = cub3d->player.pos.y * 16;
		while (x >= 0 && x < 528 && y >= 0 && y < 224)
		{
			if (cub3d->map.map[(int)y / 16][(int)x / 16] == '1')
				break ;
			my_mlx_pixel_put_2d(&cub3d->img_2d, (int)x, (int)y, 0x00FF0000);
			x += dx;
			y += dy;
		}
		dist = sqrt(pow(x - cub3d->player.pos.x * 16, 2) + pow(y
					- cub3d->player.pos.y * 16, 2));
		cast_angle = cub3d->player.pa - angle;
		if (cast_angle < 0)
			cast_angle += 2 * PI;
		if (cast_angle > 2 * PI)
			cast_angle -= 2 * PI;
		dist *= cos(cast_angle);
		line_height = 64 * 528 / dist;
		draw_start = (HEIGHT / 2) - (line_height / 2);
		draw_end = (HEIGHT / 2) + (line_height / 2);
		j = 0;
		while (j < HEIGHT)
		{
			if (j < draw_start)
			{
				color = 0x87CEEB;
				my_mlx_pixel_put_3d(&cub3d->img_3d, i, j, color);
			}
			else if (j >= draw_end)
			{
				color = 0x2E8B57;
				my_mlx_pixel_put_3d(&cub3d->img_3d, i, j, color);
			}
			j++;
		}
		j = draw_start;
		while (j < draw_end)
		{
			color = 0x00FF0000;
			my_mlx_pixel_put_3d(&cub3d->img_3d, i, j, color);
			j++;
		}
		angle += angle_increment;
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr[0],
		cub3d->img_3d.img, 0, 0);
}
