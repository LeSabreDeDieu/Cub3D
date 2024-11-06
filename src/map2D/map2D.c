/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:35:30 by aditer            #+#    #+#             */
/*   Updated: 2024/11/06 12:45:39 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put_2d(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 528 || y < 0 || y >= 224)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_3d(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_img_2d(t_cub3d *cub3d, t_img *img)
{
	int	height;
	int	width;
	int	i;

	i = 0;
	mlx_get_screen_size(cub3d->mlx_ptr, &width, &height);
	img->img = mlx_new_image(cub3d->mlx_ptr, width / 2, height / 2);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	create_img_3d(t_cub3d *cub3d, t_img *img)
{
	int	height;
	int	width;
	int	i;

	i = 0;
	mlx_get_screen_size(cub3d->mlx_ptr, &width, &height);
	img->img = mlx_new_image(cub3d->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	set_tile(t_cub3d *cub3d, int x, int y, int color)
{
	int	i;
	int	j;
	int	height;
	int	width;

	mlx_get_screen_size(cub3d->mlx_ptr, &width, &height);
	i = 1;
	while (i < 15)
	{
		j = 1;
		while (j < 15)
		{
			my_mlx_pixel_put_2d(&cub3d->img_2d, (x + j), (y + i), color);
			j++;
		}
		i++;
	}
}

void	set_tile_player(t_cub3d *cub3d, int color)
{
	int	i;
	int	j;
	int	height;
	int	width;

	mlx_get_screen_size(cub3d->mlx_ptr, &width, &height);
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put_2d(&cub3d->img_2d, ((cub3d->player.pos.x * 16 - 4)
					+ j), ((cub3d->player.pos.y * 16 - 4) + i), color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_cub3d *cub3d)
{
	int	i;
	int	j;

	i = 0;
	while (i < 528)
	{
		j = 0;
		while (j < 224)
		{
			my_mlx_pixel_put_2d(&cub3d->img_2d, i, j, 0x00000000);
			j++;
		}
		i++;
	}
	i = 0;
	while (cub3d->map.map[i])
	{
		j = 0;
		while (cub3d->map.map[i][j])
		{
			if (cub3d->map.map[i][j] == '1')
				set_tile(cub3d, j * 16, i * 16, 0x001D3091);
			else if (cub3d->map.map[i][j] == '0')
				set_tile(cub3d, j * 16, i * 16, 0x00454343);
			else if (cub3d->map.map[i][j] == 'N' || cub3d->map.map[i][j] == 'S'
				|| cub3d->map.map[i][j] == 'W' || cub3d->map.map[i][j] == 'E')
				set_tile(cub3d, j * 16, i * 16, 0x00454343);
			j++;
		}
		i++;
	}
	i = 0;
	while (cub3d->map.map[i])
	{
		j = 0;
		while (cub3d->map.map[i][j])
		{
			if (cub3d->map.map[i][j] == 'N' || cub3d->map.map[i][j] == 'S'
				|| cub3d->map.map[i][j] == 'W' || cub3d->map.map[i][j] == 'E')
			{
				set_tile_player(cub3d, 0x00FF0000);
				draw_line(cub3d);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr[1],
		cub3d->img_2d.img, 0, 0);
}
