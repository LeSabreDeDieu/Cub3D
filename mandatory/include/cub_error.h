/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:39:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/02 09:08:35 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ERROR_H
# define CUB_ERROR_H

// -------------------------- structure section -------------------------- //
typedef struct s_cub3d	t_cub3d;

// -------------------------- enum section -------------------------- //
// enum for the error
enum e_error
{
	ERROR = -1,
	SUCCESS = 0,
	FAILURE = 1
};

// -------------------------- define section -------------------------- //
# define ERROR_MSG "Error\n"
# define ERROR_MLX_PTR "Failed to initialize mlx"
# define ERROR_WIN_PTR "Failed to create window"
# define ERROR_OPENFILE "Failed to open file"
# define ERROR_NOTCUB "File is not a .cub file"
# define ERROR_MALLOC "Failed to allocate memory"
# define ERROR_TEXTURE "Texture is invalid"
# define ERROR_COLOR "Color is invalid"
# define ERROR_ARG "Invalid argument"
# define ERROR_MISS_TEXTURE "Missing texture"
# define ERROR_WRONG_TEXTURE "Wrong texture"
# define ERROR_DOUBLE_TEXTURE "Double texture"
# define ERROR_MAP "Map is invalid"
# define EMPTY_LINE_MAP "Empty line in map"
# define ERROR_MAP_CHAR "Invalid character in map"
# define ERROR_MAP_BORDER "Map is not bordered by walls"
# define ERROR_MAP_PLAYER "Player is invalid"
# define ERROR_MAP_PLAYER_DIR "Player direction is invalid"
# define ERROR_MAP_PLAYER_POS "Player position is invalid"
# define ERROR_MAP_PLAYER_MULTIPLE "Multiple player"
# define ERROR_MAP_PLAYER_NONE "No player"

// -------------------------- error functions -------------------------- //
// ERROR
void				exit_on_error(t_cub3d *cub3d, char *error);
void				usage(void);

// ---------------------------- end of file ---------------------------- //
#endif