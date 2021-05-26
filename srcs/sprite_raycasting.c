/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycasting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:42:28 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 15:51:57 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*sprite_ray_calculation_plane(t_cube *cube, int num_sprite, int x)
{
	cube->sprite.cameraX = ((2 * x) / (double)cube->map.r_x - 1);
	cube->sprite.rayDirX = cube->dirX + cube->planeX * cube->sprite.cameraX;
	cube->sprite.rayDirY = cube->dirY + cube->planeY * cube->sprite.cameraX;
	cube->sprite.x_vect_normal_plan = cube->sprite.tab_sprite_all[num_sprite][1]
		- cube->pos_player_X;
	cube->sprite.y_vect_normal_plan = cube->sprite.tab_sprite_all[num_sprite][0]
		- cube->pos_player_Y;
	cube->sprite.d = -cube->sprite.x_vect_normal_plan
		* cube->sprite.tab_sprite_all[num_sprite][1]
		- cube->sprite.y_vect_normal_plan
		* cube->sprite.tab_sprite_all[num_sprite][0];
	cube->sprite.t = -(cube->sprite.x_vect_normal_plan * cube->pos_player_X
			+ cube->sprite.y_vect_normal_plan * cube->pos_player_Y
			+ cube->sprite.d) / (cube->sprite.x_vect_normal_plan
			* cube->sprite.rayDirX + cube->sprite.y_vect_normal_plan
			* cube->sprite.rayDirY);
	return (cube);
}

t_cube	*sprite_ray_calculation_dist(t_cube *cube, int num_sprite)
{
	cube->sprite.x_intersection = cube->pos_player_X + cube->sprite.rayDirX
		* cube->sprite.t;
	cube->sprite.y_intersection = cube->pos_player_Y + cube->sprite.rayDirY
		* cube->sprite.t;
	cube->sprite.dist_i_s = sqrt(pow(cube->sprite.x_intersection
				- cube->sprite.tab_sprite_all[num_sprite][1], 2)
			+ pow(cube->sprite.y_intersection
				- cube->sprite.tab_sprite_all[num_sprite][0], 2));
	cube->sprite.dist_player_i = sqrt(pow(cube->sprite.x_intersection
				- cube->pos_player_X, 2) + pow(cube->sprite.y_intersection
				- cube->pos_player_Y, 2));
	return (cube);
}

t_cube	*sprite_raycasting(t_cube *cube)
{
	int		x;
	int		num_sprite;

	x = 0;
	num_sprite = 0;
	while (num_sprite < cube->sprite.nb_sprite_all)
	{
		x = 0;
		cube->sprite.av_ap = 0;
		while (x < cube->map.r_x)
		{
			cube = sprite_ray_calculation_plane(cube, num_sprite, x);
			cube = sprite_ray_calculation_dist(cube, num_sprite);
			if (cube->sprite.dist_i_s <= 0.5)
				cube = sprite_raycasting_2(cube, num_sprite, x);
			x++;
		}
		num_sprite++;
	}
	return (cube);
}

t_cube	*sprite_raycasting_2(t_cube *cube, int num_sprite, int x)
{
	if (cube->sprite.tab_sprite_all[num_sprite][4] == 2)
		cube = sprite_ray_aff(cube, cube->text_sprite, num_sprite, x);
	if (cube->sprite.tab_sprite_all[num_sprite][4] == 3)
		cube = sprite_ray_aff(cube, cube->text_me, num_sprite, x);
	if (cube->sprite.tab_sprite_all[num_sprite][4] == 4)
		cube = sprite_ray_aff(cube, cube->text_up, num_sprite, x);
	return (cube);
}

double	inverse_dist(double a, double min, double max)
{
	if (max == 0)
		max = 0;
	a = (min - a);
	return (a);
}
