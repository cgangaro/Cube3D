/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_verif_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:12:08 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/13 13:19:45 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_verif_close(t_map *map, int x, int y)
{
	if (map->error != NULL)
		return (map);
	if (x >= (int)ft_strlen(map->tab_char[y]) || x < 0
		|| y >= map->taille_tab || y < 0)
	{
		map->error = "Erreur : la map n'est pas fermee";
		return (map);
	}
	if (map->tab_char[y][x] == ' ' || map->tab_char[y][x] == '.' ||
	map->tab_char[y][x] == '/' || map->tab_char[y][x] == '?' ||
	map->tab_char[y][x] == ':' || map->tab_char[y][x] == ';' ||
	map->tab_char[y][x] == '+')
		return (map);
	if (map->tab_char[y][x] == '1')
	{
		map->tab_char[y][x] = '/';
		return (map);
	}
	map = parsing_verif_close_2(map, x, y);
	map = parsing_verif_close(map, x + 1, y);
	map = parsing_verif_close(map, x, y + 1);
	map = parsing_verif_close(map, x - 1, y);
	map = parsing_verif_close(map, x, y - 1);
	return (map);
}

t_map	*parsing_verif_close_2(t_map *map, int x, int y)
{
	if (map->tab_char[y][x] == '0')
		map->tab_char[y][x] = '.';
	if (map->tab_char[y][x] == '2')
		map->tab_char[y][x] = '?';
	if (map->tab_char[y][x] == '3')
		map->tab_char[y][x] = ':';
	if (map->tab_char[y][x] == '4')
		map->tab_char[y][x] = ';';
	if (map->tab_char[y][x] == '5')
		map->tab_char[y][x] = '+';
	return (map);
}
