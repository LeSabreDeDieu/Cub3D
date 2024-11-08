/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:37:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 11:14:45 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx_ptr, cub3d->img_3d.img);
	create_img_3d(cub3d, &cub3d->img_3d);
	if (cub3d->key.left)
		camera_rot_left(cub3d);
	if (cub3d->key.right)
		camera_rot_right(cub3d);
	if (cub3d->key.w)
		player_move_forward(cub3d);
	if (cub3d->key.s)
		player_move_backward(cub3d);
	if (cub3d->key.a)
		player_move_left(cub3d);
	if (cub3d->key.d)
		player_move_right(cub3d);
	raycast(cub3d);
	return (EXIT_SUCCESS);
}
