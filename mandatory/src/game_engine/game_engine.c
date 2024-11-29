/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:05:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 11:06:44 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

void	game_engine(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win_ptr, KeyPress, KeyPressMask, &on_keypress, cub3d);
	mlx_hook(cub3d->win_ptr, KeyRelease, KeyReleaseMask, &on_keyrelease,
		cub3d);
	mlx_hook(cub3d->win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, &update, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}
