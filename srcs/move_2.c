/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:25:44 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 17:25:46 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*move_left_arrow(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	if (cube->move.left_arrow)
	{
		old_dir_x = cube->dirX;
		cube->dirX = cube->dirX * cos(-cube->rotSpeed)
			- cube->dirY * sin(-cube->rotSpeed);
		cube->dirY = old_dir_x * sin(-cube->rotSpeed)
			+ cube->dirY * cos(-cube->rotSpeed);
		old_plane_x = cube->planeX;
		cube->planeX = cube->planeX * cos(-cube->rotSpeed)
			- cube->planeY * sin(-cube->rotSpeed);
		cube->planeY = old_plane_x * sin(-cube->rotSpeed)
			+ cube->planeY * cos(-cube->rotSpeed);
	}
	return (cube);
}

t_cube	*move_right_arrow(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	if (cube->move.right_arrow)
	{
		old_dir_x = cube->dirX;
		cube->dirX = cube->dirX * cos(cube->rotSpeed)
			- cube->dirY * sin(cube->rotSpeed);
		cube->dirY = old_dir_x * sin(cube->rotSpeed)
			+ cube->dirY * cos(cube->rotSpeed);
		old_plane_x = cube->planeX;
		cube->planeX = cube->planeX * cos(cube->rotSpeed)
			- cube->planeY * sin(cube->rotSpeed);
		cube->planeY = old_plane_x * sin(cube->rotSpeed)
			+ cube->planeY * cos(cube->rotSpeed);
	}
	return (cube);
}
