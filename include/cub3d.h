/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:16:05 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/16 13:32:01 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// -------------------------- include section -------------------------- //
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# include "libft.h"
# include "mlx.h"
# include "img.h"
// -------------------------- define section -------------------------- //
# define HEIGHT 1080
# define WIDTH 1920

# define PI 3.14159265359

# define FOV 60
# define TILE_SIZE 64
# define MOVE_SPEED 4
# define ROT_SPEED 0.1
// -------------------------- enum section -------------------------- //
// enum for the wall type
enum				e_wall
{
	NONE,
	VERTICAL,
	HORIZONTAL
};

// enum for the texture
enum				e_texture
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	FLOOR,
	CEILING
};
// -------------------------- struct section -------------------------- //
// struct for the position
typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

// struct for the player
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

// struct for the ray
typedef struct s_ray
{
	float			angle;
	float			dist;
	int				wall;
}					t_ray;

// struct for the texture map
typedef struct s_texture_map
{
	char			*id;
	char			*path;
	t_img			*img;
	int				color[3];
}					t_texture_map;

// struct for the map
typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

// struct for the key
typedef struct s_key
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			left;
	bool			right;
}					t_key;

// struct for the cub3d
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
// -------------------------- function section -------------------------- //
// INIT
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

// RGB
int					create_rgb(int r, int g, int b);

// DRAW
void				render_wall(t_cub3d *cub3d, int ray);

// CHECKERS
int					wall_hit(t_cub3d *cub3d, float x, float y);
int					inter_check(float angle, float *inter, float *step,
						int is_horizon);

// ANGLE
int					unit_circle(float angle, char c);
float				norm_angle(float angle);

// GETTERS
int					get_render_texture(t_cub3d *cub3d, int wall);
float				get_v_inter(t_cub3d *cub3d, float angle);
float				get_h_inter(t_cub3d *cub3d, float angle);
int					get_color(t_cub3d *cub3d, int wall);

// PLAYER MOVE
void				player_move_forward(t_cub3d *cub3d);
void				player_move_backward(t_cub3d *cub3d);
void				player_move_left(t_cub3d *cub3d);
void				player_move_right(t_cub3d *cub3d);

// CAMERA ROT
void				camera_rot_left(t_cub3d *cub3d);
void				camera_rot_right(t_cub3d *cub3d);

// free
void				free_str_tab(char **tab);

void				print(t_cub3d cub3d);
// ---------------------------- end of file ---------------------------- //
#endif