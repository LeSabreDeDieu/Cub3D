/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:12:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 17:00:58 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_texture(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < 6)
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

void	free_exit(t_cub3d *cub3d, int status)
{
	if (cub3d->map.map)
		free_str_tab(cub3d->map.map);
	exit(status);
}

int	on_destroy(t_cub3d *cub3d)
{
	free_texture(cub3d);
	if (cub3d->img_2d.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img_2d.img);
	if (cub3d->img_3d.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img_3d.img);
	if (cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	if (cub3d->mlx_ptr)
		mlx_destroy_display(cub3d->mlx_ptr);
	free(cub3d->mlx_ptr);
	free_exit(cub3d, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
