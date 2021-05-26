/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:27:13 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 14:55:38 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	first(t_cube *cube)
{
	int		ret;

	cube = init_mlx_and_text(cube);
	cube->move.up = 0;
	cube->move.down = 0;
	cube->move.left = 0;
	cube->move.right = 0;
	cube->move.left_arrow = 0;
	cube->move.right_arrow = 0;
	cube->sound = 1;
	system("afplay ./sounds/bobby.mp3 &");
	ret = raycasting(cube);
	mlx_hook(cube->wind.id, 2, 0, key_press, cube);
	mlx_hook(cube->wind.id, 3, 1, key_release, cube);
	mlx_hook(cube->wind.id, 17, 1, quit, cube);
	mlx_loop_hook(cube->mlx.id, raycasting, cube);
	return (*cube);
}

t_cube	*raycasting_init(t_cube *cube, int x)
{
	cube->cameraX = ((2 * x) / (double)cube->map.r_x - 1);
	cube->rayDirX = cube->dirX + cube->planeX * cube->cameraX;
	cube->rayDirY = cube->dirY + cube->planeY * cube->cameraX;
	cube->mapX = cube->pos_player_X;
	cube->mapY = cube->pos_player_Y;
	cube->ray_deltaDistX = fabs(1 / cube->rayDirX);
	cube->ray_deltaDistY = fabs(1 / cube->rayDirY);
	return (cube);
}

int	raycasting(t_cube *cube)
{
	int		x;

	x = 0;
	if ((cube->dead == 1) && cube->end == 0)
		return (0);
	else if (cube->end == 1)
		quit(cube, 1);
	cube = move(cube, &cube->map);
	cube = init_cube(cube);
	frame_rate(cube);
	while (x < cube->map.r_x)
	{
		cube = raycasting_wall(cube, x);
		x++;
	}
	cube = tri_tab_sprite_ray(cube);
	cube = sprite_raycasting(cube);
	cube = bonus_and_screen(cube);
	mlx_put_image_to_window(cube->mlx.id, cube->wind.id, cube->img.img, 0, 0);
	cube = fps(cube);
	mlx_destroy_image(cube->mlx.id, cube->img.img);
	return (0);
}

t_cube	*raycasting_wall(t_cube *cube, int x)
{
	cube = raycasting_init(cube, x);
	cube = ray_step(cube);
	cube = ray_hit(cube);
	cube = ray_draw_start_end(cube);
	cube = ray_impact_rayDir(cube, x);
	cube = ray_side_direction(cube, x);
	return (cube);
}

t_cube	*bonus_and_screen(t_cube *cube)
{
	cube = mini_map(cube);
	if (cube->save == 1)
		screen_shoot(cube);
	if (cube->dead == 1)
		cube = img_full_screen(cube, cube->img_dead);
	if (cube->wait_end == 1)
		cube = img_full_screen(cube, cube->img_end);
	return (cube);
}
