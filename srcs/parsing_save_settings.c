/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_save_settings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:11:51 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 16:18:24 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_save_settings(char *line, t_map *map)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	if (line[i] == 'R')
		if (!(map == parsing_resolution(line, map)))
			return (NULL);
	if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W'
		|| line [i] == 'S' || line [i] == 'M' || line [i] == 'U')
		if (!(map == parsing_texture(line, map, line[i], line[i + 1])))
			return (NULL);
	if (line[i] == 'F')
		if (!(map == parsing_color_f(line, map)))
			return (NULL);
	if (line[i] == 'C')
		if (!(map == parsing_color_c(line, map)))
			return (NULL);
	return (map);
}

char	*parsing_trim_setting(char *line, int mode)
{
	int		i;
	int		y;
	char	*param;

	i = 0;
	while (line[i] == ' ' || line[i] == ',' || line[i] == 'R' || line[i] == 'N'
		|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E' || line[i] == 'F'
		|| line[i] == 'C' || line[i] == 'O' || line[i] == 'A' || line[i] == 'M'
		|| line[i] == 'U')
		i++;
	y = i;
	while (line[y] >= 32 && line[y] <= 126 && line[y] != ' ')
		y++;
	param = ft_substr(line, i, y - i);
	if (!param)
		return (NULL);
	if (mode == 1)
		return (param);
	free (param);
	return (parsing_trim_setting_2(line, y, i));
}

char	*parsing_trim_setting_2(char *line, int y, int i)
{
	char	*param;

	while (line[y] == ' ')
		y++;
	while (line[y] >= 32 && line[y] <= 126 && line[y] != ' ')
		y++;
	param = ft_substr(line, i, y - i);
	if (!param)
		return (NULL);
	return (param);
}

t_map	*parsing_resolution(char *line, t_map *map)
{
	char	*param;
	char	*nbr;

	if (map->r_x != -1 || map->r_y != -1)
	{
		map->error = "Erreur: doublons dans les parametres";
		return (map);
	}
	param = parsing_trim_setting(line, 2);
	if (!param)
		return (NULL);
	nbr = ft_substr(param, 0, ft_search(param, ' ', 0));
	if (!nbr)
		return (NULL);
	map->r_x = ft_atoi(nbr);
	free (nbr);
	return (parsing_resolution_2(map, param));
}

t_map	*parsing_resolution_2(t_map *map, char *param)
{
	char	*nbr;

	nbr = ft_substr(param, ft_search(param, ' ', 1) + 1, ft_strlen(param)
			- ft_search(param, ' ', 1) + 1);
	if (!nbr)
		return (NULL);
	free(param);
	map->r_y = ft_atoi(nbr);
	free(nbr);
	if (map->r_y <= 0 || map->r_x <= 0)
		map->error = "Erreur: resolution incorrect";
	return (map);
}
