/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditer <aditer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:49:56 by aditer            #+#    #+#             */
/*   Updated: 2024/11/05 10:33:52 by aditer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

typedef struct s_cub3d	t_cub3d;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					tile_size;
}						t_img;

void					my_mlx_pixel_put(t_img *data, int x, int y, int color);
void					create_img(t_cub3d *cub3d);
void					draw_map(t_cub3d *cub3d);

#endif