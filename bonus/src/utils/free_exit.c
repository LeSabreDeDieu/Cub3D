/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:12:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/02 08:42:46 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_str_tab(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while (tab[i])
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_exit(t_cub3d *cub3d, int status)
{
	if (cub3d->map.map)
		free_str_tab(cub3d->map.map);
	exit(status);
}

void	clean_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
