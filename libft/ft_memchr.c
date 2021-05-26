/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:26:40 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/24 15:00:15 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*src;

	src = s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (char)c)
			return (src + i);
		i++;
	}
	return (0);
}
