/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:42:25 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/13 10:05:18 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*life_hurt(t_cube *cube, char c)
{
	int		x;
	int		y;
	double	dist_p_m;

	x = floor(cube->pos_player_X);
	y = floor(cube->pos_player_Y);
	if (x > 0 && cube->map.tab_char[y][x - 1] == c)
		dist_p_m = sqrt(pow((y + 0.5) - cube->pos_player_Y, 2)
				+ pow(((x - 1) + 0.5) - cube->pos_player_X, 2));
	else if (y > 0 && cube->map.tab_char[y - 1][x] == c)
		dist_p_m = sqrt(pow(((y - 1) + 0.5) - cube->pos_player_Y, 2)
				+ pow((x + 0.5) - cube->pos_player_X, 2));
	else if (cube->map.tab_char[y][x + 1] == c)
		dist_p_m = sqrt(pow((y + 0.5) - cube->pos_player_Y, 2)
				+ pow(((x + 1) + 0.5) - cube->pos_player_X, 2));
	else if (cube->map.tab_char[y + 1][x] == c)
		dist_p_m = sqrt(pow(((y + 1) + 0.5) - cube->pos_player_Y, 2)
				+ pow((x + 0.5) - cube->pos_player_X, 2));
	else
		dist_p_m = 5.0;
	cube = life_hurt_2(cube, dist_p_m);
	return (cube);
}

t_cube	*life_hurt_2(t_cube *cube, double dist_p_m)
{
	if (dist_p_m < 0.7 && cube->life_time_hurt == 0.0)
	{
		cube->life_hurt = 1;
		cube->life_time_hurt = cube->dt.time_mem_sec;
		cube->life_percent = cube->life_percent - cube->life_percent_hurt;
	}
	if (cube->life_hurt == 1 && 1.0 < (cube->dt.time_mem_sec
			- cube->life_time_hurt))
	{
		cube->life_percent = cube->life_percent - cube->life_percent_hurt;
		cube->life_time_hurt = cube->dt.time_mem_sec;
	}
	if (dist_p_m >= 0.6)
	{
		cube->life_hurt = 0;
		cube->life_time_hurt = 0.0;
	}
	return (cube);
}
