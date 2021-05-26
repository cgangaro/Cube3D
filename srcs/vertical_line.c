/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:28:21 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/11 13:24:57 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_vl	vertical_line_init(t_cube cube, t_text text, t_vl vl)
{
	if (cube.texture_coor < 0)
		cube.texture_coor = 0;
	vl.rx = floor(cube.texture_coor);
	if (cube.ray_dist_wall < 1.0)
	{
		if (cube.ray_dist_wall < 0.000001)
			vl.diff_y = (cube.drawEnd - cube.drawStart) / 0.1;
		else
			vl.diff_y = (cube.drawEnd - cube.drawStart) / cube.ray_dist_wall;
		vl.y_text = ((1 - cube.ray_dist_wall) * text.height) / 2;
	}
	else
	{
		vl.diff_y = cube.drawEnd - cube.drawStart;
		vl.y_text = 0;
	}
	vl.ry = (double)(text.height - 1) / (double)vl.diff_y;
	return (vl);
}

t_data	vertical_line(int x, t_cube cube, t_text text)
{
	t_vl	vl;
	int		color;

	vl.y = 0;
	vl = vertical_line_init(cube, text, vl);
	cube = vertical_line_2(x, cube, &vl);
	while (vl.y < cube.drawEnd)
	{
		vl.y_text = vl.y_text + vl.ry;
		vl.y_text_floor = floor(vl.y_text);
		color = text.text.addr_int[vl.y_text_floor
			* text.text.line_length + vl.rx];
		cube.img.addr_int[vl.y * cube.map.r_x + x] = color;
		vl.y++;
	}
	while (vl.y < cube.map.r_y)
	{
		cube.img.addr_int[vl.y * cube.map.r_x + x] = create_trgb
			(0, cube.map.f_1, cube.map.f_2, cube.map.f_3);
		vl.y++;
	}
	return (cube.img);
}

t_cube	vertical_line_2(int x, t_cube cube, t_vl *vl)
{
	while (vl->y < cube.drawStart)
	{
		cube.img.addr_int[vl->y * cube.map.r_x + x] = create_trgb
			(0, cube.map.c_1, cube.map.c_2, cube.map.c_3);
		vl->y++;
	}
	return (cube);
}

t_vl_sprite	vertical_line_sprite_init(t_cube cube, t_text text, t_vl_sprite vl)
{
	cube.sprite.texture_coor = cube.sprite.texture_coor * text.width;
	vl.rx = floor(cube.sprite.texture_coor);
	if (cube.sprite.dist_player_s < 1.0)
	{
		vl.y_size = cube.map.r_y;
		vl.y_text = (double)(text.height - 1) - ((double)(text.height - 1)
				*(cube.sprite.dist_player_s));
		vl.y_text = vl.y_text / 2;
		vl.ry = ((double)(text.height - 1) / (double)vl.y_size)
			* cube.sprite.dist_player_s;
	}
	else
	{
		vl.y_size = cube.map.r_y / cube.sprite.dist_player_s;
		vl.y_text = 0;
		vl.ry = ((double)(text.height - 1) / (double)vl.y_size);
	}
	return (vl);
}

t_data	vertical_line_sprite(int x, t_cube cube, t_text text)
{
	t_vl_sprite	vl;

	vl.y = 0;
	vl = vertical_line_sprite_init(cube, text, vl);
	cube.sprite.drawStart = floor((cube.map.r_y / 2) - (vl.y_size / 2));
	cube.sprite.drawEnd = floor((cube.map.r_y / 2) + (vl.y_size / 2));
	while (vl.y < cube.sprite.drawStart)
	{
		vl.y++;
	}
	while (vl.y < cube.sprite.drawEnd)
	{
		vl.y_text = vl.y_text + vl.ry;
		vl.y_text_floor = floor(vl.y_text);
		vl.color = text.text.addr_int[vl.y_text_floor
			* text.text.line_length + vl.rx];
		if ((vl.color & 0x00FFFFFF) != 0)
			cube.img.addr_int[vl.y * cube.map.r_x + x] = vl.color;
		vl.y++;
	}
	while (vl.y < cube.map.r_y)
	{
		vl.y++;
	}
	return (cube.img);
}
