/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:08:24 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 14:55:50 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	init_main(t_cube cube, t_map map)
{
	cube.door_open_close = 0;
	cube.door_mem_oc = 0;
	cube.moveSpeed = 0.15;
	cube.rotSpeed = 0.1;
	cube.life_percent_hurt = 0.1;
	cube.life_percent = 1.0;
	cube.dead = 0;
	cube.end = 0;
	cube.wait_end = 0;
	cube.sound = 0;
	cube = spawn_and_dir(cube, map);
	return (cube);
}

t_cube	init_main_2(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		cube->tab_door[i][0] = 0;
		cube->tab_door[i][1] = 0;
		cube->tab_door[i][2] = 1;
		i++;
	}
	cube = secret_door_tab(cube, '5');
	return (*cube);
}

t_cube	spawn_and_dir(t_cube cube, t_map map)
{
	cube.pos_player_X = map.spawn_x;
	cube.pos_player_Y = map.spawn_y;
	if (map.spawn_dir == 'N' || map.spawn_dir == 'S')
		cube = spawn_dir_N_or_S(cube, map);
	else if (map.spawn_dir == 'W' || map.spawn_dir == 'E')
		cube = spawn_dir_W_or_E(cube, map);
	return (cube);
}

t_cube	spawn_dir_N_or_S(t_cube cube, t_map map)
{
	if (map.spawn_dir == 'N')
	{
		cube.dirX = 0;
		cube.dirY = -1;
		cube.planeX = 0.66;
		cube.planeY = 0;
		cube.cam_dir = 1;
	}
	else if (map.spawn_dir == 'S')
	{
		cube.dirX = 0;
		cube.dirY = 1;
		cube.planeX = -0.66;
		cube.planeY = 0;
		cube.cam_dir = -1;
	}
	return (cube);
}

t_cube	spawn_dir_W_or_E(t_cube cube, t_map map)
{
	if (map.spawn_dir == 'W')
	{
		cube.dirX = -1;
		cube.dirY = 0;
		cube.planeX = 0;
		cube.planeY = -0.66;
		cube.cam_dir = -1;
	}
	else if (map.spawn_dir == 'E')
	{
		cube.dirX = 1;
		cube.dirY = 0;
		cube.planeX = 0;
		cube.planeY = 0.66;
		cube.cam_dir = 1;
	}
	return (cube);
}
