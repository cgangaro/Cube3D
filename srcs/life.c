/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:29:34 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 17:18:58 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*life(t_cube *cube)
{
	cube = life_aff(cube);
	cube = life_aff_cadre(cube);
	cube = life_hurt(cube, '3');
	if (cube->life_percent <= 0.0)
		cube->dead = 1;
	return (cube);
}

t_cube	*life_aff(t_cube *cube)
{
	int	x;
	int	y;

	cube->life_x_ratio = 0.35;
	cube->life_y_ratio = 0.03;
	cube->x_init = (int)floor((cube->map.r_x
				- ((double)cube->map.r_x * cube->life_x_ratio)) / 2);
	cube->y_init = cube->map.r_y * cube->life_y_ratio;
	y = cube->y_init;
	while (y < cube->map.r_y * cube->life_y_ratio * 2)
	{
		x = cube->x_init;
		while (x < (cube->x_init + (cube->life_percent
					* (cube->map.r_x * cube->life_x_ratio))))
		{
			cube->img.addr_int[y * cube->map.r_x + x] = 14745600;
			x++;
		}
		y++;
	}
	return (cube);
}

t_cube	*life_aff_cadre(t_cube *cube)
{
	int	x;
	int	y;

	y = cube->y_init - cube->y_init / 6;
	while (y < (cube->y_init * 2) + (cube->y_init / 6) + 1)
	{
		x = cube->x_init - (cube->y_init / 6);
		cube = life_aff_cadre_2(cube, x, y);
		y++;
	}
	return (cube);
}

t_cube	*life_aff_cadre_2(t_cube *cube, int x, int y)
{
	if (y < cube->y_init || y > cube->y_init * 2)
	{
		while ((x < cube->x_init + (cube->map.r_x
					* cube->life_x_ratio) + (cube->y_init / 6)))
		{
			cube->img.addr_int[y * cube->map.r_x + x]
				= create_trgb(0, 102, 0, 153);
			x++;
		}
	}
	else
	{
		while (x < cube->x_init + (cube->map.r_x * cube->life_x_ratio)
			+ (cube->y_init / 6))
		{
			if (x < cube->x_init || (x > cube->x_init
					+ (cube->map.r_x * cube->life_x_ratio) - 1))
				cube->img.addr_int[y * cube->map.r_x + x]
					= create_trgb(0, 102, 0, 153);
			x++;
		}
	}
	return (cube);
}
