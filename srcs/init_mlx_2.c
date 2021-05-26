/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:51:26 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 15:02:12 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_cube	*init_mlx_and_text_5(t_cube *cube)
{
	cube->text_up.text.img = mlx_xpm_file_to_image(
			cube->mlx.id, cube->map.text_up, &cube->text_up.width,
			&cube->text_up.height);
	if (cube->text_up.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	cube->text_up.text.addr_int = (int *)mlx_get_data_addr(
			cube->text_up.text.img, &cube->text_up.text.bits_per_pixel,
			&cube->text_up.text.line_length,
			&cube->text_up.text.endian);
	cube->text_up.text.line_length /= 4;
	cube->img_dead.text.img = mlx_xpm_file_to_image(
			cube->mlx.id, "./textures/gameover.xpm", &cube->img_dead.width,
			&cube->img_dead.height);
	if (cube->img_dead.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	return (cube);
}

t_cube	*init_mlx_and_text_6(t_cube *cube)
{
	cube->img_dead.text.addr_int = (int *)mlx_get_data_addr(
			cube->img_dead.text.img, &cube->img_dead.text.bits_per_pixel,
			&cube->img_dead.text.line_length,
			&cube->img_dead.text.endian);
	cube->img_dead.text.line_length /= 4;
	cube->img_end.text.img = mlx_xpm_file_to_image(
			cube->mlx.id, "./textures/end.xpm", &cube->img_end.width,
			&cube->img_end.height);
	if (cube->img_end.text.img == NULL)
	{
		ft_putstr_1("Erreur: fichier texture\n");
		quit(cube, -1);
	}
	cube->img_end.text.addr_int = (int *)mlx_get_data_addr(
			cube->img_end.text.img, &cube->img_end.text.bits_per_pixel,
			&cube->img_end.text.line_length,
			&cube->img_end.text.endian);
	cube->img_end.text.line_length /= 4;
	return (cube);
}
