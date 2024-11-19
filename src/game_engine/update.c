/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:37:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 18:58:11 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"

static void	key_update(t_cub3d *cub3d)
{
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
}

int	update(t_cub3d *cub3d)
{
	if (cub3d->nb_frame >= FRAME_TIME)
	{
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
		create_img(cub3d, &cub3d->img);
		key_update(cub3d);
		raycast(cub3d);
		mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
			cub3d->img.img, 0, 0);
		cub3d->nb_frame = 0;
	}
	cub3d->nb_frame++;
	return (EXIT_SUCCESS);
}
