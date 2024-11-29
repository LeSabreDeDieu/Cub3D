/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:11:50 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 15:06:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_texture_color_hud(t_img *texture, int x, int y)
{
	int	color;

	color = texture->addr[y * texture->line_length + x * texture->bits_per_pixel
		/ 8];
	color += texture->addr[y * texture->line_length + x
		* texture->bits_per_pixel / 8 + 1] << 8;
	color += texture->addr[y * texture->line_length + x
		* texture->bits_per_pixel / 8 + 2] << 16;
	return (color);
}

static void	draw_heart_reset(t_cub3d *cub3d, t_img *heart, int heart_width)
{
	t_pos	pos;
	t_img	*hotbar;
	int		color;

	pos.y = -5;
	hotbar = cub3d->hud.hotbar;
	color = 0;
	while (pos.y < heart->height)
	{
		pos.x = 0;
		while (pos.x < heart->width)
		{
			if (pos.y >= 0)
				color = get_texture_color_hud(heart, pos.x, pos.y);
			if (color == 0)
				my_mlx_pixel_put(&cub3d->hud.heart_animation, pos.x
					+ heart_width, pos.y + 5, get_texture_color_hud(&cub3d->img,
						pos.x + (WIDTH / 2) - (hotbar->width / 2) + heart_width,
						pos.y + HEIGHT - hotbar->height - 10 - heart->height));
			else if (color != 0 && pos.y >= 0)
				my_mlx_pixel_put(&cub3d->hud.heart_animation, pos.x
					+ heart_width, pos.y + 5, get_texture_color_hud(heart, pos.x, pos.y));
			pos.x++;
		}
		pos.y++;
	}
}

static void	draw_heart(t_cub3d *cub3d, t_img *heart, int heart_width)
{
	t_pos	pos;
	t_img	*hotbar;
	int		color;

	hotbar = cub3d->hud.hotbar;
	pos.y = 0;
	while (pos.y < heart->height)
	{
		pos.x = 0;
		while (pos.x < heart->width)
		{
			color = get_texture_color_hud(heart, pos.x, pos.y);
			if (color == 0)
				my_mlx_pixel_put(&cub3d->hud.heart_animation, pos.x
					+ heart_width, pos.y, get_texture_color_hud(&cub3d->img,
						pos.x + (WIDTH / 2) - (hotbar->width / 2) + heart_width,
						pos.y + HEIGHT - hotbar->height - 15 - heart->height));
			else if (color != 0 && pos.y >= 0)
				my_mlx_pixel_put(&cub3d->hud.heart_animation, pos.x
					+ heart_width, pos.y, get_texture_color_hud(heart, pos.x, pos.y));
			pos.x++;
		}
		pos.y++;
	}
}

int	animation_hearts(t_cub3d *cub3d)
{
	t_img	*heart;

	heart = cub3d->hud.heart;
	draw_heart(cub3d, heart, cub3d->hud.heart->width * cub3d->hud.heart_index);
	if (cub3d->hud.heart_index != 0)
		draw_heart_reset(cub3d, heart, cub3d->hud.heart->width * (cub3d->hud.heart_index - 1));
	cub3d->hud.heart_index++;
	return (0);
}