/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:28:00 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 17:05:59 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*tri_tab_sprite_all(t_cube *cube)
{
	cube = tri_tab_add_tab(cube, cube->sprite.tab_sprite, 2);
	cube = tri_tab_add_tab(cube, cube->sprite.tab_sprite_3, 3);
	cube = tri_tab_add_tab(cube, cube->sprite.tab_sprite_4, 4);
	cube->sprite.nb_sprite_all = cube->sprite.nb_sprite
		+ cube->sprite.nb_sprite_3 + cube->sprite.nb_sprite_4;
	cube = tri_tab_sprite_all_2(cube);
	return (cube);
}

t_cube	*tri_tab_add_tab(t_cube *cube, double tab[200][4], double num)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i][0] != 0)
	{
		j = 0;
		while (cube->sprite.tab_sprite_all[j][0] != 0)
			j++;
		cube->sprite.tab_sprite_all[j][0] = tab[i][0];
		cube->sprite.tab_sprite_all[j][1] = tab[i][1];
		cube->sprite.tab_sprite_all[j][2] = tab[i][2];
		cube->sprite.tab_sprite_all[j][3] = tab[i][3];
		cube->sprite.tab_sprite_all[j][4] = num;
		i++;
	}
	return (cube);
}

t_cube	*tri_tab_sprite_all_2(t_cube *cube)
{
	int		i;
	double	dist1;
	double	dist2;

	i = 0;
	while (i < cube->sprite.nb_sprite_all - 1)
	{
		dist1 = sqrt(pow(cube->sprite.tab_sprite_all[i][1]
					- cube->pos_player_X, 2)
				+ pow(cube->sprite.tab_sprite_all[i][0]
					- cube->pos_player_Y, 2));
		dist2 = sqrt(pow(cube->sprite.tab_sprite_all[i + 1][1]
					- cube->pos_player_X, 2) + pow(cube->sprite.tab_sprite_all
				[i + 1][0] - cube->pos_player_Y, 2));
		if (dist2 > dist1)
		{
			cube = tri_tab_sprite_invers_all(cube, i);
			i = -1;
		}
		i++;
	}
	return (cube);
}

t_cube	*tri_tab_sprite_invers_all(t_cube *cube, int i)
{
	double	temp;

	temp = cube->sprite.tab_sprite_all[i][0];
	cube->sprite.tab_sprite_all[i][0] = cube->sprite.tab_sprite_all[i + 1][0];
	cube->sprite.tab_sprite_all[i + 1][0] = temp;
	temp = cube->sprite.tab_sprite_all[i][1];
	cube->sprite.tab_sprite_all[i][1] = cube->sprite.tab_sprite_all[i + 1][1];
	cube->sprite.tab_sprite_all[i + 1][1] = temp;
	temp = cube->sprite.tab_sprite_all[i][2];
	cube->sprite.tab_sprite_all[i][2] = cube->sprite.tab_sprite_all[i + 1][2];
	cube->sprite.tab_sprite_all[i + 1][2] = temp;
	temp = cube->sprite.tab_sprite_all[i][3];
	cube->sprite.tab_sprite_all[i][3] = cube->sprite.tab_sprite_all[i + 1][3];
	cube->sprite.tab_sprite_all[i + 1][3] = temp;
	temp = cube->sprite.tab_sprite_all[i][4];
	cube->sprite.tab_sprite_all[i][4] = cube->sprite.tab_sprite_all[i + 1][4];
	cube->sprite.tab_sprite_all[i + 1][4] = temp;
	return (cube);
}

t_cube	*tri_tab_sprite(t_cube *cube)
{
	int		i;
	double	dist1;
	double	dist2;

	i = 0;
	while (i < cube->sprite.nb_sprite - 1)
	{
		dist1 = sqrt(pow(cube->sprite.tab_sprite[i][1]
					- cube->pos_player_X, 2) + pow(cube->sprite.tab_sprite[i][0]
					- cube->pos_player_Y, 2));
		dist2 = sqrt(pow(cube->sprite.tab_sprite[i + 1][1]
					- cube->pos_player_X, 2) + pow(cube->sprite.tab_sprite
				[i + 1][0] - cube->pos_player_Y, 2));
		if (dist2 > dist1)
		{
			cube = tri_tab_sprite_invers(cube, i);
			i = -1;
		}
		i++;
	}
	return (cube);
}
