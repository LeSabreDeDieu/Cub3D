/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:38:21 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 11:26:14 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"

int	windows_init(t_cub3d *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), FAILURE);
	return (SUCCESS);
}
