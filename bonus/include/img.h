/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:49:56 by aditer            #+#    #+#             */
/*   Updated: 2024/11/24 08:34:04 by sgabsi           ###   ########.fr       */
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

// get the color of a pixel in the image
int						get_texture_color(t_img *texture, float x_offset,
							float y_offset);

// get the color of the floor and the ceiling
int						get_color_floor_ceilling(t_cub3d *cub3d, int fc);

// set the image
t_img					*set_image(t_cub3d *cub3d, char *path);

// load the texture
void					load_texture(t_cub3d *cub3d);

// ---------------------------- end of file ---------------------------- //
#endif
