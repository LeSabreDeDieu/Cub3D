/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:15:19 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 14:31:09 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub_error.h"
#include <X11/X.h>
#include <fcntl.h>

static void	usage(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;
	char	*str;
	int		fd;

	if (argc != 2)
		usage();
	ft_bzero(&cub3d, sizeof(t_cub3d));
	str = argv[1] + (ft_strlen(argv[1]) - 4);
	if (str && ft_strncmp(str, ".cub", 4) != 0)
		exit_error(NOTCUB);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		free_exit(&cub3d, "Error\nFile not found\n", EXIT_FAILURE);
	get_all_texture(&cub3d, fd);
	check_texture(&cub3d);
	check_valid_map(&cub3d, fd);
	close(fd);
	print(cub3d);
	windows_init(&cub3d);
	mlx_hook(cub3d.win_ptr, KeyPress, KeyPressMask, &on_keypress, &cub3d);
	mlx_hook(cub3d.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&cub3d);
	mlx_loop(cub3d.mlx_ptr);
	return (EXIT_SUCCESS);
}
