/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:16:05 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/08 15:27:35 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "img.h"
# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define HEIGHT 1080
# define WIDTH 1920

# define PI 3.14159265359

# define FOV 60
# define TILE_SIZE 64
# define MOVE_SPEED 12
# define ROT_SPEED 0.1

enum				e_wall
{
	NONE,
	VERTICAL,
	HORIZONTAL
};

enum				e_texture
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	FLOOR,
	CEILING
};

typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct s_player
{
	t_pos			pos;
	t_pos			d_pos_p;
	t_pos			d_pos_l;
	t_pos			d_pos_r;
	t_pos			move;
	float			pa;
	float			fov_rd;
}					t_player;

typedef struct s_ray
{
	float			angle;
	float			dist;
	int				wall;
}					t_ray;

typedef struct s_texture_map
{
	char			*id;
	char			*path;
	t_img			*img;
	int				color[3];
}					t_texture_map;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_key
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			left;
	bool			right;
}					t_key;

typedef struct s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_texture_map	*texture[6];
	t_map			map;
	t_img			img_2d;
	t_img			img_3d;
	t_player		player;
	t_key			key;
	t_ray			ray;
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
int					on_keyrelease(int keycode, t_cub3d *cub3d);

// UTILS
size_t				ft_strlen_not_whitespace(const char *s);
void				free_str_tab(char **tab);
void				check_chars(t_cub3d *data);
void				get_player_pos(t_cub3d *data);
void				load_texture(t_cub3d *cube3d);
void				raycast(t_cub3d *cub3d);
int					update(t_cub3d *cub3d);

// PLAYER MOVE
void				player_move_forward(t_cub3d *cub3d);
void				player_move_backward(t_cub3d *cub3d);
void				player_move_left(t_cub3d *cub3d);
void				player_move_right(t_cub3d *cub3d);

// CAMERA ROT
void				camera_rot_left(t_cub3d *cub3d);
void				camera_rot_right(t_cub3d *cub3d);

// ERROR
void				exit_on_error(t_cub3d *cub3d, char *error);

void				print(t_cub3d cub3d);

// free
void				free_str_tab(char **tab);

#endif