/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:24:23 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 10:11:25 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_angle_start(t_cub3d *data, int i, int j)
{
	if (data->map.map[i][j] == 'N')
		data->player.pa = 3 * PI / 2;
	else if (data->map.map[i][j] == 'S')
		data->player.pa = PI / 2;
	else if (data->map.map[i][j] == 'E')
		data->player.pa = 0;
	else if (data->map.map[i][j] == 'W')
		data->player.pa = PI;
}

void	get_player_pos(t_cub3d *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				data->player.pos.x = (j * TILE_SIZE) + TILE_SIZE / 2;
				data->player.pos.y = (i * TILE_SIZE) + TILE_SIZE / 2;
				data->player.fov_rd = (float)FOV * (PI / 180);
				init_angle_start(data, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
