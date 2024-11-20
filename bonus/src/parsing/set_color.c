/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:51:26 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 15:59:01 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	set_color(t_texture_map *texture, char **split, int j)
{
	int	color;

	color = ft_atoi(split[j]);
	if (color < 0 || color > 255)
		return (FAILURE);
	texture->color[j] = color;
	return (SUCCESS);
}
