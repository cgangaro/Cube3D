/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tab_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:11:19 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/06 14:17:19 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_tab_char(char *line, int fd, int ret_get, t_map *map)
{
	int		i;

	i = 1;
	while (ret_get == 1 && parsing_start_map(line) != 1)
	{
		free (line);
		ret_get = get_next_line(fd, &line);
	}
	free (line);
	if (ret_get == 0)
	{
		map->error = "Erreur: pas de map";
		return (map);
	}
	map = parsing_tab_char_2(line, fd, ret_get, map);
	if (!map)
		return (NULL);
	return (parsing_tab_char_3(line, fd, ret_get, map));
}

t_map	*parsing_tab_char_2(char *line, int fd, int ret_get, t_map *map)
{
	int		taille_map;

	taille_map = 2;
	ret_get = get_next_line(fd, &line);
	while (ret_get == 1)
	{
		free (line);
		taille_map++;
		ret_get = get_next_line(fd, &line);
	}
	free (line);
	if (close(fd) == -1)
		return (NULL);
	map->tab_char = malloc(sizeof(char **) * (taille_map + 1));
	if (!map->tab_char)
		return (NULL);
	return (map);
}

t_map	*parsing_tab_char_3(char *line, int fd, int ret_get, t_map *map)
{
	fd = open(map->nom_fichier, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret_get = get_next_line(fd, &line);
	while (parsing_start_map(line) != 1)
	{
		free (line);
		ret_get = get_next_line(fd, &line);
	}
	map->tab_char[0] = ft_substr(line, 0, ft_strlen(line));
	if (!map->tab_char[0])
		return (NULL);
	free (line);
	return (parsing_tab_char_4(line, fd, ret_get, map));
}

t_map	*parsing_tab_char_4(char *line, int fd, int ret_get, t_map *map)
{
	int	i;

	i = 1;
	ret_get = get_next_line(fd, &line);
	while (ret_get == 1)
	{
		map->tab_char[i] = ft_substr(line, 0, ft_strlen(line));
		if (!map->tab_char[i])
			return (NULL);
		free (line);
		i++;
		ret_get = get_next_line(fd, &line);
	}
	map->tab_char[i] = ft_substr(line, 0, ft_strlen(line));
	if (!map->tab_char[i])
		return (NULL);
	free (line);
	map->tab_char[i + 1] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (map);
}
