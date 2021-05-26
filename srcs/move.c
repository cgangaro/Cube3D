/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:21:06 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 16:07:10 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*move(t_cube *cube, t_map *map)
{
	if (cube->move.up)
		cube = move_up(cube, map);
	if (cube->move.down)
		cube = move_down(cube, map);
	if (cube->move.left)
		cube = move_left(cube, map);
	if (cube->move.right)
		cube = move_right(cube, map);
	cube = move_left_arrow(cube);
	cube = move_right_arrow(cube);
	return (cube);
}

t_cube	*move_up(t_cube *cube, t_map *map)
{
	if (map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '1' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '2' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '3' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '4' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '5')
		cube->pos_player_Y += (cube->dirY * cube->moveSpeed);
	if (map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * cube->moveSpeed)] != '1'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * cube->moveSpeed)] != '2'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * cube->moveSpeed)] != '3'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * cube->moveSpeed)] != '4'
		&& map->tab_char[(int)(cube->pos_player_Y)]
	 	[(int)(cube->pos_player_X + cube->dirX * cube->moveSpeed)] != '5')
		cube->pos_player_X += cube->dirX * cube->moveSpeed;
	return (cube);
}

t_cube	*move_down(t_cube *cube, t_map *map)
{
	if (map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * -cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '1' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * -cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '2' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * -cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '3' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * -cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '4' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirY * -cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '5')
		cube->pos_player_Y += (cube->dirY * -cube->moveSpeed);
	if (map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * -cube->moveSpeed)] != '1'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * -cube->moveSpeed)] != '2'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * -cube->moveSpeed)] != '3'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * -cube->moveSpeed)] != '4'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirX * -cube->moveSpeed)] != '5')
		cube->pos_player_X += (cube->dirX * -cube->moveSpeed);
	return (cube);
}

t_cube	*move_left(t_cube *cube, t_map *map)
{
	if (map->tab_char
		[(int)(cube->pos_player_Y - cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '1' && map->tab_char
		[(int)(cube->pos_player_Y - cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '2' && map->tab_char
		[(int)(cube->pos_player_Y - cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '3' && map->tab_char
		[(int)(cube->pos_player_Y - cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '4' && map->tab_char
		[(int)(cube->pos_player_Y - cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '5')
		cube->pos_player_Y -= (cube->dirX * cube->moveSpeed);
	if (map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirY * cube->moveSpeed)] != '1'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirY * cube->moveSpeed)] != '2'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirY * cube->moveSpeed)] != '3'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirY * cube->moveSpeed)] != '4'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X + cube->dirY * cube->moveSpeed)] != '5')
		cube->pos_player_X += (cube->dirY * cube->moveSpeed);
	return (cube);
}

t_cube	*move_right(t_cube *cube, t_map *map)
{
	if (map->tab_char
		[(int)(cube->pos_player_Y + cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '1' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '2' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '3' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '4' && map->tab_char
		[(int)(cube->pos_player_Y + cube->dirX * cube->moveSpeed)]
		[(int)(cube->pos_player_X)] != '5')
		cube->pos_player_Y += (cube->dirX * cube->moveSpeed);
	if (map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X - cube->dirY * cube->moveSpeed)] != '1'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X - cube->dirY * cube->moveSpeed)] != '2'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X - cube->dirY * cube->moveSpeed)] != '3'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X - cube->dirY * cube->moveSpeed)] != '4'
		&& map->tab_char[(int)(cube->pos_player_Y)]
		[(int)(cube->pos_player_X - cube->dirY * cube->moveSpeed)] != '5')
		cube->pos_player_X -= (cube->dirY * cube->moveSpeed);
	return (cube);
}
