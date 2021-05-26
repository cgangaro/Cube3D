/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:52:47 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/24 14:51:38 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int			i;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		if (d[i] == (char)c)
			return (d + i + 1);
		n--;
		i++;
	}
	return (0);
}
