/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:18:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/16 13:33:22 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_img(t_cub3d *cub3d, t_img *img)
{
	img->img = mlx_new_image(cub3d->mlx_ptr, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->tile_size = TILE_SIZE;
	img->width = cub3d->map.width;
	img->height = cub3d->map.height;
}
