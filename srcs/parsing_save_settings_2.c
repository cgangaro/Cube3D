/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_save_settings_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:31:34 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/12 16:26:07 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_texture(char *line, t_map *map, char c, char c2)
{
	if (c == 'N')
	{
		if (map->text_no != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_no = parsing_trim_setting(line, 1);
		if (!map->text_no)
			return (NULL);
		return (map);
	}
	if (c == 'S' && c2 == 'O')
	{
		if (map->text_so != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_so = parsing_trim_setting(line, 1);
		if (!map->text_so)
			return (NULL);
		return (map);
	}
	return (parsing_texture_2(line, map, c, c2));
}

t_map	*parsing_texture_2(char *line, t_map *map, char c, char c2)
{
	if (c == 'W')
	{
		if (map->text_we != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_we = parsing_trim_setting(line, 1);
		if (!map->text_we)
			return (NULL);
		return (map);
	}
	if (c == 'E')
	{
		if (map->text_ea != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_ea = parsing_trim_setting(line, 1);
		if (!map->text_ea)
			return (NULL);
		return (map);
	}
	return (parsing_texture_3(line, map, c, c2));
}

t_map	*parsing_texture_3(char *line, t_map *map, char c, char c2)
{
	if (c == 'S' && c2 != 'O')
	{
		if (map->text_sp != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_sp = parsing_trim_setting(line, 1);
		if (!map->text_sp)
			return (NULL);
		return (map);
	}
	if (c == 'M')
	{
		if (map->text_me != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_me = parsing_trim_setting(line, 1);
		if (!map->text_me)
			return (NULL);
		return (map);
	}
	return (parsing_texture_4(line, map, c));
}

t_map	*parsing_texture_4(char *line, t_map *map, char c)
{
	if (c == 'U')
	{
		if (map->text_up != NULL)
		{
			map->error = "Erreur: doublons dans les parametres";
			return (map);
		}
		map->text_up = parsing_trim_setting(line, 1);
		if (!map->text_up)
			return (NULL);
		return (map);
	}
	return (map);
}
