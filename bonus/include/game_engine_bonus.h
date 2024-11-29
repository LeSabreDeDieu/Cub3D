/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:06:30 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/24 07:39:44 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_BONUS_H
# define GAME_ENGINE_BONUS_H

// -------------------------- include section -------------------------- //
# include "cub3d_bonus.h"
# include <X11/X.h>

// -------------------------- struct section -------------------------- //
typedef struct s_cub3d	t_cub3d;

// -------------------------- function section -------------------------- //

// THE GAME ENGINE
void	game_engine(t_cub3d *cub3d);

//KEY GESTION
int		on_keypress(int keycode, t_cub3d *cub3d);
int		on_keyrelease(int keycode, t_cub3d *cub3d);

// UPDATE
int		update(t_cub3d *cub3d);

//FREES
void	free_texture(t_cub3d *cub3d);
int		on_destroy(t_cub3d *cub3d);

// ---------------------------- end of file ---------------------------- //
#endif