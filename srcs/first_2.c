/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:50:19 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 14:55:59 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*init_cube(t_cube *cube)
{
	int	i;

	i = 0;
	cube->sprite.nb_sprite = 0;
	cube->sprite.nb_sprite_3 = 0;
	cube->sprite.nb_sprite_4 = 0;
	cube->sprite.nb_sprite_all = 0;
	while (i < 200)
	{
		cube->sprite.tab_sprite[i][0] = 0;
		cube->sprite.tab_sprite[i][1] = 0;
		cube->sprite.tab_sprite[i][2] = 0;
		cube->sprite.tab_sprite[i][3] = 0;
		cube->sprite.tab_sprite_3[i][0] = 0;
		cube->sprite.tab_sprite_3[i][1] = 0;
		cube->sprite.tab_sprite_3[i][2] = 0;
		cube->sprite.tab_sprite_3[i][3] = 0;
		cube->sprite.tab_sprite_4[i][0] = 0;
		cube->sprite.tab_sprite_4[i][1] = 0;
		cube->sprite.tab_sprite_4[i][2] = 0;
		cube->sprite.tab_sprite_4[i][3] = 0;
		i++;
	}
	return (init_cube_2(cube));
}

t_cube	*init_cube_2(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 400)
	{
		cube->sprite.tab_sprite_all[i][0] = 0;
		cube->sprite.tab_sprite_all[i][1] = 0;
		cube->sprite.tab_sprite_all[i][2] = 0;
		cube->sprite.tab_sprite_all[i][3] = 0;
		cube->sprite.tab_sprite_all[i][4] = 0;
		i++;
	}
	cube->img.img = mlx_new_image(cube->mlx.id, cube->map.r_x,
			cube->map.r_y);
	cube->img.addr_int = (int *)mlx_get_data_addr(cube->img.img,
			&cube->img.bits_per_pixel, &cube->img.line_length,
			&cube->img.endian);
	cube->img.line_length /= 4;
	return (cube);
}

t_cube	*tri_tab_sprite_ray(t_cube *cube)
{
	cube = tri_tab_sprite(cube);
	cube = tri_tab_sprite_n3(cube);
	cube = tri_tab_sprite_n4(cube);
	cube = tri_tab_sprite_all(cube);
	return (cube);
}

t_cube	*fps(t_cube *cube)
{
	if (cube->dt.dt)
	{
		mlx_string_put(cube->mlx.id, cube->wind.id, 10, 15, 16711680, "FPS:");
		mlx_string_put
			(cube->mlx.id, cube->wind.id, 55, 15, 16711680, cube->dt.str_dt);
		free(cube->dt.str_dt);
	}
	return (cube);
}
