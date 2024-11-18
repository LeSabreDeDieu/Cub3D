/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/16 13:09:30 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_cub3d *cub3d)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	cub3d->ray.angle = cub3d->player.pa - (cub3d->player.fov_rd / 2);
	while (ray < WIDTH)
	{
		h_inter = get_h_inter(cub3d, norm_angle(cub3d->ray.angle));
		v_inter = get_v_inter(cub3d, norm_angle(cub3d->ray.angle));
		if (h_inter < v_inter)
		{
			cub3d->ray.dist = h_inter;
			cub3d->ray.wall = HORIZONTAL;
		}
		else
		{
			cub3d->ray.dist = v_inter;
			cub3d->ray.wall = VERTICAL;
		}
		render_wall(cub3d, ray);
		ray++;
		cub3d->ray.angle += cub3d->player.fov_rd / WIDTH;
	}
}
