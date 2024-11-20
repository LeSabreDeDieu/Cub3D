/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:14:15 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 14:02:10 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

void	free_texture(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < 6 && cub3d->texture[i])
	{
		if (cub3d->texture[i]->id)
			free(cub3d->texture[i]->id);
		if (cub3d->texture[i]->path)
			free(cub3d->texture[i]->path);
		if (cub3d->texture[i]->img)
		{
			mlx_destroy_image(cub3d->mlx_ptr, cub3d->texture[i]->img->img);
			free(cub3d->texture[i]->img);
		}
		free(cub3d->texture[i]);
		i++;
	}
}

int	on_destroy(t_cub3d *cub3d)
{
	free_texture(cub3d);
	if (cub3d->img.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
	if (cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	if (cub3d->mlx_ptr)
		mlx_destroy_display(cub3d->mlx_ptr);
	free(cub3d->mlx_ptr);
	free_exit(cub3d, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
