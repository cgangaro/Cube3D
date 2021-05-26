/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:30:26 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 15:59:41 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing(char *nom_fichier, t_map *map)
{
	int		fd;
	int		ret_get;
	char	*line;

	map->nom_fichier = nom_fichier;
	fd = open(nom_fichier, O_RDONLY);
	if (fd == -1)
	{
		map->error = "Erreur : nom de fichier";
		return (map);
	}
	line = NULL;
	ret_get = get_next_line(fd, &line);
	while (ret_get == 1)
	{
		map = parsing_parametres(line, map);
		if (!map)
			return (NULL);
		if (map->end_parametres == 1)
			break ;
		else
			free (line);
		ret_get = get_next_line(fd, &line);
	}
	return (parsing_2(map, fd, ret_get, line));
}

t_map	*parsing_2(t_map *map, int fd, int ret_get, char *line)
{
	if (parsing_verif_all_parametres(map) == -1)
		return (map);
	map = parsing_tab_char(line, fd, ret_get, map);
	if (!map)
		return (NULL);
	map = parsing_map_verif(map);
	map = parsing_rectification_resolution(map);
	if (map->c_1 < 0 || map->c_1 > 255 || map->c_2 < 0
		|| map->c_2 > 255 || map->c_3 < 0 || map->c_3 > 255)
	{
		map->error = "Erreur : couleur du plafond";
		return (map);
	}
	if (map->f_1 < 0 || map->f_1 > 255 || map->f_2 < 0
		|| map->f_2 > 255 || map->f_3 < 0 || map->f_3 > 255)
	{
		map->error = "Erreur : couleur du sol";
		return (map);
	}
	return (map);
}

t_map	*parsing_parametres(char *line, t_map *map)
{	
	if (line[0] == 0)
	{
		return (map);
	}
	if (parsing_start_map(line))
	{
		map->end_parametres = 1;
		return (map);
	}
	if (parsing_verif_parametres(line, map) == -1)
		return (map);
	map = parsing_save_settings(line, map);
	if (!map)
		return (NULL);
	return (map);
}

int	parsing_start_map(char *line)
{
	int	i;

	i = 0;
	if (line[0] == 0)
		return (0);
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '0' || line[i] == '1'
			|| line[i] == '2' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E' || line[i] == 'M'
			|| line[i] == 'U'))
		i++;
	if (line[i] != '\0')
		return (0);
	return (1);
}

t_map	*parsing_rectification_resolution(t_map *map)
{
	int	i;
	int	j;

	if (map->r_x < 64 || map->r_y < 64)
	{
		map->error = "Erreur : resolution trop faible";
		return (map);
	}
	i = map->r_x % 64;
	j = map->r_x / 64;
	if (i > 32)
		map->r_x = (j + 1) * 64;
	else
		map->r_x = j * 64;
	return (map);
}
