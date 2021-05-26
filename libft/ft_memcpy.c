/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:19:43 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/24 14:50:04 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	const char		*s;
	char			*d;

	s = src;
	d = dst;
	if (d == 0 && s == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
