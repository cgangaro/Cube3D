/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:50:17 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 13:52:03 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*mini_map(t_cube *cube)
{
	int			side;
	t_mini_map	mini;

	side = cube->map.r_y;
	if (cube->map.r_x < cube->map.r_y)
		side = cube->map.r_x;
	side = (int)((double)side * 0.35);
	mini.y_tab = 0;
	mini = mini_map_ligne_longue(cube, mini);
	mini.nbr_pixels = (int)((double)side / (double)mini.ligne_longue);
	mini.y = cube->map.r_y - (mini.height * mini.nbr_pixels);
	cube = mini_map_aff(cube, mini);
	mini.x = (int)floor(cube->pos_player_X) * mini.nbr_pixels;
	mini.y = (cube->map.r_y - (mini.height * mini.nbr_pixels))
		+ (int)floor(cube->pos_player_Y) * mini.nbr_pixels;
	mini.color = 16711680;
	cube = mini_map_case(cube, mini);
	cube = life(cube);
	cube = secret_door(cube, '5');
	return (cube);
}

t_cube	*mini_map_aff(t_cube *cube, t_mini_map mini)
{
	while (cube->map.tab_char[mini.y_tab] != NULL)
	{
		mini.x_tab = 0;
		mini.x = 0;
		while (cube->map.tab_char[mini.y_tab][mini.x_tab] != 0)
		{
			if (cube->map.tab_char[mini.y_tab][mini.x_tab] == '0')
				mini.color = 3158064;
			if (cube->map.tab_char[mini.y_tab][mini.x_tab] == '1'
				|| cube->map.tab_char[mini.y_tab][mini.x_tab] == ' ')
				mini.color = 255;
			if (cube->map.tab_char[mini.y_tab][mini.x_tab] == '2')
				mini.color = 65280;
			cube = mini_map_case(cube, mini);
			mini.x = mini.x + mini.nbr_pixels;
			mini.x_tab++;
		}
		mini.y = mini.y + mini.nbr_pixels;
		mini.y_tab++;
	}
	return (cube);
}

t_mini_map	mini_map_ligne_longue(t_cube *cube, t_mini_map mini)
{
	int	i;
	int	j;

	j = 0;
	mini.ligne_longue = 0;
	while (cube->map.tab_char[j] != NULL)
	{
		i = ft_strlen(cube->map.tab_char[j]);
		if (i > mini.ligne_longue)
			mini.ligne_longue = i;
		j++;
	}
	if (j > mini.ligne_longue)
		mini.ligne_longue = j;
	mini.height = j;
	return (mini);
}

t_cube	*mini_map_case(t_cube *cube, t_mini_map mini)
{
	int	x;
	int	y;

	y = mini.y;
	while (y < (mini.y + mini.nbr_pixels))
	{
		x = mini.x;
		while (x < (mini.x + mini.nbr_pixels))
		{
			cube->img.addr_int[y * cube->map.r_x + x] = mini.color;
			x++;
		}
		y++;
	}
	return (cube);
}

t_cube	*mini_map_cadre(t_cube *cube)
{
	int	y;
	int	x;

	y = cube->map.r_y - 355;
	while (y <= cube->map.r_y - 350)
	{
		x = 0;
		while (x < 350)
		{
			cube->img.addr_int[y * cube->map.r_x + x] = 6684825;
			x++;
		}
		y++;
	}
	while (y <= cube->map.r_y - 1)
	{
		x = 350;
		while (x <= 355)
		{
			cube->img.addr_int[y * cube->map.r_x + x] = 6684825;
			x++;
		}
		y++;
	}
	return (cube);
}
