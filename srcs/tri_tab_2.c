/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_tab_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:28:51 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 17:05:31 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*tri_tab_sprite_invers(t_cube *cube, int i)
{
	double	temp;

	temp = cube->sprite.tab_sprite[i][0];
	cube->sprite.tab_sprite[i][0]
		= cube->sprite.tab_sprite[i + 1][0];
	cube->sprite.tab_sprite[i + 1][0] = temp;
	temp = cube->sprite.tab_sprite[i][1];
	cube->sprite.tab_sprite[i][1] = cube->sprite.tab_sprite[i + 1][1];
	cube->sprite.tab_sprite[i + 1][1] = temp;
	temp = cube->sprite.tab_sprite[i][2];
	cube->sprite.tab_sprite[i][2] = cube->sprite.tab_sprite[i + 1][2];
	cube->sprite.tab_sprite[i + 1][2] = temp;
	temp = cube->sprite.tab_sprite[i][3];
	cube->sprite.tab_sprite[i][3] = cube->sprite.tab_sprite[i + 1][3];
	cube->sprite.tab_sprite[i + 1][3] = temp;
	return (cube);
}

t_cube	*tri_tab_sprite_n3(t_cube *cube)
{
	int		i;
	double	dist1;
	double	dist2;

	i = 0;
	while (i < cube->sprite.nb_sprite_3 - 1)
	{
		dist1 = sqrt(pow(cube->sprite.tab_sprite_3[i][1]
					- cube->pos_player_X, 2)
				+ pow(cube->sprite.tab_sprite_3[i][0]
					- cube->pos_player_Y, 2));
		dist2 = sqrt(pow(cube->sprite.tab_sprite_3[i + 1][1]
					- cube->pos_player_X, 2) + pow(cube->sprite.tab_sprite_3
				[i + 1][0] - cube->pos_player_Y, 2));
		if (dist2 > dist1)
		{
			cube = tri_tab_sprite_invers_n3(cube, i);
			i = -1;
		}
		i++;
	}
	return (cube);
}

t_cube	*tri_tab_sprite_invers_n3(t_cube *cube, int i)
{
	double	temp;

	temp = cube->sprite.tab_sprite_3[i][0];
	cube->sprite.tab_sprite_3[i][0] = cube->sprite.tab_sprite_3[i + 1][0];
	cube->sprite.tab_sprite_3[i + 1][0] = temp;
	temp = cube->sprite.tab_sprite_3[i][1];
	cube->sprite.tab_sprite_3[i][1] = cube->sprite.tab_sprite_3[i + 1][1];
	cube->sprite.tab_sprite_3[i + 1][1] = temp;
	temp = cube->sprite.tab_sprite_3[i][2];
	cube->sprite.tab_sprite_3[i][2] = cube->sprite.tab_sprite_3[i + 1][2];
	cube->sprite.tab_sprite_3[i + 1][2] = temp;
	temp = cube->sprite.tab_sprite_3[i][3];
	cube->sprite.tab_sprite_3[i][3] = cube->sprite.tab_sprite_3[i + 1][3];
	cube->sprite.tab_sprite_3[i + 1][3] = temp;
	return (cube);
}

t_cube	*tri_tab_sprite_n4(t_cube *cube)
{
	int		i;
	double	dist1;
	double	dist2;

	i = 0;
	while (i < cube->sprite.nb_sprite_4 - 1)
	{
		dist1 = sqrt(pow(cube->sprite.tab_sprite_4[i][1]
					- cube->pos_player_X, 2)
				+ pow(cube->sprite.tab_sprite_4[i][0]
					- cube->pos_player_Y, 2));
		dist2 = sqrt(pow(cube->sprite.tab_sprite_4[i + 1][1]
					- cube->pos_player_X, 2) + pow(cube->sprite.tab_sprite_4
				[i + 1][0] - cube->pos_player_Y, 2));
		if (dist2 > dist1)
		{
			cube = tri_tab_sprite_invers_n4(cube, i);
			i = -1;
		}
		i++;
	}
	return (cube);
}

t_cube	*tri_tab_sprite_invers_n4(t_cube *cube, int i)
{
	double	temp;

	temp = cube->sprite.tab_sprite_4[i][0];
	cube->sprite.tab_sprite_4[i][0] = cube->sprite.tab_sprite_4[i + 1][0];
	cube->sprite.tab_sprite_4[i + 1][0] = temp;
	temp = cube->sprite.tab_sprite_4[i][1];
	cube->sprite.tab_sprite_4[i][1] = cube->sprite.tab_sprite_4[i + 1][1];
	cube->sprite.tab_sprite_4[i + 1][1] = temp;
	temp = cube->sprite.tab_sprite_4[i][2];
	cube->sprite.tab_sprite_4[i][2] = cube->sprite.tab_sprite_4[i + 1][2];
	cube->sprite.tab_sprite_4[i + 1][2] = temp;
	temp = cube->sprite.tab_sprite_4[i][3];
	cube->sprite.tab_sprite_4[i][3] = cube->sprite.tab_sprite_4[i + 1][3];
	cube->sprite.tab_sprite_4[i + 1][3] = temp;
	return (cube);
}
