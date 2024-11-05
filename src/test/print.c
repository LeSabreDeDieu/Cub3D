/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:35:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/05 10:38:31 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print(t_cub3d cub3d)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!(ft_strncmp(cub3d.texture[i].id, "F", 1) == 0
				|| ft_strncmp(cub3d.texture[i].id, "C", 1) == 0))
			printf("%s\t:\t%s\n", cub3d.texture[i].id, cub3d.texture[i].path);
		else
		{
			printf("%s\t:\t%d, %d, %d\n", cub3d.texture[i].id,
				cub3d.texture[i].color[0], cub3d.texture[i].color[1],
				cub3d.texture[i].color[2]);
		}
		i++;
	}
	print_map(cub3d.map.map);
}
