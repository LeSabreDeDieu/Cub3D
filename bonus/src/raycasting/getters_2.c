/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 08:32:43 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/30 12:11:46 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_color_floor_ceilling(t_cub3d *cub3d, int fc)
{
	int	i;
	int	*colors;

	i = 0;
	colors = NULL;
	while (cub3d->texture[i])
	{
		if (!ft_strcmp(cub3d->texture[i]->id, "F") && fc == 0)
		{
			colors = cub3d->texture[i]->color;
			break ;
		}
		else if (!ft_strcmp(cub3d->texture[i]->id, "C") && fc == 1)
		{
			colors = cub3d->texture[i]->color;
			break ;
		}
		i++;
	}
	return (create_rgb(colors[0], colors[1], colors[2]));
}