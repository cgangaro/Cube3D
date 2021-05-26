/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:34:53 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/24 15:21:20 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			l;
	char		*d;
	const char	*s;

	l = len;
	d = dst;
	s = src;
	if (dst < src)
	{
		l = 0;
		while (l < (int)len)
		{
			d[l] = s[l];
			l++;
		}
	}
	else if (dst > src)
		while (l-- > 0)
			d[l] = s[l];
	return (d);
}
