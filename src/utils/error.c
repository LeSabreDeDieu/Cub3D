/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:44:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 14:20:24 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error)
{
	printf("Error\n%s\n", error);
}

void	exit_on_error(t_cub3d *cub3d, char *error)
{
	print_error(error);
	on_destroy(cub3d);
}
