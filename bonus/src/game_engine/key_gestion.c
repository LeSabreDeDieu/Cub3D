/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:20:41 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 17:26:03 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	on_keypress(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		on_destroy(cub3d);
	if (keycode == XK_w || keycode == XK_Up)
		cub3d->key.w = true;
	if (keycode == XK_s || keycode == XK_Down)
		cub3d->key.s = true;
	if (keycode == XK_a)
		cub3d->key.a = true;
	if (keycode == XK_d)
		cub3d->key.d = true;
	if (keycode == XK_Left)
		cub3d->key.left = true;
	if (keycode == XK_Right)
		cub3d->key.right = true;
	if ((keycode == XK_Shift_L || keycode == XK_Shift_R) && !cub3d->key.ctrl)
		cub3d->key.shift = true;
	if ((keycode == XK_Control_L || keycode == XK_Control_R)
		&& !cub3d->key.shift)
		cub3d->key.ctrl = true;
	return (EXIT_SUCCESS);
}

int	on_keyrelease(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_w || keycode == XK_Up)
		cub3d->key.w = false;
	if (keycode == XK_s || keycode == XK_Down)
		cub3d->key.s = false;
	if (keycode == XK_a)
		cub3d->key.a = false;
	if (keycode == XK_d)
		cub3d->key.d = false;
	if (keycode == XK_Left)
		cub3d->key.left = false;
	if (keycode == XK_Right)
		cub3d->key.right = false;
	if (keycode == XK_Shift_L || keycode == XK_Shift_R)
		cub3d->key.shift = false;
	if (keycode == XK_Control_L || keycode == XK_Control_R)
		cub3d->key.ctrl = false;
	return (EXIT_SUCCESS);
}
