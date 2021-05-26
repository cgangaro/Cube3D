/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:23:19 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 15:26:33 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	error_parsing(t_map *map)
{
	if (map->text_no != NULL)
		free(map->text_no);
	if (map->text_so != NULL)
		free(map->text_so);
	if (map->text_we != NULL)
		free(map->text_we);
	if (map->text_ea != NULL)
		free(map->text_ea);
	if (map->text_me != NULL)
		free(map->text_me);
	if (map->text_up != NULL)
		free(map->text_up);
	if (map->text_sp != NULL)
		free(map->text_sp);
	return (error_parsing_2(map));
}

int	error_parsing_2(t_map *map)
{
	int	i;

	i = 0;
	if (map->tab_char != NULL)
	{
		while (map->tab_char[i] != NULL)
		{
			free(map->tab_char[i]);
			i++;
		}
		free(map->tab_char);
	}
	ft_putstr_1(map->error);
	return (-1);
}

int	quit(t_cube *cube, int error)
{
	int	i;

	i = 0;
	quit_2(cube);
	if (cube->map.tab_char != NULL)
	{
		while (cube->map.tab_char[i] != NULL)
		{
			free(cube->map.tab_char[i]);
			i++;
		}
		free(cube->map.tab_char);
	}
	if (cube->sound == 1)
		system("killall afplay");
	if (error == -1)
		exit(-1);
	if (error == 0)
		exit(0);
	exit(1);
}

void	quit_2(t_cube *cube)
{
	if (cube->map.text_no != NULL)
		free(cube->map.text_no);
	if (cube->map.text_so != NULL)
		free(cube->map.text_so);
	if (cube->map.text_we != NULL)
		free(cube->map.text_we);
	if (cube->map.text_ea != NULL)
		free(cube->map.text_ea);
	if (cube->map.text_me != NULL)
		free(cube->map.text_me);
	if (cube->map.text_up != NULL)
		free(cube->map.text_up);
	if (cube->map.text_sp != NULL)
		free(cube->map.text_sp);
}
