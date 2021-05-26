/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:57:46 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 16:03:57 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int i;

	if (!src)
		return (0);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (i < dstsize && src[i] == 0)
		return (i);
	while (src[i])
		i++;
	return (i);
}
