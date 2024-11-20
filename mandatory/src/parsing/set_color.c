/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:26 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 11:13:25 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_color(t_texture_map *texture, char **split, int j)
{
	int	color;

	color = ft_atoi(split[j]);
	if (color < 0 || color > 255)
		return (FAILURE);
	texture->color[j] = color;
	return (SUCCESS);
}
