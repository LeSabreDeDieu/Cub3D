/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:38:21 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/02 09:08:37 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	windows_init(t_cub3d *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_on_error(data, ERROR_MLX_PTR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!data->win_ptr)
		exit_on_error(data, ERROR_WIN_PTR);
	return (SUCCESS);
}
