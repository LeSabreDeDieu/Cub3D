/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:54:19 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 15:01:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"
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
			free(map);
			free(line);
			map = tmp;
		}
	}
	return (map);
}

static void	check_empty_line(t_cub3d *cube3d, char *map)
{
	int	i;

	if (!map)
		(free(map), free_exit(cube3d, "Error\nMap not found\n", EXIT_FAILURE));
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			free_exit(cube3d, "Error\nEmpty line in map\n", EXIT_FAILURE);
		}
		i++;
	}
}

static void	is_bordered(t_cub3d *cube3d, int i, int j)
{
	if (ft_isspace(cube3d->map[i - 1][j])
		|| ft_isspace(cube3d->map[i + 1][j])
		|| ft_isspace(cube3d->map[i][j - 1])
		|| ft_isspace(cube3d->map[i][j + 1])
		|| cube3d->map[i - 1][j] == 0 || cube3d->map[i + 1][j] == 0
		|| cube3d->map[i][j - 1] == 0 || cube3d->map[i][j + 1] == 0)
	{
		ft_printf("i = %d, j = %d\n", i, j);
		ft_printf("cube3d->map[i][j] = %%%c%%\n", cube3d->map[i][j]);
		ft_printf("cube3d->map[i][j] = %%%d%%\n", cube3d->map[i][j]);
		ft_printf("cube3d->map[i - 1][j] = %%%c%%\n", cube3d->map[i - 1][j]);
		ft_printf("cube3d->map[i - 1][j] = %%%d%%\n", cube3d->map[i - 1][j]);
		ft_printf("cube3d->map[i + 1][j] = %%%c%%\n", cube3d->map[i + 1][j]);
		ft_printf("cube3d->map[i + 1][j] = %%%d%%\n", cube3d->map[i + 1][j]);
		ft_printf("cube3d->map[i][j - 1] = %%%c%%\n", cube3d->map[i][j - 1]);
		ft_printf("cube3d->map[i][j - 1] = %%%d%%\n", cube3d->map[i][j - 1]);
		ft_printf("cube3d->map[i][j + 1] = %%%c%%\n", cube3d->map[i][j + 1]);
		ft_printf("cube3d->map[i][j + 1] = %%%d%%\n", cube3d->map[i][j + 1]);
		free_exit(cube3d, "Error\nMap not bordered by walls\n", EXIT_FAILURE);
	}
}

static void	check_bordered(t_cub3d *cube3d)
{
	int	i;
	int	j;

	i = 0;
	while (cube3d->map[i])
	{
		j = 0;
		while (cube3d->map[i][j])
		{
			if (cube3d->map[i][j] == '0')
				is_bordered(cube3d, i, j);
			j++;
		}
		i++;
	}
}

void	check_valid_map(t_cub3d *cube3d, int fd)
{
	char	*map_tmp;

	// int		player_pos[2];
	map_tmp = get_map(fd);
	check_empty_line(cube3d, map_tmp);
	cube3d->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	if (!cube3d->map)
		exit_error(FAILURE);
	check_chars(cube3d);
	check_bordered(cube3d);
	// ft_bzero(player_pos, sizeof(int));
	// get_player_pos(cube3d, player_pos);
}
