/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:16:05 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/05 15:04:53 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "img.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

# define HEIGHT 1080
# define WIDTH 1080

# define PI 3.14159265359

typedef struct s_pos
{
	float			x;
	float			y;
}					t_pos;

typedef struct s_player
{
	t_pos			pos;
	t_pos			d_pos_p;
	float			pa;
}					t_player;

typedef struct s_texture_map
{
	char			*id;
	char			*path;
	int				color[3];
}					t_texture_map;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr[2];
	t_texture_map	texture[6];
	t_map			map;
	t_img			img;
	t_player		player;
}					t_cub3d;

int					windows_init(t_cub3d *cub3d);

// PARSING
void				check_texture(t_cub3d *cub3d);
void				get_all_texture(t_cub3d *cub3d, int fd);
void				get_check_valid_map(t_cub3d *cube3d, int fd);
int					set_color(t_texture_map *texture, char **split, int j);

// EVENTS
int					on_destroy(t_cub3d *cub3d);
int					on_keypress(int keycode, t_cub3d *cub3d);
int					on_keypress_exit(int keycode, t_cub3d *cub3d);
int					on_keypress_move(int keycode, t_cub3d *cub3d);
int					on_keypress_rot(int keycode, t_cub3d *cub3d);


// UTILS
size_t				ft_strlen_not_whitespace(const char *s);
void				free_str_tab(char **tab);
void				free_exit(t_cub3d *cub3d, char *msg, int status);
void				check_chars(t_cub3d *data);
void				get_player_pos(t_cub3d *data);
void				draw_line(t_cub3d *cub3d);

void				print(t_cub3d cub3d);

// free
void				free_str_tab(char **tab);

#endif