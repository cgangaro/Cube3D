/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:40:42 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 14:09:05 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	int	new_t;
	int	new_r;
	int	new_g;
	int	ret;

	new_t = t << 24;
	new_r = r << 16;
	new_g = g << 8;
	ret = new_t + new_r + new_g + b;
	return (ret);
}

t_cube	*img_full_screen(t_cube *cube, t_text text)
{
	t_full_s	fs;

	fs = img_full_screen_init(cube, text);
	while (fs.x < cube->map.r_x)
	{
		fs.tot_rx = fs.tot_rx + fs.rx;
		fs.x_text = floor(fs.tot_rx);
		fs.y = 0;
		fs.tot_ry = 0.0;
		while (fs.y < cube->map.r_y)
		{
			fs.tot_ry = fs.tot_ry + fs.ry;
			fs.y_text = floor(fs.tot_ry);
			fs.color = text.text.addr_int[fs.y_text
				* text.text.line_length + fs.x_text];
			if (fs.color < 0)
				fs.color = 0;
			cube->img.addr_int[fs.y * cube->map.r_x + fs.x]
				= fs.color;
			fs.y++;
		}
		fs.x++;
	}
	return (cube);
}

t_full_s	img_full_screen_init(t_cube *cube, t_text text)
{
	t_full_s	fs;

	fs.rx = ((double)text.width / (double)cube->map.r_x);
	fs.ry = ((double)text.height / (double)cube->map.r_y);
	fs.x = 0;
	fs.tot_rx = 0;
	return (fs);
}

void	frame_rate(t_cube *cube)
{
	struct timeval	time;
	long int		time_end;
	float			speed;

	gettimeofday(&time, NULL);
	time_end = time.tv_sec * 1000000 + time.tv_usec;
	if (cube->dt.time_mem > 0)
		cube->dt.dt = (time_end - cube->dt.time_mem) * 0.000001;
	cube->dt.time_mem = time_end;
	cube->dt.time_mem_sec = time_end * 0.000001;
	if (cube->dt.dt)
	{
		speed = 1 / cube->dt.dt;
		cube->dt.str_dt = ft_itoa(speed);
	}
}

t_cube	*init_screen_size(t_cube *cube)
{
	int	i;
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	i = mlx_get_screen_size(cube->mlx.id, &sizex, &sizey);
	if (cube->map.r_x > sizex || cube->map.r_y > sizey)
	{
		cube->map.r_x = sizex;
		cube->map.r_y = sizey;
	}
	return (cube);
}
