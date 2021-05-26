/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opti_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:07:16 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/13 13:12:21 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_opti_map(t_map *map)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->tab_char[y] != NULL)
	{
		while (map->tab_char[y][x] != 0)
		{
			map = parsing_opti_map_2(map, x, y);
			x++;
		}
		y++;
		x = 0;
	}
	return (map);
}

t_map	*parsing_opti_map_2(t_map *map, int x, int y)
{
	if (map->tab_char[y][x] == '.')
		map->tab_char[y][x] = '0';
	else if (map->tab_char[y][x] == '/')
		map->tab_char[y][x] = '1';
	else if (map->tab_char[y][x] == '?')
		map->tab_char[y][x] = '2';
	else if (map->tab_char[y][x] == ':')
		map->tab_char[y][x] = '3';
	else if (map->tab_char[y][x] == ';')
		map->tab_char[y][x] = '4';
	else if (map->tab_char[y][x] == '+')
		map->tab_char[y][x] = '5';
	else if (map->tab_char[y][x] != map->spawn_dir)
		map->tab_char[y][x] = ' ';
	return (map);
}

t_map	*parsing_opti_map_suppr_start(t_map *map)
{	
	int	x;
	int	y;
	int	v;

	x = 0;
	y = 0;
	v = 0;
	while (map->tab_char[y] != NULL)
	{
		if (parsing_opti_map_suppr_space(map, y) == -1)
			return (map);
		map->tab_char = ft_suppr_char_tab(map->tab_char, 0);
		if (!map->tab_char)
			return (NULL);
		x = 0;
	}
	return (map);
}

t_map	*parsing_opti_map_suppr_end(t_map *map)
{	
	int	x;
	int	y;
	int	v;

	x = 0;
	y = 0;
	v = 0;
	while (map->tab_char[y] != NULL)
		y++;
	y--;
	while (y >= 0)
	{
		if (parsing_opti_map_suppr_space(map, y) == -1)
			return (map);
		map->tab_char = ft_suppr_char_tab(map->tab_char, 1);
		if (!map->tab_char)
			return (NULL);
		x = 0;
	}
	return (map);
}

int	parsing_opti_map_suppr_space(t_map *map, int y)
{
	int	x;

	x = 0;
	while (map->tab_char[y][x] != 0)
	{
		if (map->tab_char[y][x] != ' ')
			return (-1);
		x++;
	}
	return (0);
}
