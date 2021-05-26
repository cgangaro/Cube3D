/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:10:09 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/13 12:56:16 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*secret_door(t_cube *cube, char c)
{
	t_sd	sd;

	sd.x = floor(cube->pos_player_X);
	sd.y = floor(cube->pos_player_Y);
	sd.i = 0;
	while (cube->tab_door[sd.i][0] != 0)
	{
		sd.x_door = cube->tab_door[sd.i][1];
		sd.y_door = cube->tab_door[sd.i][0];
		sd.dist_p_m = sqrt(pow((cube->tab_door[sd.i][0])
					- cube->pos_player_Y, 2) + pow((cube->tab_door[sd.i][1])
					- cube->pos_player_X, 2));
		cube = secret_door_2(cube, c, sd);
		sd.i++;
	}
	if (cube->door_open_close == 1)
		cube->door_mem_oc = 1;
	return (cube);
}

t_cube	*secret_door_2(t_cube *cube, char c, t_sd sd)
{
	if (sd.dist_p_m < 2.0 && sd.dist_p_m > 0.5 && cube->door_open_close == 1
		&& cube->door_mem_oc == 0 && cube->tab_door[sd.i][2] == 1)
	{
		cube->map.tab_char[sd.y_door][sd.x_door] = '6';
		cube->tab_door[sd.i][2] = 0;
	}
	else if (sd.dist_p_m < 3.0 && sd.dist_p_m > 0.5 && cube->door_open_close
		== 1 && cube->door_mem_oc == 0 && cube->tab_door[sd.i][2] == 0)
	{
		cube->map.tab_char[sd.y_door][sd.x_door] = c;
		cube->tab_door[sd.i][2] = 1;
	}
	return (cube);
}

t_cube	*secret_door_tab(t_cube *cube, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (cube->map.tab_char[i] != NULL)
	{
		j = 0;
		while (cube->map.tab_char[i][j] != 0)
		{
			if (cube->map.tab_char[i][j] == c)
			{
				x = 0;
				while (cube->tab_door[x][0] != 0)
					x++;
				cube->tab_door[x][0] = i + 0.5;
				cube->tab_door[x][1] = j + 0.5;
			}
			j++;
		}
		i++;
	}
	return (cube);
}
