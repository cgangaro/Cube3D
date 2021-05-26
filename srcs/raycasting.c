/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:38:46 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 16:23:15 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*ray_step(t_cube *cube)
{
	if (cube->rayDirX < 0)
	{
		cube->ray_stepX = -1;
		cube->ray_sideDistX = (cube->pos_player_X - cube->mapX)
			* cube->ray_deltaDistX;
	}
	else
	{
		cube->ray_stepX = 1;
		cube->ray_sideDistX = (cube->mapX + 1.0 - cube->pos_player_X)
			* cube->ray_deltaDistX;
	}
	if (cube->rayDirY < 0)
	{
		cube->ray_stepY = -1;
		cube->ray_sideDistY = (cube->pos_player_Y - cube->mapY)
			* cube->ray_deltaDistY;
	}
	else
	{
		cube->ray_stepY = 1;
		cube->ray_sideDistY = (cube->mapY + 1.0 - cube->pos_player_Y)
			* cube->ray_deltaDistY;
	}
	return (cube);
}

t_cube	*ray_draw_start_end(t_cube *cube)
{
	if (cube->side == 0)
		cube->ray_dist_wall = (cube->mapX - cube->pos_player_X
				+ (1 - cube->ray_stepX) / 2) / cube->rayDirX;
	else
		cube->ray_dist_wall = (cube->mapY - cube->pos_player_Y
				+ (1 - cube->ray_stepY) / 2) / cube->rayDirY;
	if (cube->ray_dist_wall < 1)
		cube->lineHeight = cube->map.r_y;
	else
		cube->lineHeight = (int)((double)cube->map.r_y / cube->ray_dist_wall);
	cube->drawStart = -cube->lineHeight / 2 + cube->map.r_y / 2;
	if (cube->drawStart < 0)
		cube->drawStart = 0;
	cube->drawEnd = cube->lineHeight / 2 + cube->map.r_y / 2;
	if (cube->drawEnd >= cube->map.r_y)
		cube->drawEnd = cube->map.r_y - 1;
	return (cube);
}

t_cube	*ray_impact_rayDir(t_cube *cube, int x)
{
	if (cube->side == 0)
		cube->pos_rayDir = cube->pos_player_Y
			+ cube->ray_dist_wall * cube->rayDirY;
	else
		cube->pos_rayDir = cube->pos_player_X
			+ cube->ray_dist_wall * cube->rayDirX;
	cube->sprite.tab_impact_ray[x][0] = cube->pos_player_Y + cube->ray_dist_wall
		* cube->rayDirY;
	cube->sprite.tab_impact_ray[x][1] = cube->pos_player_X + cube->ray_dist_wall
		* cube->rayDirX;
	cube->wall = cube->pos_rayDir - floor(cube->pos_rayDir);
	return (cube);
}

t_cube	*ray_side_direction(t_cube	*cube, int x)
{
	if (cube->side == 1 && cube->rayDirY < 0.0)
	{
		cube->texture_coor = cube->wall * (double)cube->text_no.width;
		cube->img = vertical_line(x, *cube, cube->text_no);
	}
	else if (cube->side == 1 && cube->rayDirY >= 0.0)
	{
		cube->texture_coor = cube->wall * (double)cube->text_so.width;
		cube->texture_coor = (double)cube->text_so.width
			- cube->texture_coor - 1;
		cube->img = vertical_line(x, *cube, cube->text_so);
	}
	else if (cube->side == 0 && cube->rayDirX < 0.0)
	{
		cube->texture_coor = cube->wall * (double)cube->text_we.width;
		cube->texture_coor = (double)cube->text_we.width
			- cube->texture_coor - 1;
		cube->img = vertical_line(x, *cube, cube->text_we);
	}
	else if (cube->side == 0 && cube->rayDirX >= 0.0)
	{
		cube->texture_coor = cube->wall * (double)cube->text_ea.width;
		cube->img = vertical_line(x, *cube, cube->text_ea);
	}
	return (cube);
}
