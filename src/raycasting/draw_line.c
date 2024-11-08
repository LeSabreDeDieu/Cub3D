/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 11:25:55 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int wall_hit(t_cub3d *cub3d, float x, float y)
{
    int x_m;
    int y_m;

    if (x < 0 || y < 0 || x >= cub3d->map.width * TILE_SIZE || y >= cub3d->map.height * TILE_SIZE)
        return (0);
    x_m = floor(x / TILE_SIZE);
    y_m = floor(y / TILE_SIZE);
    if (cub3d->map.map[y_m] && x_m < (int)ft_strlen(cub3d->map.map[y_m]))
    {
        if (cub3d->map.map[y_m][x_m] == '1')
            return (0);
    }
    return (1);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);
	}
	return (0);
}

float get_h_inter(t_cub3d *cub3d, float angle)
{
    float h_x, h_y, x_step, y_step;
    int pixel;

    y_step = TILE_SIZE;
    x_step = TILE_SIZE / tan(angle);
    h_y = floor(cub3d->player.pos.y / TILE_SIZE) * TILE_SIZE;
    pixel = inter_check(angle, &h_y, &y_step, 1);
    h_x = cub3d->player.pos.x + (h_y - cub3d->player.pos.y) / tan(angle);
    if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
    while (wall_hit(cub3d, h_x, h_y - pixel))
    {
        h_x += x_step;
        h_y += y_step;
    }
    return (sqrt(pow(h_x - cub3d->player.pos.x, 2) + pow(h_y - cub3d->player.pos.y, 2)));
}

float get_v_inter(t_cub3d *cub3d, float angle)
{
    float v_x, v_y, x_step, y_step;
    int pixel;

    x_step = TILE_SIZE;
    y_step = TILE_SIZE * tan(angle);
    v_x = floor(cub3d->player.pos.x / TILE_SIZE) * TILE_SIZE;
     if (!(angle > PI / 2 && angle < 3 * PI / 2))
    {
        v_x += TILE_SIZE;
        pixel = -1;
    }
    else
    {
        x_step *= -1;
        pixel = 1;
    }
    v_y = cub3d->player.pos.y + (v_x - cub3d->player.pos.x) * tan(angle);
    if (((angle > 0 && angle < PI) && y_step < 0) || (!(angle < PI || angle > 2 * PI) && y_step > 0))
        y_step *= -1;
    while (wall_hit(cub3d, v_x - pixel, v_y))
    {
        v_x += x_step;
        v_y += y_step;
    }
    return (sqrt(pow(v_x - cub3d->player.pos.x, 2) + pow(v_y - cub3d->player.pos.y, 2)));
}

float norm_angle(float angle)
{
    if (angle < 0)
        angle += 2 * PI;
    if (angle > 2 * PI)
        angle -= 2 * PI;
    return (angle);
}

void draw_floor(t_cub3d *cub3d, int ray, int b_pix)
{
    int i = b_pix;
    while (i < HEIGHT)
        my_mlx_pixel_put_3d(&cub3d->img_3d, ray, i++, 0xB99470FF);
}

void draw_ceiling(t_cub3d *cub3d, int ray, int t_pix)
{
    int i = 0;
    while (i < t_pix)
        my_mlx_pixel_put_3d(&cub3d->img_3d, ray, i++, 0x87CEEBFF);
}

int get_color(t_cub3d *cub3d, int wall)
{
    cub3d->ray.angle = norm_angle(cub3d->ray.angle);
    if (wall == VERTICAL)
    {
        if (cub3d->ray.angle > PI / 2 && cub3d->ray.angle < 3 * (PI / 2))
            return (0xB5B5B5FF);
        else
            return (0xB5B5B5FF);
    }
    else if (wall == HORIZONTAL)
    {
        if (cub3d->ray.angle > 0 && cub3d->ray.angle < PI)
            return (0xF5F5F5FF);
        else
            return (0xF5F5F5FF);
    }
    return (0);
}

void draw_wall(t_cub3d *cub3d, int ray, double top_pixel, double bottom_pixel)
{
    int color = get_color(cub3d, cub3d->ray.wall);
    while (top_pixel < bottom_pixel)
        my_mlx_pixel_put_3d(&cub3d->img_3d, ray, top_pixel++, color);
}

void render_wall(t_cub3d *cub3d, int ray)
{
    double wall_height;
    double top_pixel;
    double bottom_pixel;

    cub3d->ray.dist *= cos(norm_angle(cub3d->ray.angle - cub3d->player.pa));
    wall_height = (TILE_SIZE / cub3d->ray.dist) * ((WIDTH / 2) / tan(cub3d->player.fov_rd / 2));
    top_pixel = (HEIGHT / 2) - (wall_height / 2);
    bottom_pixel = (HEIGHT / 2) + (wall_height / 2);
    if (bottom_pixel > HEIGHT)
        bottom_pixel = HEIGHT;
    if (top_pixel < 0)
        top_pixel = 0;
    draw_wall(cub3d, ray, top_pixel, bottom_pixel);
    draw_floor(cub3d, ray, bottom_pixel);
    draw_ceiling(cub3d, ray, top_pixel);
}

void raycast(t_cub3d *cub3d)
{
    double h_inter;
    double v_inter;
    int ray = 0;

    cub3d->ray.angle = cub3d->player.pa - (cub3d->player.fov_rd / 2);
    while (ray < WIDTH)
    {
        h_inter = get_h_inter(cub3d, norm_angle(cub3d->ray.angle));
        v_inter = get_v_inter(cub3d, norm_angle(cub3d->ray.angle));
        if (h_inter < v_inter)
        {
            cub3d->ray.dist = h_inter;
            cub3d->ray.wall = HORIZONTAL;
        }
        else
        {
            cub3d->ray.dist = v_inter;
            cub3d->ray.wall = VERTICAL;
        }
        render_wall(cub3d, ray);
        ray++;
        cub3d->ray.angle += cub3d->player.fov_rd / WIDTH;
    }
    mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr, cub3d->img_3d.img, 0, 0);
}
