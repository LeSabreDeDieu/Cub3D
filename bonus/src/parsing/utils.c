/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:46:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/20 16:54:29 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen_not_whitespace(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	return (i);
}

static void	verif_nb_chars(t_cub3d *data, int count_player)
{
	if (count_player < 1)
		exit_on_error(data, ERROR_MAP_PLAYER_NONE);
	if (count_player > 1)
		exit_on_error(data, ERROR_MAP_PLAYER_MULTIPLE);
}

static void	char_counter(char *map, int *count_player, int i)
{
	if (map[i] == 'N' || map[i] == 'S' || map[i] == 'E' || map[i] == 'W')
		(*count_player)++;
}

static void	is_in_list(t_cub3d *data, char c, char *chars, char *map_orig)
{

	if (ft_strchr(chars, c) == NULL)
	{
		free(map_orig);
		exit_on_error(data, ERROR_MAP_CHAR);
	}
}

void	check_chars(t_cub3d *data, char *map_orig, char *map_copy)
{
	int		i;
	char	*chars;
	int		count_player;

	i = 0;
	count_player = 0;
	chars = "01NSEW \t\n\v\f\r";
	while (map_copy[i])
	{
		is_in_list(data, map_copy[i], chars, map_orig);
		char_counter(map_copy, &count_player, i);
		i++;
	}
	verif_nb_chars(data, count_player);
}
