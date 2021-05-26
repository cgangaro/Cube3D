/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_save_settings_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:28:55 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/06 14:51:09 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_map	*parsing_color_f(char *line, t_map *map)
{
	char	*param;
	char	*nbr;

	if (map->f_1 != -1 || map->f_2 != -1 || map->f_3 != -1)
	{
		map->error = "Erreur: doublons dans les parametres";
		return (map);
	}
	param = parsing_trim_setting(line, 1);
	if (!param)
		return (NULL);
	nbr = ft_substr(param, 0, ft_search(param, ',', 0));
	if (!nbr)
		return (NULL);
	map->f_1 = ft_atoi(nbr);
	free(nbr);
	return (parsing_color_f_2(map, param));
}

t_map	*parsing_color_f_2(t_map *map, char *param)
{
	char	*nbr;

	nbr = ft_substr(param, ft_search(param, ',', 0) + 1,
			ft_search(param, ',', 1) - (ft_search(param, ',', 0) + 1));
	if (!nbr)
		return (NULL);
	map->f_2 = ft_atoi(nbr);
	free(nbr);
	nbr = ft_substr(param, ft_search(param, ',', 1) + 1,
			ft_strlen(param) - (ft_search(param, ',', 1) + 1));
	if (!nbr)
		return (NULL);
	map->f_3 = ft_atoi(nbr);
	free(nbr);
	free(param);
	return (map);
}

t_map	*parsing_color_c(char *line, t_map *map)
{
	char	*param;
	char	*nbr;

	if (map->c_1 != -1 || map->c_2 != -1 || map->c_3 != -1)
	{
		map->error = "Erreur: doublons dans les parametres";
		return (map);
	}
	param = parsing_trim_setting(line, 1);
	if (!param)
		return (NULL);
	nbr = ft_substr(param, 0, ft_search(param, ',', 0));
	if (!nbr)
		return (NULL);
	map->c_1 = ft_atoi(nbr);
	free(nbr);
	return (parsing_color_c_2(map, param));
}

t_map	*parsing_color_c_2(t_map *map, char *param)
{
	char	*nbr;

	nbr = ft_substr(param, ft_search(param, ',', 0) + 1,
			ft_search(param, ',', 1) - (ft_search(param, ',', 0) + 1));
	if (!nbr)
		return (NULL);
	map->c_2 = ft_atoi(nbr);
	free(nbr);
	nbr = ft_substr(param, ft_search(param, ',', 1) + 1,
			ft_strlen(param) - (ft_search(param, ',', 1) + 1));
	if (!nbr)
		return (NULL);
	map->c_3 = ft_atoi(nbr);
	free(nbr);
	free(param);
	return (map);
}
