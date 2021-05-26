/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_verif.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:18:04 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 15:36:05 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_map_verif(t_map *map)
{
	if (map->tab_char == NULL)
	{
		map->error = "Erreur : erreur de configuration de la map";
		return (map);
	}
	while (map->tab_char[map->taille_tab] != NULL)
		map->taille_tab++;
	if (map->taille_tab < 3)
	{
		map->error = "Erreur : erreur de configuration de la map";
		return (map);
	}
	map->start = 0;
	map = parsing_map_verif_caracteres(map);
	map = parsing_spawn(map);
	map = parsing_verif_close(map, map->spawn_x, map->spawn_y);
	if (map->error != NULL)
		return (map);
	map = parsing_opti_map(map);
	if (!map)
		return (NULL);
	return (map);
}

t_map	*parsing_map_verif_caracteres(t_map *map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map->tab_char[i] != NULL)
	{
		if (map->tab_char[i][0] == '\n' || map->tab_char[i][0] == 0)
		{
			map->error = "Erreur : ligne vide dans map";
			return (map);
		}
		while (map->tab_char[i][y] != 0)
		{
			map = parsing_map_verif_caracteres_2(map, i, y);
			if (map->error != NULL)
				return (map);
			y++;
		}
		y = 0;
		i++;
	}
	if (map->start == 0)
		map->error = "Erreur : pas de spawn dans la map";
	return (map);
}

t_map	*parsing_map_verif_caracteres_2(t_map *map, int i, int y)
{
	if (!(map->tab_char[i][y] == '0' || map->tab_char[i][y] == '1' ||
		map->tab_char[i][y] == '2' || map->tab_char[i][y] == 'N' ||
		map->tab_char[i][y] == 'S' || map->tab_char[i][y] == 'W' ||
		map->tab_char[i][y] == 'E' || map->tab_char[i][y] == ' ' ||
		map->tab_char[i][y] == '3' || map->tab_char[i][y] == '4' ||
		map->tab_char[i][y] == '5'))
	{
		map->error = "Erreur : caractere interdit dans la map";
		return (map);
	}
	if ((map->tab_char[i][y] == 'N' || map->tab_char[i][y] == 'S'
		|| map->tab_char[i][y] == 'W' || map->tab_char[i][y] == 'E')
		&& map->start == 1)
	{
		map->error = "Erreur : deux spawns dans la map";
		return (map);
	}
	if (map->tab_char[i][y] == 'N' || map->tab_char[i][y] == 'S'
		|| map->tab_char[i][y] == 'W' || map->tab_char[i][y] == 'E')
		map->start = 1;
	return (map);
}

t_map	*parsing_spawn(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->tab_char[y] != NULL)
	{
		while (map->tab_char[y][x] != 0)
		{
			if (map->tab_char[y][x] == 'N' || map->tab_char[y][x] == 'S' ||
			map->tab_char[y][x] == 'W' || map->tab_char[y][x] == 'E')
			{
				map->spawn_x = x;
				map->spawn_y = y;
				map->spawn_dir = map->tab_char[y][x];
				return (map);
			}
			x++;
		}
		y++;
		x = 0;
	}
	map->error = "Erreur : pas de spawn";
	return (map);
}
