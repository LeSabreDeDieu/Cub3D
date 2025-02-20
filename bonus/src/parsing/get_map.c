/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:54:19 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/02 09:27:06 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <fcntl.h>

char	*get_map(int fd)
{
	char	*line;
	char	*tmp;
	char	*map;

	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!map)
			map = line;
		else
		{
			tmp = ft_strjoin(map, line);
			if (!tmp)
				return (free(map), free(line), NULL);
			free(map);
			free(line);
			map = tmp;
		}
	}
	close(fd);
	return (map);
}

static void	check_empty_line(t_cub3d *cube3d, char *map_copy, char *map)
{
	int	i;

	if (!map_copy)
		(free(map), exit_on_error(cube3d, ERROR_MAP));
	i = 0;
	while (map_copy[i])
	{
		if (map_copy[i] == '\n' && map_copy[i + 1] == '\n')
		{
			free(map);
			exit_on_error(cube3d, EMPTY_LINE_MAP);
		}
		i++;
	}
}

static void	is_bordered(t_cub3d *cube3d, int i, int j)
{
	if (i == 0 || j == 0)
		exit_on_error(cube3d, ERROR_MAP_BORDER);
	if (cube3d->map.map[i + 1] == NULL || cube3d->map.map[i - 1] == NULL
		|| cube3d->map.map[i][j + 1] == 0 || cube3d->map.map[i][j - 1] == 0)
	{
		exit_on_error(cube3d, ERROR_MAP_BORDER);
	}
	if (ft_isspace(cube3d->map.map[i - 1][j]) || ft_isspace(cube3d->map.map[i
			+ 1][j]) || ft_isspace(cube3d->map.map[i][j - 1])
		|| ft_isspace(cube3d->map.map[i][j + 1]) || cube3d->map.map[i
		- 1][j] == 0 || cube3d->map.map[i + 1][j] == 0 || cube3d->map.map[i][j
		- 1] == 0 || cube3d->map.map[i][j + 1] == 0)
	{
		exit_on_error(cube3d, ERROR_MAP_BORDER);
	}
}

static void	check_bordered(t_cub3d *cube3d)
{
	size_t	max;
	int		i;
	int		j;

	i = 0;
	max = 0;
	while (cube3d->map.map[i])
	{
		j = 0;
		while (cube3d->map.map[i][j])
		{
			if (cube3d->map.map[i][j] == '0' || cube3d->map.map[i][j] == 'N'
				|| cube3d->map.map[i][j] == 'S' || cube3d->map.map[i][j] == 'W'
				|| cube3d->map.map[i][j] == 'E')
				is_bordered(cube3d, i, j);
			if (ft_strlen(cube3d->map.map[i]) > max)
				max = ft_strlen(cube3d->map.map[i]);
			j++;
		}
		i++;
	}
	cube3d->map.height = i;
	cube3d->map.width = max;
}

void	get_check_valid_map(t_cub3d *cube3d, int fd)
{
	char	*map_tmp;
	char	*map_tmp_copy;

	map_tmp = get_map(fd);
	if (!map_tmp)
		exit_on_error(cube3d, ERROR_MAP);
	map_tmp_copy = map_tmp;
	skip_spaces(&map_tmp_copy);
	check_chars(cube3d, map_tmp, map_tmp_copy);
	check_empty_line(cube3d, map_tmp_copy, map_tmp);
	cube3d->map.map = ft_split(map_tmp_copy, '\n');
	free(map_tmp);
	if (!cube3d->map.map)
		exit_on_error(cube3d, ERROR_MAP);
	check_bordered(cube3d);
	get_player_pos(cube3d);
}
