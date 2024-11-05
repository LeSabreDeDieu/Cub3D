/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:12:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/05 15:04:44 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"

int	on_keypress(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		on_destroy(cub3d);
	on_keypress_move(keycode, cub3d);
	on_keypress_rot(keycode, cub3d);
	return (EXIT_SUCCESS);
}

int	on_keypress_move(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_w)
	{
		cub3d->player.pos.x += cub3d->player.d_pos_p.x;
		if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
			+ 4 >= 528)
			cub3d->player.pos.x -= cub3d->player.d_pos_p.x;
		cub3d->player.pos.y += cub3d->player.d_pos_p.y;
		if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
			+ 4 >= 224)
			cub3d->player.pos.y -= cub3d->player.d_pos_p.y;
		draw_map(cub3d);
	}
	if (keycode == XK_s)
	{
		cub3d->player.pos.x -= cub3d->player.d_pos_p.x;
		if (cub3d->player.pos.x * 16 - 4 <= 0 || cub3d->player.pos.x * 16
			+ 4 >= 528)
			cub3d->player.pos.x += cub3d->player.d_pos_p.x;
		cub3d->player.pos.y -= cub3d->player.d_pos_p.y;
		if (cub3d->player.pos.y * 16 - 4 <= 0 || cub3d->player.pos.y * 16
			+ 4 >= 224)
			cub3d->player.pos.y += cub3d->player.d_pos_p.y;
		draw_map(cub3d);
	}
	return (SUCCESS);
}

int	on_keypress_rot(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_a)
	{
		cub3d->player.pa -= 0.1;
		if (cub3d->player.pa < 0)
			cub3d->player.pa += 2 * PI;
		cub3d->player.d_pos_p.x = cos(cub3d->player.pa) * 0.1;
		cub3d->player.d_pos_p.y = sin(cub3d->player.pa) * 0.1;
		draw_map(cub3d);
	}
	if (keycode == XK_d)
	{
		cub3d->player.pa += 0.1;
		if (cub3d->player.pa < 2 * PI)
			cub3d->player.pa -= 2 * PI;
		cub3d->player.d_pos_p.x = cos(cub3d->player.pa) * 0.1;
		cub3d->player.d_pos_p.y = sin(cub3d->player.pa) * 0.1;
		draw_map(cub3d);
	}
	return (SUCCESS);
}

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_exit(t_cub3d *cub3d, char *msg, int status)
{
	int	i;

	i = 0;
	if (msg)
		ft_putstr_fd(msg, 2);
	while (i < 6)
	{
		if (cub3d->texture[i].id)
			free(cub3d->texture[i].id);
		if (cub3d->texture[i].path)
			free(cub3d->texture[i].path);
		i++;
	}
	if (cub3d->map.map)
		free_str_tab(cub3d->map.map);
	exit(status);
}

int	on_destroy(t_cub3d *cub3d)
{
	if (cub3d->img.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
	if (cub3d->win_ptr[0])
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr[0]);
	if (cub3d->win_ptr[1])
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr[1]);
	if (cub3d->mlx_ptr)
		mlx_destroy_display(cub3d->mlx_ptr);
	free(cub3d->mlx_ptr);
	free_exit(cub3d, NULL, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
