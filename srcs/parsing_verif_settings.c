/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verif_settings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:52:25 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 13:45:46 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	parsing_verif_parametres_R(char *line, t_map *map, int i)
{
	int	r_1;
	int	r_2;
	int	ret;

	i++;
	r_1 = 0;
	r_2 = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] >= 48 && line[i] <= 57)
	{
		i++;
		r_1 = 1;
	}
	ret = parsing_verif_parametres_R_2(line, i, r_1, r_2);
	if (ret == -1)
	{
		map->error = "Erreur: parametre(s) manquant(s), mauvaise resolution";
		return (-1);
	}
	return (0);
}

int	parsing_verif_parametres_R_2(char *line, int i, int r_1, int r_2)
{
	while (line[i] == ' ')
		i++;
	while (line[i] >= 48 && line[i] <= 57)
	{
		i++;
		r_2 = 1;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0' || r_1 == 0 || r_2 == 0)
		return (-1);
	return (0);
}

int	parsing_verif_all_parametres(t_map *map)
{
	if (map->r_x == -1 || map->r_y == -1 || map->text_no == NULL
		|| map->text_so == NULL || map->text_we == NULL || map->text_ea == NULL
		|| map->text_sp == NULL || map->c_1 == -1 || map->c_2 == -1
		|| map->c_3 == -1 || map->f_1 == -1 || map->f_2 == -1 || map->f_3 == -1
		|| map->text_me == NULL || map->text_up == NULL)
	{
		map->error = "Erreur: parametre(s) manquant(s)";
		return (-1);
	}
	return (0);
}

int	parsing_verif_parametres(char *line, t_map *map)
{
	int	i;

	i = 0;
	if (map->error != NULL)
		return (-1);
	while (line[i] == ' ')
		i++;
	if (!(line[i] == 'R' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E' || line[i] == 'F' || line[i] == 'C'
			|| line[i] == 'M' || line[i] == 'U'))
	{
		map->error = "Erreur: le fichier est mal configuré";
		return (-1);
	}
	if (line[i] == 'R')
		return (parsing_verif_parametres_R(line, map, i));
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'S' || line[i] == 'M' || line[i] == 'U')
		return (parsing_verif_parametres_textures(line, map, i));
	if (line[i] == 'F' || line[i] == 'C')
		return (parsing_verif_parametres_colors(line, map, i));
	map->error = "Erreur: le fichier est mal configuré";
	return (-1);
}
