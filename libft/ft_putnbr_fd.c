/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:33:56 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 15:41:53 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd((nb - (nb % 10)) / 10, fd);
		if (nb >= 10)
		{
			nb = nb % 10;
		}
	}
	c = nb + 48;
	ft_putchar_fd(c, fd);
}
