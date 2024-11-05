/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:39:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 14:00:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ERROR_H
# define CUB_ERROR_H

enum	e_errors
{
	FAILURE = -1,
	SUCCESS,
	NOTCUB,
	FILENOTFOUND
};

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

# define ERROR_MSG "Error\n"

void	exit_error(int error);

#endif