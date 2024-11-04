/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:44:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 09:07:50 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_error.h"
#include "libft.h"

void	exit_error(int error)
{
	if (error == NOTCUB)
		ft_putstr_fd("Not a .cub file\n", 2);
	exit(EXIT_FAILURE);
}
