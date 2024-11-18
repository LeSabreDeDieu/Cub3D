/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:06:30 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/18 11:25:20 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_H
# define GAME_ENGINE_H

// -------------------------- include section -------------------------- //
# include "cub3d.h"
# include <X11/X.h>

// -------------------------- function section -------------------------- //

// THE GAME ENGINE
void	game_engine(t_cub3d *cub3d);

//KEY GESTION
int		on_keypress(int keycode, t_cub3d *cub3d);
int		on_keyrelease(int keycode, t_cub3d *cub3d);

// UPDATE
int		update(t_cub3d *cub3d);

// ---------------------------- end of file ---------------------------- //
#endif