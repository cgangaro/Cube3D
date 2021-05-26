/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:32:45 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 15:02:25 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cpt(int n)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_recursive(char *s, unsigned int nb, int i)
{
	if (nb >= 10)
	{
		s = ft_recursive(s, (nb - (nb % 10)) / 10, i - 1);
		if (nb >= 10)
		{
			nb = nb % 10;
		}
	}
	s[i] = nb + 48;
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				i;
	int				y;

	i = ft_cpt(n);
	y = 0;
	if (n < 0)
		y++;
	if (!(s = ft_calloc(sizeof(char), i + 1 + y)))
		return (0);
	if (n < 0)
	{
		s[0] = '-';
		nb = n * -1;
		i++;
	}
	else
	{
		nb = n;
	}
	s = ft_recursive(s, nb, i - 1);
	return (s);
}
