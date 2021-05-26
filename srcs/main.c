/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:07:36 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 14:07:19 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*nom_map;
	t_cube	cube;

	cube.save = 0;
	nom_map = arg_error(argc, argv);
	map = malloc(sizeof(t_map));
	if (!map)
		return (-1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (-1);
	map = init_struct(map);
	map = parsing(nom_map, map);
	if (map->error != NULL)
		return (error_parsing(map));
	cube = init_main(cube, *map);
	cube.map = *map;
	cube = init_main_2(&cube);
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
		cube.save = 1;
	cube = first(&cube);
	mlx_loop(cube.mlx.id);
	return (0);
}

t_map	*init_struct(t_map *map)
{
	map->r_x = -1;
	map->r_y = -1;
	map->text_no = NULL;
	map->text_so = NULL;
	map->text_we = NULL;
	map->text_ea = NULL;
	map->text_sp = NULL;
	map->text_me = NULL;
	map->text_up = NULL;
	map->f_1 = -1;
	map->f_2 = -1;
	map->f_3 = -1;
	map->c_1 = -1;
	map->c_2 = -1;
	map->c_3 = -1;
	map->error = NULL;
	map->end_parametres = 0;
	map->tab_char = NULL;
	map->taille_tab = 0;
	map->spawn_x = -1;
	map->spawn_y = -1;
	map->spawn_dir = 0;
	return (map);
}

char	*arg_error(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_1("Erreur : nombre d'arguments erroné\n");
		exit(-1);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) > 0)
	{
		ft_putstr_1("Erreur : vous devez entrer le nom du fichier map\n");
		exit(-1);
	}
	arg_error_name_file(argv);
	return (argv[1]);
}

void	arg_error_name_file(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]);
	if (i < 5)
	{
		ft_putstr_1("Erreur : fichier de configuration invalide\n");
		ft_putstr_1("\"*.cub\"\n");
		exit(-1);
	}
	if (argv[1][i - 1] != 'b' || argv[1][i - 2] != 'u'
		|| argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
	{
		ft_putstr_1("Erreur : fichier de configuration invalide\n");
		ft_putstr_1("\"*.cub\"\n");
		exit(-1);
	}
}
