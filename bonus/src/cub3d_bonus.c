/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:15:19 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 11:31:17 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "game_engine_bonus.h"

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	if (argc != 2)
		usage();
	init_project(&cub3d, argv);
	game_engine(&cub3d);
	return (EXIT_SUCCESS);
}
