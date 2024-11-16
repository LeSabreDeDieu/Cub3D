/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:49:56 by aditer            #+#    #+#             */
/*   Updated: 2024/11/16 13:23:18 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

// -------------------------- define section -------------------------- //
typedef struct s_cub3d	t_cub3d;

// ---------------------------- image struct ---------------------------- //
typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					tile_size;
	int					width;
	int					height;
}						t_img;

// -------------------------- image functions -------------------------- //
// create a new image
void					create_img(t_cub3d *cub3d, t_img *img);

// put a pixel in the image
void					my_mlx_pixel_put(t_img *img, int x, int y, int color);

// ---------------------------- end of file ---------------------------- //
#endif
