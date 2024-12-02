/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:44:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/29 15:49:31 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	usage(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	ft_putstr_fd("Usage: ./cub3D <map.cub>\n", 2);
	exit(EXIT_FAILURE);
}

static void	print_error(char *error)
{
	printf("Error\n%s\n", error);
}

void	exit_on_error(t_cub3d *cub3d, char *error)
{
	print_error(error);
	on_destroy(cub3d);
}
