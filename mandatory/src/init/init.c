/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:09:47 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 14:52:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

void	init_project(t_cub3d *cub3d, char *argv[])
{
	char	*str;
	int		fd;

	ft_bzero(cub3d, sizeof(t_cub3d));
	str = argv[1] + (ft_strlen(argv[1]) - 4);
	if (str && ft_strncmp(str, ".cub", 4) != 0)
		exit_on_error(cub3d, ERROR_NOTCUB, -1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_on_error(cub3d, ERROR_OPENFILE, fd);
	get_all_texture(cub3d, fd);
	check_texture(cub3d, fd);
	get_check_valid_map(cub3d, fd);
	windows_init(cub3d);
	load_texture(cub3d);
	create_img(cub3d, &cub3d->img);
}
