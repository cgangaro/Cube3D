/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycasting_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:37:17 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/11 15:51:09 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*sprite_ray_aff(t_cube *cube, t_text text, int num_sprite, int x)
{
	cube->sprite.dist_impact_player = sqrt(pow(cube->sprite.tab_impact_ray[x][1]
				- cube->pos_player_X, 2) + pow(cube->sprite.tab_impact_ray[x][0]
				- cube->pos_player_Y, 2));
	if (cube->sprite.dist_impact_player > cube->sprite.dist_player_i)
	{
		cube = sprite_ray_unit_vectors(cube, num_sprite);
		cube = sprite_ray_calculation_dist_unit_vectors(cube);
		if (x == cube->map.r_x / 2)
		{
			if (cube->sprite.av_ap == 0)
				cube->sprite.texture_coor = inverse_dist
					(cube->sprite.dist_i_s, 0.5, 0);
			if (cube->sprite.av_ap == 1)
				cube->sprite.texture_coor = cube->sprite.dist_i_s + 0.5;
			cube->img = vertical_line_sprite
				(x, *cube, text);
		}
		else if (x < cube->map.r_x / 2)
			cube = sprite_ray_rayDir_left_screen(cube, x, text);
		else if (x > cube->map.r_x / 2)
			cube = sprite_ray_rayDir_right_screen(cube, x, text);
	}
	return (cube);
}

t_cube	*sprite_ray_unit_vectors(t_cube *cube, int num_sprite)
{
	cube->sprite.dist_player_s = sqrt(pow(cube->sprite.tab_sprite_all
			[num_sprite][1] - cube->pos_player_X, 2)
			+ pow(cube->sprite.tab_sprite_all
			[num_sprite][0] - cube->pos_player_Y, 2));
	cube->sprite.x_vect_normal_1 = cube->sprite.x_vect_normal_plan
		/ cube->sprite.dist_player_s;
	cube->sprite.y_vect_normal_1 = cube->sprite.y_vect_normal_plan
		/ cube->sprite.dist_player_s;
	cube->sprite.x_vect_player_i = cube->sprite.x_intersection
		- cube->pos_player_X;
	cube->sprite.y_vect_player_i = cube->sprite.y_intersection
		- cube->pos_player_Y;
	cube->sprite.x_vect_player_i_1 = cube->sprite.x_vect_player_i
		/ cube->sprite.dist_player_i;
	cube->sprite.y_vect_player_i_1 = cube->sprite.y_vect_player_i
		/ cube->sprite.dist_player_i;
	return (cube);
}

t_cube	*sprite_ray_calculation_dist_unit_vectors(t_cube *cube)
{
	cube->sprite.dist_1_dir_s = sqrt(pow((cube->pos_player_X + cube->dirX)
				- (cube->pos_player_X + cube->sprite.x_vect_normal_1), 2)
			+ pow((cube->pos_player_Y + cube->dirY) - (cube->pos_player_Y
					+ cube->sprite.y_vect_normal_1), 2));
	cube->sprite.dist_1_dir_i = sqrt(pow((cube->pos_player_X + cube->dirX)
				- (cube->pos_player_X + cube->sprite.x_vect_player_i_1), 2)
			+ pow((cube->pos_player_Y + cube->dirY) - (cube->pos_player_Y
					+ cube->sprite.y_vect_player_i_1), 2));
	cube->sprite.dist_1_i_s = sqrt(pow((cube->pos_player_X
					+ cube->sprite.x_vect_player_i_1) - (cube->pos_player_X
					+ cube->sprite.x_vect_normal_1), 2)
			+ pow((cube->pos_player_Y
					+ cube->sprite.y_vect_player_i_1) - (cube->pos_player_Y
					+ cube->sprite.y_vect_normal_1), 2));
	return (cube);
}

t_cube	*sprite_ray_rayDir_left_screen(t_cube *cube, int x, t_text text)
{
	if (cube->sprite.dist_1_dir_s == cube->sprite.dist_1_dir_i)
		cube->sprite.texture_coor = 0.5;
	else if (cube->sprite.dist_1_dir_s < cube->sprite.dist_1_dir_i
		|| (cube->sprite.dist_1_dir_s > cube->sprite.dist_1_dir_i
			&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_i
			&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_s))
	{
		cube->sprite.texture_coor = inverse_dist(cube->sprite.dist_i_s, 0.5, 0);
		cube->sprite.av_ap = 0;
	}
	else if (cube->sprite.dist_1_dir_s > cube->sprite.dist_1_dir_i)
	{
		cube->sprite.texture_coor = cube->sprite.dist_i_s + 0.5;
		cube->sprite.av_ap = 1;
	}
	cube->img = vertical_line_sprite(x, *cube, text);
	return (cube);
}

t_cube	*sprite_ray_rayDir_right_screen(t_cube *cube, int x, t_text text)
{
	if (cube->sprite.dist_1_dir_s == cube->sprite.dist_1_dir_i)
		cube->sprite.texture_coor = 0.5;
	else if (cube->sprite.dist_1_dir_s < cube->sprite.dist_1_dir_i
		|| (cube->sprite.dist_1_dir_i < cube->sprite.dist_1_dir_s
			&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_s
			&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_i))
	{
		cube->sprite.texture_coor = cube->sprite.dist_i_s + 0.5;
		cube->sprite.av_ap = 1;
	}
	else if ((cube->sprite.dist_1_dir_s > cube->sprite.dist_1_dir_i
			&& !(cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_i
				&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_s))
		|| (cube->sprite.dist_1_dir_s < cube->sprite.dist_1_dir_i
			&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_i
			&& cube->sprite.dist_1_i_s > cube->sprite.dist_1_dir_s))
	{
		cube->sprite.texture_coor = inverse_dist(cube->sprite.dist_i_s, 0.5, 0);
		cube->sprite.av_ap = 0;
	}
	cube->img = vertical_line_sprite(x, *cube, text);
	return (cube);
}
