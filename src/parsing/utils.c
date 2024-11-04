/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:46:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 15:09:16 by sgabsi           ###   ########.fr       */
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
		free_exit(data, "Error\nMissing player\n", EXIT_FAILURE);
	if (count_player > 1)
		free_exit(data, "Error\nToo many player\n", EXIT_FAILURE);
}

static void	char_counter(t_cub3d *data, int *count_player, int i, int j)
{
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
		(*count_player)++;
}

static void	is_in_list(t_cub3d *data, char *chars, int i, int j)
{
	if (ft_strchr(chars, data->map[i][j]) == NULL)
		free_exit(data, "Error\nInvalid character in map\n", EXIT_FAILURE);
}

void	check_chars(t_cub3d *data)
{
	int		i;
	int		j;
	char	*chars;
	int		count_player;

	i = 0;
	count_player = 0;
	chars = "01NSEW \t\n\v\f\r";
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			is_in_list(data, chars, i, j);
			char_counter(data, &count_player, i, j);
			j++;
		}
		i++;
	}
	verif_nb_chars(data, count_player);
}
