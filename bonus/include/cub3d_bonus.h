/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:37:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/11/30 12:21:06 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

// -------------------------- include section -------------------------- //
# include "cub_error.h"
# include "game_engine_bonus.h"
# include "img.h"
# include "libft.h"
# include "mlx.h"
# include "player.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
// -------------------------- define section -------------------------- //
# define WIDTH 1080
# define HEIGHT 720

# define PI 3.14159265359

# define FOV 60
# define TILE_SIZE 32
# define MOVE_SPEED 2
# define ROT_SPEED 0.05
# define FPS 60
# define FRAME_TIME 16.67

# define MINIMAP_SIZE 144
# define MINIMAP_OFFSET 10
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

// struct for the key
typedef struct s_key
{
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			left;
	bool			right;
	bool			shift;
	bool			ctrl;
	bool			altl;
}					t_key;

// struct for the ray
typedef struct s_ray
{
	float			hori_x;
	float			hori_y;
	float			vert_x;
	float			vert_y;
	float			angle;
	float			dist;
	int				wall;
	int				index;
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

typedef struct s_hud
{
	t_img			*hotbar;
	t_img			*heart;
	t_img			heart_animation;
	int				heart_index;
}					t_hud;

// struct for the cub3d
typedef struct s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_texture_map	*texture[6];
	t_img			img;
	t_hud			hud;
	t_map			map;
	t_player		player;
	t_key			key;
	t_ray			ray;
	double			fps;
	long			last_frame_time;
	int				nb_frame;
	bool			animation;
}					t_cub3d;
// -------------------------- function section -------------------------- //
// INIT
int					windows_init(t_cub3d *cub3d);
void				init_project(t_cub3d *cub3d, char *argv[]);

// PARSING
void				check_texture(t_cub3d *cub3d, int fd);
void				get_all_texture(t_cub3d *cub3d, int fd);
void				get_check_valid_map(t_cub3d *cube3d, int fd);
int					set_color(t_texture_map *texture, char **split, int j);
void				skip_spaces(char **str);

// UTILS
size_t				ft_strlen_not_whitespace(const char *s);
void				check_chars(t_cub3d *data, char *map_orig, char *map_copy);
void				get_player_pos(t_cub3d *data);
void				raycast(t_cub3d *cub3d);

// MINIMAP
void				calculate_map_coords(t_cub3d *cub3d, float *start_x,
						float *start_y);
void				*draw_minimap(void *cub3d);
void				draw_player(t_cub3d *cub3d);
void				draw_pov(t_cub3d *cub3d, float *start_x, float *start_y);

// RGB
int					create_rgb(int r, int g, int b);

// DRAW
void				render_wall(t_cub3d *cub3d, int ray);
void				draw_hotbar(t_cub3d *cub3d);
void				draw_hearts(t_cub3d *cub3d);
int					animation_hearts(t_cub3d *cub3d);

// CHECKERS
int					wall_hit(t_cub3d *cub3d, float x, float y);
int					inter_check(float angle, float *inter, float *step,
						int is_horizon);

// ANGLE
int					unit_circle(float angle, char c);
float				norm_angle(float angle);
float				deg_to_rad(float deg);
float				rad_to_deg(float rad);

// GETTERS
t_img				*get_wall_render_texture(t_cub3d *cub3d, int wall);
float				get_v_inter(t_cub3d *cub3d, float angle);
float				get_h_inter(t_cub3d *cub3d, float angle);
int					get_color(t_cub3d *cub3d, int wall);

// free
void				free_str_tab(char **tab);
void				free_exit(t_cub3d *cub3d, int status);
void				clean_gnl(int fd);

void				print(t_cub3d cub3d);
// ---------------------------- end of file ---------------------------- //
#endif