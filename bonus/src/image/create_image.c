/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:18:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 13:33:26 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	create_img(t_cub3d *cub3d, t_img *img, int width, int height)
{
	img->img = mlx_new_image(cub3d->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->tile_size = TILE_SIZE;
	img->width = width;
	img->height = height;
}
