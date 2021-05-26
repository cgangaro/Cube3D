/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_settings_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:37:50 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/11 10:09:31 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	parsing_verif_parametres_colors(char *line, t_map *map, int i)
{
	i++;
	while (line[i] == ' ')
		i++;
	while (line[i] >= 48 && line[i] <= 57)
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] >= 48 && line[i] <= 57)
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] >= 48 && line[i] <= 57)
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
	{
		map->error = "Erreur: le fichier est mal configuré";
		return (-1);
	}
	return (0);
}

int	parsing_verif_parametres_textures(char *line, t_map *map, int i)
{
	int	error;

	error = 0;
	if ((line[i] == 'N' && line[i + 1] != 'O')
		|| (line[i] == 'W' && line[i + 1] != 'E')
		|| (line[i] == 'E' && line[i + 1] != 'A'))
		error = 1;
	if ((line[i] == 'S' && line[i + 1] != 'O') || line[i] == 'M'
		|| line[i] == 'U')
		i++;
	else
		i = i + 2;
	while (line[i] == ' ')
		i++;
	return (parsing_verif_parametres_textures_2(line, map, i, error));
}

int	parsing_verif_parametres_textures_2(char *line, t_map *map,
	int i, int error)
{
	while (line[i] >= 32 && line[i] <= 126 && line[i] != '\\' && line[i] != ':'
		&& line[i] != '*' && line[i] != '"' && line[i] != '?' && line[i] != '<'
		&& line[i] != '>' && line[i] != '|' && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		error = 1;
	if (error)
	{
		map->error = "Erreur: le fichier est mal configuré";
		return (-1);
	}
	return (0);
}
