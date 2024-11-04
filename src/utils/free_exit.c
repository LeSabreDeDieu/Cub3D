/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:12:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 14:48:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_keypress(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		on_destroy(cub3d);
	return (EXIT_SUCCESS);
}

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_exit(t_cub3d *cub3d, char *msg, int status)
{
	int	i;

	i = 0;
	if (msg)
		ft_putstr_fd(msg, 2);
	while (i < 6)
	{
		if (cub3d->texture[i].id)
			free(cub3d->texture[i].id);
		if (cub3d->texture[i].path)
			free(cub3d->texture[i].path);
		i++;
	}
	if (cub3d->map)
		free_str_tab(cub3d->map);
	exit(status);
}

int	on_destroy(t_cub3d *cub3d)
{
	if (cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	if (cub3d->mlx_ptr)
		mlx_destroy_display(cub3d->mlx_ptr);
	free(cub3d->mlx_ptr);
	free_exit(cub3d, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
