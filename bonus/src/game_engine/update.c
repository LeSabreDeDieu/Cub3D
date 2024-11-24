/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:36:42 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/24 09:16:58 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_engine.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

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

void render_frame(t_cub3d *cub3d)
{
    mlx_clear_window(cub3d->mlx_ptr, cub3d->win_ptr);
    key_update(cub3d);
    raycast(cub3d);
	draw_minimap(cub3d);
    mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, cub3d->img.img, 0, 0);
    display_fps(cub3d);
}

int update(t_cub3d *cub3d)
{
    long current_time;
    long time_since_last_frame;

    current_time = gettimeofday_ms();
    time_since_last_frame = current_time - cub3d->last_frame_time;
    if (time_since_last_frame < (1000 / FPS))
        usleep(((1000 / FPS) - time_since_last_frame) * 1000);
    if (!cub3d->key.altl)
        mouse_rot(cub3d);
    render_frame(cub3d);
    cub3d->last_frame_time = gettimeofday_ms();
    return (EXIT_SUCCESS);
}

