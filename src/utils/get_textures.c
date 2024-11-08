/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:15:17 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 16:42:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"

t_img	*set_image(t_cub3d *cub3d, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		exit_on_error(cub3d, ERROR_MALLOC);
	img->img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path, &img->width, &img->height);
	if (!img->img)
		exit_on_error(cub3d, ERROR_TEXTURE);
	return (img);
}

void	load_texture(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (cub3d->texture[i]->path && cub3d->texture[i]->id[0] != 'C' && cub3d->texture[i]->id[0] != 'F') 
			cub3d->texture[i]->img = set_image(cub3d, cub3d->texture[i]->path);
		i++;
	}
}
