/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:53:55 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 15:36:11 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_wind
{
	void		*id;
}				t_wind;

typedef struct s_dt
{
	float		dt;
	double		time_mem;
	double		time_mem_sec;
	char		*str_dt;
}				t_dt;

typedef struct s_mlx
{
	void		*id;
}				t_mlx;

typedef struct s_move {
	int			up;
	int			down;
	int			left;
	int			right;
	int			left_arrow;
	int			right_arrow;
}				t_move;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			*addr_int;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_text
{
	t_data		text;
	int			width;
	int			height;
}				t_text;

typedef struct s_sd
{
	int			x;
	int			y;
	int			i;
	int			x_door;
	int			y_door;
	double		dist_p_m;
}				t_sd;

typedef struct s_map
{
	int		r_x;
	int		r_y;
	char	*text_no;
	char	*text_so;
	char	*text_ea;
	char	*text_we;
	char	*text_sp;
	char	*text_me;
	char	*text_up;
	int		f_1;
	int		f_2;
	int		f_3;
	int		f;
	int		c_1;
	int		c_2;
	int		c_3;
	int		c;
	char	*error;
	int		end_parametres;
	char	**tab_char;
	int		taille_tab;
	char	*nom_fichier;
	int		spawn_x;
	int		spawn_y;
	char	spawn_dir;
	int		start;
}				t_map;

typedef struct s_vl
{
	int		y;
	int		rx;
	double	ry;
	int		y_text_floor;
	double	y_text;
	int		diff_y;
}				t_vl;

typedef struct s_vl_sprite
{
	int		y;
	int		rx;
	double	ry;
	int		y_text_floor;
	double	y_text;
	int		diff_y;
	int		color;
	int		y_size;
}				t_vl_sprite;

typedef struct s_mini_map
{
	int		y;
	int		x;
	int		y_tab;
	int		x_tab;
	int		color;
	int		nbr_pixels;
	int		ligne_longue;
	int		height;
}				t_mini_map;

typedef struct s_full_s
{
	double	rx;
	double	ry;
	double	tot_rx;
	double	tot_ry;
	int		x;
	int		y;
	int		x_text;
	int		y_text;
	int		color;
}				t_full_s;

typedef struct s_sprite
{
	double		tab_sprite[200][4];
	double		tab_sprite_3[200][4];
	double		tab_sprite_4[200][4];
	double		tab_sprite_all[400][5];
	double		tab_impact_ray[3500][2];
	int			nb_sprite;
	int			nb_sprite_3;
	int			nb_sprite_4;
	int			nb_sprite_all;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			ray_stepX;
	int			ray_stepY;
	double		ray_sideDistX;
	double		ray_sideDistY;
	double		ray_deltaDistX;
	double		ray_deltaDistY;
	double		ray_dist_wall;
	int			mapX;
	int			mapY;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		pos_rayDir;
	double		wall;
	double		texture_coor;
	double		ray_dist_center_sprite;
	double		dist_rayDir_center_sprite;
	double		dist_player_i;
	double		dist_player_s;
	double		x_vect_normal_plan;
	double		y_vect_normal_plan;
	double		x_intersection;
	double		y_intersection;
	double		dist_i_s;
	double		x_vect_normal_1;
	double		y_vect_normal_1;
	double		x_vect_player_i;
	double		y_vect_player_i;
	double		x_vect_player_i_1;
	double		y_vect_player_i_1;
	double		dist_1_dir_s;
	double		dist_1_dir_i;
	double		dist_1_i_s;
	double		dist_impact_player;
	double		t;
	double		d;
	int			av_ap;
}				t_sprite;

typedef struct s_cube {
	t_dt		dt;
	double		pos_player_X;
	double		pos_player_Y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	int			ray_stepX;
	int			ray_stepY;
	double		ray_sideDistX;
	double		ray_sideDistY;
	double		ray_deltaDistX;
	double		ray_deltaDistY;
	double		ray_dist_wall;
	int			lineHeight;
	t_sprite	sprite;
	t_data		img;
	t_text		text_no;
	t_text		text_so;
	t_text		text_we;
	t_text		text_ea;
	t_text		text_sprite;
	t_text		text_me;
	t_text		text_up;
	t_text		img_dead;
	t_text		img_end;
	t_move		move;
	double		moveSpeed;
	double		rotSpeed;
	double		oldDirX;
	double		oldPlaneX;
	t_mlx		mlx;
	t_wind		wind;
	t_map		map;
	int			drawStart;
	int			drawEnd;
	double		pos_rayDir;
	double		wall;
	double		texture_coor;
	int			side;
	int			cam_dir;
	int			save;
	int			i;
	int			f;
	float		life_percent;
	float		life_x_ratio;
	float		life_y_ratio;
	int			x_init;
	int			y_init;
	int			life_hurt;
	double		life_time_hurt;
	float		life_percent_hurt;
	int			dead;
	int			end;
	int			wait_end;
	double		tab_door[50][3];
	int			door_open_close;
	int			door_mem_oc;
	int			sound;
}				t_cube;

