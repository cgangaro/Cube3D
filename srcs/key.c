/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:06:57 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 17:07:23 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	key_press(int key, t_cube *cube)
{
	if (key == 13)
		cube->move.up = 1;
	if (key == 1)
		cube->move.down = 1;
	if (key == 0)
		cube->move.left = 1;
	if (key == 2)
		cube->move.right = 1;
	if (key == 123)
		cube->move.left_arrow = 1;
	if (key == 124)
		cube->move.right_arrow = 1;
	if (key > 0 && (cube->dead == 1 || cube->wait_end == 1))
		cube->end = 1;
	if (key == 5)
		cube->door_open_close = 1;
	if (key == 53)
		cube->wait_end = 1;
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key == 13)
		cube->move.up = 0;
	if (key == 1)
		cube->move.down = 0;
	if (key == 0)
		cube->move.left = 0;
	if (key == 2)
		cube->move.right = 0;
	if (key == 123)
		cube->move.left_arrow = 0;
	if (key == 124)
		cube->move.right_arrow = 0;
	if (key == 5)
	{
		cube->door_open_close = 0;
		cube->door_mem_oc = 0;
	}
	return (0);
}
