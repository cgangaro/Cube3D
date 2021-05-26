/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:02:51 by cgangaro          #+#    #+#             */
/*   Updated: 2021/05/17 14:36:32 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	header_bmp(t_cube *cube, unsigned char **img_bmp, int size)
{
	(*img_bmp)[0] = (unsigned char)('B');
	(*img_bmp)[1] = (unsigned char)('M');
	(*img_bmp)[2] = (unsigned char)(size);
	(*img_bmp)[3] = (unsigned char)(size >> 8);
	(*img_bmp)[4] = (unsigned char)(size >> 16);
	(*img_bmp)[5] = (unsigned char)(size >> 24);
	(*img_bmp)[10] = (unsigned char)(54);
	(*img_bmp)[0 + 14] = (unsigned char)(40);
	(*img_bmp)[4 + 14] = (unsigned char)(cube->map.r_x >> 0);
	(*img_bmp)[5 + 14] = (unsigned char)(cube->map.r_x >> 8);
	(*img_bmp)[6 + 14] = (unsigned char)(cube->map.r_x >> 16);
	(*img_bmp)[7 + 14] = (unsigned char)(cube->map.r_x >> 24);
	(*img_bmp)[8 + 14] = (unsigned char)(cube->map.r_y >> 0);
	(*img_bmp)[9 + 14] = (unsigned char)(cube->map.r_y >> 8);
	(*img_bmp)[10 + 14] = (unsigned char)(cube->map.r_y >> 16);
	(*img_bmp)[11 + 14] = (unsigned char)(cube->map.r_y >> 24);
	(*img_bmp)[12 + 14] = (unsigned char)(1);
	(*img_bmp)[14 + 14] = (unsigned char)(cube->img.bits_per_pixel);
}

void	copy_img_to_bmp(t_cube *cube, unsigned char **img_bmp)
{
	int	x_img;
	int	y_img;
	int	i_bmp;

	i_bmp = 54;
	y_img = cube->map.r_y - 1;
	while (y_img >= 0)
	{
		x_img = 0;
		while (x_img < cube->map.r_x)
		{
			(*img_bmp)[i_bmp++] = (cube->img.addr_int[y_img * \
				cube->img.line_length + x_img]);
			(*img_bmp)[i_bmp++] = (cube->img.addr_int[y_img * \
				cube->img.line_length + x_img] >> 8);
			(*img_bmp)[i_bmp++] = (cube->img.addr_int[y_img * \
				cube->img.line_length + x_img] >> 16);
			(*img_bmp)[i_bmp++] = (cube->img.addr_int[y_img * \
				cube->img.line_length + x_img] >> 24);
			x_img++;
		}
		y_img--;
	}
}

int	screen_shoot(t_cube *cube)
{
	unsigned char	*img_bmp;
	int				fd;
	int				size;

	size = 54 + 4 * cube->map.r_y * cube->map.r_x;
	img_bmp = ft_calloc(size, sizeof(unsigned char));
	if (!img_bmp)
		return (-1);
	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0700);
	if (fd == -1)
	{
		ft_putstr_1("Erreur : erreur dans la création du fichier bitmap\n");
		quit(cube, -1);
	}
	header_bmp(cube, &img_bmp, size);
	copy_img_to_bmp(cube, &img_bmp);
	write(fd, img_bmp, size);
	free(img_bmp);
	quit(cube, 1);
	return (0);
}