t_map		*init_struct(t_map *map);
t_map		*parsing(char *nom_fichier, t_map *map);
t_map		*parsing_2(t_map *map, int fd, int ret_get, char *line);
t_map		*parsing_save_settings(char *line, t_map *map);
int			parsing_start_map(char *line);
char		*parsing_trim_setting(char *line, int mode);
char		*parsing_trim_setting_2(char *line, int y, int i);
t_map		*parsing_resolution(char *line, t_map *map);
t_map		*parsing_resolution_2(t_map *map, char *param);
t_map		*parsing_texture(char *line, t_map *map, char c, char c2);
t_map		*parsing_texture_2(char *line, t_map *map, char c, char c2);
t_map		*parsing_texture_3(char *line, t_map *map, char c, char c2);
t_map		*parsing_texture_4(char *line, t_map *map, char c);
t_map		*parsing_color_f(char *line, t_map *map);
t_map		*parsing_color_f_2(t_map *map, char *param);
t_map		*parsing_color_c(char *line, t_map *map);
t_map		*parsing_color_c_2(t_map *map, char *param);
t_map		*parsing_parametres(char *line, t_map *map);
t_map		*parsing_map_verif(t_map *map);
t_map		*parsing_map_verif_caracteres(t_map *map);
t_map		*parsing_map_verif_caracteres_2(t_map *map, int i, int y);
t_map		*parsing_spawn(t_map *map);
t_map		*parsing_verif_close(t_map *map, int x, int y);
t_map		*parsing_verif_close_2(t_map *map, int x, int y);
t_map		*parsing_opti_map(t_map *map);
t_map		*parsing_opti_map_2(t_map *map, int x, int y);
t_map		*parsing_opti_map_suppr_start(t_map *map);
t_map		*parsing_opti_map_suppr_end(t_map *map);
int			parsing_opti_map_suppr_space(t_map *map, int y);
int			parsing_verif_parametres_colors(char *line, t_map *map, int i);
int			parsing_verif_parametres_textures(char *line, t_map *map, int i);
int			parsing_verif_parametres_textures_2(char *line,
				t_map *map, int i, int error);
int			parsing_verif_parametres_R(char *line, t_map *map, int i);
int			parsing_verif_parametres_R_2(char *line, int i, int r_1, int r_2);
int			parsing_verif_all_parametres(t_map *map);
int			parsing_verif_parametres(char *line, t_map *map);
int			error_parsing(t_map *map);
int			error_parsing_2(t_map *map);
t_map		*parsing_rectification_resolution(t_map *map);

t_map		*parsing_tab_char(char *line, int fd, int ret_get, t_map *map);
t_map		*parsing_tab_char_2(char *line, int fd, int ret_get, t_map *map);
t_map		*parsing_tab_char_3(char *line, int fd, int ret_get, t_map *map);
t_map		*parsing_tab_char_4(char *line, int fd, int ret_get, t_map *map);

char		*arg_error(int argc, char **argv);
t_cube		init_main(t_cube cube, t_map map);
t_cube		init_main_2(t_cube *cube);
void		arg_error_name_file(char **argv);
t_cube		spawn_and_dir(t_cube cube, t_map map);
t_cube		spawn_dir_N_or_S(t_cube cube, t_map map);
t_cube		spawn_dir_W_or_E(t_cube cube, t_map map);

t_cube		first(t_cube *cube);
t_cube		*init_mlx_and_text(t_cube *cube);
t_cube		*init_mlx_and_text_2(t_cube *cube);
t_cube		*init_mlx_and_text_3(t_cube *cube);
t_cube		*init_mlx_and_text_4(t_cube *cube);
t_cube		*init_mlx_and_text_5(t_cube *cube);
t_cube		*init_mlx_and_text_6(t_cube *cube);
t_cube		*init_screen_size(t_cube *cube);

t_cube		*move(t_cube *cube, t_map *map);
t_cube		*move_up(t_cube *cube, t_map *map);
t_cube		*move_down(t_cube *cube, t_map *map);
t_cube		*move_left(t_cube *cube, t_map *map);
t_cube		*move_right(t_cube *cube, t_map *map);
t_cube		*move_left_arrow(t_cube *cube);
t_cube		*move_right_arrow(t_cube *cube);

