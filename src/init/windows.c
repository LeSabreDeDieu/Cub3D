/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:38:21 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 08:55:03 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"

int	windows_init(t_cub3d *data)
{
	int	width;
	int	height;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (FAILURE);
	mlx_get_screen_size(data->mlx_ptr, &width, &height);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "cub3d");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), FAILURE);
	return (SUCCESS);
}
