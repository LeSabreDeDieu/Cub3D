/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gestion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:20:41 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/06 08:27:48 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"

int	on_keypress(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		on_destroy(cub3d);
	if (keycode == XK_w)
		cub3d->key.w = true;
	if (keycode == XK_a)
		cub3d->key.a = true;
	if (keycode == XK_s)
		cub3d->key.s = true;
	if (keycode == XK_d)
		cub3d->key.d = true;
	if (keycode == XK_Left)
		cub3d->key.left = true;
	if (keycode == XK_Right)
		cub3d->key.right = true;
	return (EXIT_SUCCESS);
}

int	on_keyrelease(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_w)
		cub3d->key.w = false;
	if (keycode == XK_a)
		cub3d->key.a = false;
	if (keycode == XK_s)
		cub3d->key.s = false;
	if (keycode == XK_d)
		cub3d->key.d = false;
	if (keycode == XK_Left)
		cub3d->key.left = false;
	if (keycode == XK_Right)
		cub3d->key.right = false;
	return (EXIT_SUCCESS);
}
