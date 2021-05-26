/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:51:15 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 15:01:59 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*init_mlx_and_text(t_cube *cube)
{
	cube->mlx.id = mlx_init();
	if (!cube->mlx.id)
	{
		ft_putstr_1("Erreur: problème d'initialisation de la mlx\n");
		quit(cube, -1);
	}
	cube = init_screen_size(cube);
	cube->wind.id = mlx_new_window(cube->mlx.id, cube->map.r_x,
			cube->map.r_y, "Cube3D");
	cube->text_no.text.img = mlx_xpm_file_to_image(cube->mlx.id,
			cube->map.text_no, &cube->text_no.width, &cube->text_no.height);
	if (cube->text_no.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	cube = init_mlx_and_text_2(cube);
	cube = init_mlx_and_text_3(cube);
	cube = init_mlx_and_text_4(cube);
	cube = init_mlx_and_text_5(cube);
	cube = init_mlx_and_text_6(cube);
	return (cube);
}

t_cube	*init_mlx_and_text_2(t_cube *cube)
{
	cube->text_no.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_no.text.img, &cube->text_no.text.bits_per_pixel,
			&cube->text_no.text.line_length, &cube->text_no.text.endian);
	cube->text_no.text.line_length /= 4;
	cube->text_so.text.img = mlx_xpm_file_to_image(cube->mlx.id,
			cube->map.text_so, &cube->text_so.width, &cube->text_so.height);
	if (cube->text_so.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	cube->text_so.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_so.text.img, &cube->text_so.text.bits_per_pixel,
			&cube->text_so.text.line_length, &cube->text_so.text.endian);
	cube->text_so.text.line_length /= 4;
	cube->text_we.text.img = mlx_xpm_file_to_image(cube->mlx.id,
			cube->map.text_we, &cube->text_we.width, &cube->text_we.height);
	if (cube->text_we.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	return (cube);
}

t_cube	*init_mlx_and_text_3(t_cube *cube)
{
	cube->text_we.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_we.text.img, &cube->text_we.text.bits_per_pixel,
			&cube->text_we.text.line_length, &cube->text_we.text.endian);
	cube->text_we.text.line_length /= 4;
	cube->text_ea.text.img = mlx_xpm_file_to_image(cube->mlx.id,
			cube->map.text_ea, &cube->text_ea.width, &cube->text_ea.height);
	if (cube->text_ea.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	cube->text_ea.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_ea.text.img, &cube->text_ea.text.bits_per_pixel,
			&cube->text_ea.text.line_length, &cube->text_ea.text.endian);
	cube->text_ea.text.line_length /= 4;
	cube->text_sprite.text.img = mlx_xpm_file_to_image(
			cube->mlx.id, cube->map.text_sp, &cube->text_sprite.width,
			&cube->text_sprite.height);
	if (cube->text_sprite.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	return (cube);
}

t_cube	*init_mlx_and_text_4(t_cube *cube)
{
	cube->text_sprite.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_sprite.text.img, &cube->text_sprite.text.bits_per_pixel,
			&cube->text_sprite.text.line_length,
			&cube->text_sprite.text.endian);
	cube->text_sprite.text.line_length /= 4;
	cube->text_me.text.img = mlx_xpm_file_to_image(
			cube->mlx.id, cube->map.text_me, &cube->text_me.width,
			&cube->text_me.height);
	if (cube->text_me.text.img == NULL)
	{
		printf("1\n");
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	cube->text_me.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_me.text.img, &cube->text_me.text.bits_per_pixel,
			&cube->text_me.text.line_length,
			&cube->text_me.text.endian);
	cube->text_me.text.line_length /= 4;
	return (cube);
}
