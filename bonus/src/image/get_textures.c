/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:15:17 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 10:50:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_img	*set_image(t_cub3d *cub3d, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		exit_on_error(cub3d, ERROR_MALLOC);
	img->img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&img->width, &img->height);
	if (!img->img)
	{
		free(img);
		exit_on_error(cub3d, ERROR_TEXTURE);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

void	load_texture(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cub3d->texture[i]->path && cub3d->texture[i]->id[0] != 'C'
			&& cub3d->texture[i]->id[0] != 'F')
			cub3d->texture[i]->img = set_image(cub3d, cub3d->texture[i]->path);
		else
			cub3d->texture[i]->img = NULL;
		i++;
	}
	cub3d->hud.hotbar = set_image(cub3d, "./ressources/hud/Hotbar.xpm");
	if (!cub3d->hud.hotbar)
		exit_on_error(cub3d, ERROR_TEXTURE);
	cub3d->hud.heart = set_image(cub3d, "./ressources/hud/heart.xpm");
	if (!cub3d->hud.heart)
		exit_on_error(cub3d, ERROR_TEXTURE);
}
