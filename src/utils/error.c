/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:44:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 14:53:45 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error(char *error)
{
	printf("Error\n%s\n", error);
}

void	usage(void)
{
	print_error("Usage: ./cub3D <map.cub>\n");
	exit(EXIT_FAILURE);
}

void	exit_on_error(t_cub3d *cub3d, char *error, int fd)
{
	char	*line;

	if (fd >= 0)
	{
		line = get_next_line(fd);
		while(line)	
		{
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	print_error(error);
	on_destroy(cub3d);
}
