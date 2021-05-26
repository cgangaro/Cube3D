/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:22:22 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/13 10:31:27 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*ray_hit(t_cube *cube)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cube->ray_sideDistX < cube->ray_sideDistY)
		{
			cube->ray_sideDistX = cube->ray_sideDistX + cube->ray_deltaDistX;
			cube->mapX = cube->mapX + cube->ray_stepX;
			cube->side = 0;
		}
		else
		{
			cube->ray_sideDistY = cube->ray_sideDistY + cube->ray_deltaDistY;
			cube->mapY = cube->mapY + cube->ray_stepY;
			cube->side = 1;
		}
		cube = ray_hit_sprite(cube);
		if (cube->map.tab_char[cube->mapY][cube->mapX] == '1'
			|| cube->map.tab_char[cube->mapY][cube->mapX] == '5')
		{
			hit = 1;
		}
	}
	return (cube);
}

t_cube	*ray_hit_sprite(t_cube *cube)
{
	if (cube->map.tab_char[cube->mapY][cube->mapX] == '2')
	{
		cube->i = -1;
		cube->f = 0;
		while (cube->sprite.tab_sprite[++cube->i][0] != 0 && cube->f == 0)
		{
			if (cube->sprite.tab_sprite[cube->i][0] == cube->mapY + 0.5)
			{
				if (cube->sprite.tab_sprite[cube->i][1] == cube->mapX + 0.5)
				{
					cube->f = 1;
				}
			}
		}
		if (cube->f == 0)
		{
			cube->sprite.tab_sprite[cube->sprite.nb_sprite][0] = cube->mapY
				+ 0.5;
			cube->sprite.tab_sprite[cube->sprite.nb_sprite][1] = cube->mapX
				+ 0.5;
			cube->sprite.nb_sprite++;
		}
	}
	return (ray_hit_sprite_3(cube));
}

t_cube	*ray_hit_sprite_3(t_cube *cube)
{
	if (cube->map.tab_char[cube->mapY][cube->mapX] == '3')
	{
		cube->i = -1;
		cube->f = 0;
		while (cube->sprite.tab_sprite_3[++cube->i][0] != 0 && cube->f == 0)
		{
			if (cube->sprite.tab_sprite_3[cube->i][0] == cube->mapY + 0.5)
			{
				if (cube->sprite.tab_sprite_3[cube->i][1] == cube->mapX + 0.5)
				{
					cube->f = 1;
				}
			}
		}
		if (cube->f == 0)
		{
			cube->sprite.tab_sprite_3[cube->sprite.nb_sprite_3][0] = cube->mapY
				+ 0.5;
			cube->sprite.tab_sprite_3[cube->sprite.nb_sprite_3][1] = cube->mapX
				+ 0.5;
			cube->sprite.nb_sprite_3++;
		}
	}
	return (ray_hit_sprite_4(cube));
}

t_cube	*ray_hit_sprite_4(t_cube *cube)
{
	if (cube->map.tab_char[cube->mapY][cube->mapX] == '4')
	{
		cube->i = -1;
		cube->f = 0;
		while (cube->sprite.tab_sprite_4[++cube->i][0] != 0 && cube->f == 0)
		{
			if (cube->sprite.tab_sprite_4[cube->i][0] == cube->mapY + 0.5)
			{
				if (cube->sprite.tab_sprite_4[cube->i][1] == cube->mapX + 0.5)
				{
					cube->f = 1;
				}
			}
		}
		if (cube->f == 0)
		{
			cube->sprite.tab_sprite_4[cube->sprite.nb_sprite_4][0] = cube->mapY
				+ 0.5;
			cube->sprite.tab_sprite_4[cube->sprite.nb_sprite_4][1] = cube->mapX
				+ 0.5;
			cube->sprite.nb_sprite_4++;
		}
	}
	return (cube);
}
