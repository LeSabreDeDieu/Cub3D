/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:36:42 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 15:06:48 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine_bonus.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long	gettimeofday_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

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

static void	display_fps(t_cub3d *cub3d)
{
	static long	last_update_time = 0;
	static int	frame_count = 0;
	static int	current_fps = 0;
	long		current_time;
	char		fps_text[32];

	current_time = gettimeofday_ms();
	frame_count++;
	if (current_time - last_update_time >= 1000)
	{
		current_fps = frame_count;
		frame_count = 0;
		last_update_time = current_time;
	}
	sprintf(fps_text, "FPS: %d", current_fps);
	mlx_string_put(cub3d->mlx_ptr, cub3d->win_ptr, 10, 10, 0xFFFFFF, fps_text);
}

void	render_frame(t_cub3d *cub3d)
{
	mlx_clear_window(cub3d->mlx_ptr, cub3d->win_ptr);
	key_update(cub3d);
	raycast(cub3d);
	draw_minimap(cub3d);
	draw_hotbar(cub3d);
	draw_hearts(cub3d);
	animation_hearts(cub3d);
	if (cub3d->hud.heart_index == 10)
	{
		cub3d->hud.heart_index = 0;
		cub3d->animation = 0;
	}
	usleep(23000);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, cub3d->img.img, 0,
		0);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
		cub3d->hud.heart_animation.img, (WIDTH / 2)
		- (cub3d->hud.hotbar->width / 2), HEIGHT
		- (cub3d->hud.hotbar->height + cub3d->hud.heart->height + 15));
	cub3d->nb_frame = 0;
	display_fps(cub3d);
}

int	update(t_cub3d *cub3d)
{
	if (cub3d->nb_frame >= FRAME_TIME)
		render_frame(cub3d);
	if (!cub3d->key.altl)
		mouse_rot(cub3d);
	cub3d->nb_frame++;
	return (EXIT_SUCCESS);
}