int			raycasting(t_cube *cube);
t_cube		*raycasting_init(t_cube *cube, int x);
t_cube		*raycasting_wall(t_cube *cube, int x);
t_cube		*ray_step(t_cube *cube);
t_cube		*ray_hit(t_cube *cube);
t_cube		*ray_hit_sprite(t_cube *cube);
t_cube		*ray_hit_sprite_3(t_cube *cube);
t_cube		*ray_hit_sprite_4(t_cube *cube);
t_cube		*ray_draw_start_end(t_cube *cube);
t_cube		*ray_impact_rayDir(t_cube *cube, int x);
t_cube		*ray_side_direction(t_cube	*cube, int x);
t_cube		*init_cube(t_cube *cube);
t_cube		*init_cube_2(t_cube *cube);
t_cube		*bonus_and_screen(t_cube *cube);
t_cube		*tri_tab_sprite_ray(t_cube *cube);
t_cube		*fps(t_cube *cube);

t_data		vertical_line(int x, t_cube cube, t_text text);
t_cube		vertical_line_2(int x, t_cube cube, t_vl *vl);
t_vl		vertical_line_init(t_cube cube, t_text text, t_vl vl);
t_data		vertical_line_sprite(int x, t_cube cube, t_text text);
t_vl_sprite	vertical_line_sprite_init(t_cube cube, t_text text, t_vl_sprite vl);

t_cube		*sprite_raycasting(t_cube *cube);
t_cube		*sprite_raycasting_2(t_cube *cube, int num_sprite, int x);
t_cube		*sprite_ray_calculation_plane(t_cube *cube, int num_sprite, int x);
t_cube		*sprite_ray_calculation_dist(t_cube *cube, int num_sprite);
t_cube		*sprite_ray_aff(t_cube *cube, t_text text, int num_sprite, int x);
t_cube		*sprite_ray_unit_vectors(t_cube *cube, int num_sprite);
t_cube		*sprite_ray_calculation_dist_unit_vectors(t_cube *cube);
t_cube		*sprite_ray_rayDir_left_screen(t_cube *cube, int x, t_text text);
t_cube		*sprite_ray_rayDir_right_screen(t_cube *cube, int x, t_text text);
double		inverse_dist(double a, double min, double max);

int			key_press(int key, t_cube *cube);
int			key_release(int key, t_cube *cube);
int			create_trgb(int t, int r, int g, int b);
t_cube		*tri_tab_sprite(t_cube *cube);
t_cube		*tri_tab_sprite_invers(t_cube *cube, int i);
t_cube		*tri_tab_sprite_n3(t_cube *cube);
t_cube		*tri_tab_sprite_invers_n3(t_cube *cube, int i);
t_cube		*tri_tab_sprite_n4(t_cube *cube);
t_cube		*tri_tab_sprite_invers_n4(t_cube *cube, int i);
t_cube		*tri_tab_sprite_all(t_cube *cube);
t_cube		*tri_tab_sprite_all_2(t_cube *cube);
t_cube		*tri_tab_add_tab(t_cube *cube, double tab[200][4], double num);
t_cube		*tri_tab_sprite_invers_all(t_cube *cube, int i);

int			screen_shoot(t_cube *cube);
void		header_bmp(t_cube *cube, unsigned char **img_bmp, int size);
void		copy_img_to_bmp(t_cube *cube, unsigned char **img_bmp);
t_cube		*mini_map(t_cube *cube);
t_cube		*mini_map_cadre(t_cube *cube);
t_cube		*mini_map_case(t_cube *cube, t_mini_map mini);
t_mini_map	mini_map_ligne_longue(t_cube *cube, t_mini_map mini);
t_cube		*mini_map_aff(t_cube *cube, t_mini_map mini);
t_cube		*life(t_cube *cube);
t_cube		*life_aff(t_cube *cube);
t_cube		*life_aff_cadre(t_cube *cube);
t_cube		*life_aff_cadre_2(t_cube *cube, int x, int y);
t_cube		*life_hurt(t_cube *cube, char c);
t_cube		*life_hurt_2(t_cube *cube, double dist_p_m);
t_cube		*img_full_screen(t_cube *cube, t_text text);
t_full_s	img_full_screen_init(t_cube *cube, t_text text);
t_cube		*secret_door(t_cube *cube, char c);
t_cube		*secret_door_2(t_cube *cube, char c, t_sd sd);
t_cube		*secret_door_tab(t_cube *cube, char c);
void		frame_rate(t_cube *cube);

int			quit(t_cube *cube, int error);
void		quit_2(t_cube *cube);

#endif