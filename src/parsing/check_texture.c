/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:26:21 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 14:53:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_right_name(t_texture_map *texture[6])
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(texture[i]->id, "NO", 2) != 0
			&& ft_strncmp(texture[i]->id, "SO", 2) != 0
			&& ft_strncmp(texture[i]->id, "WE", 2) != 0
			&& ft_strncmp(texture[i]->id, "EA", 2) != 0
			&& ft_strncmp(texture[i]->id, "F", 1) != 0
			&& ft_strncmp(texture[i]->id, "C", 1) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	is_in_double(t_texture_map *texture[6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = i + 1;
		while (j < 6)
		{
			if (ft_strncmp(texture[i]->id, texture[j]->id, 2) == 0)
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_color(t_texture_map *texture[6], int i)
{
	char	**split;
	char	*str_tmp;
	int		j;
	int		k;

	split = ft_split(texture[i]->path, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (free_str_tab(split), FAILURE);
	j = -1;
	while (++j < 3)
	{
		k = 0;
		str_tmp = ft_strtrim(split[j], " \t\n\v\f\r");
		if (!str_tmp)
			return (free_str_tab(split), FAILURE);
		while (str_tmp[k] && ft_isdigit(str_tmp[k]))
			k++;
		if (str_tmp[k] != '\0')
			return (free(str_tmp), free_str_tab(split), FAILURE);
		if (set_color(texture[i], split, j) == FAILURE)
			return (free(str_tmp), free_str_tab(split), FAILURE);
		free(str_tmp);
	}
	return (free_str_tab(split), SUCCESS);
}

int	color_is_valid(t_texture_map *texture[6])
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (ft_strncmp(texture[i]->id, "F", 1) == 0
			|| ft_strncmp(texture[i]->id, "C", 1) == 0)
		{
			if (check_color(texture, i) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

void	check_texture(t_cub3d *cub3d, int fd)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!cub3d->texture[i]->id || !cub3d->texture[i]->path)
			exit_on_error(cub3d, ERROR_MISS_TEXTURE, fd);
		i++;
	}
	if (is_right_name(cub3d->texture) == FAILURE)
		exit_on_error(cub3d, ERROR_WRONG_TEXTURE, fd);
	if (is_in_double(cub3d->texture) == FAILURE)
		exit_on_error(cub3d, ERROR_DOUBLE_TEXTURE, fd);
	if (color_is_valid(cub3d->texture) == FAILURE)
		exit_on_error(cub3d, ERROR_COLOR, fd);
}
