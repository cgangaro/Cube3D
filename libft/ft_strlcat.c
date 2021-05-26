/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:22:43 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 16:00:22 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int y;

	i = 0;
	y = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (i < dstsize)
	{
		while (src[y] && (i + 1) < dstsize)
		{
			dst[i] = src[y];
			i++;
			y++;
		}
		dst[i] = 0;
	}
	while (src[y])
	{
		i++;
		y++;
	}
	return (i);
}
