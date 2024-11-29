/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:20:41 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 11:27:51 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	keyboard_press(int keycode, t_cub3d *cub3d)
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
	if (keycode == XK_Alt_L)
	{
		cub3d->key.altl = true;
		//mlx_mouse_show(cub3d->mlx_ptr, cub3d->win_ptr);
	}
}

int	on_keypress(int keycode, t_cub3d *cub3d)
{
	keyboard_press(keycode, cub3d);
	return (EXIT_SUCCESS);
}

static void	keyboard_release(int keycode, t_cub3d *cub3d)
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
	if (keycode == XK_Alt_L)
	{
		cub3d->key.altl = false;
		//mlx_mouse_hide(cub3d->mlx_ptr, cub3d->win_ptr);
	}
}

int	on_keyrelease(int keycode, t_cub3d *cub3d)
{
	keyboard_release(keycode, cub3d);
	return (EXIT_SUCCESS);
}
