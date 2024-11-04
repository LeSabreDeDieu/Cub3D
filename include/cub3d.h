/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:16:05 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/04 09:15:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"

# include <X11/keysym.h>

typedef struct s_cub3d
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_cub3d;

int	windows_init(t_cub3d *cub3d);

// EVENTS
int	on_keypress(int keycode, t_cub3d *cub3d);
int	on_destroy(t_cub3d *cub3d);

#endif