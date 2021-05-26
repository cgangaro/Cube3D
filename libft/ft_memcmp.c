/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:35:28 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/24 15:01:09 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned int	i;
	char			*src1;
	char			*src2;

	src1 = s1;
	src2 = s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)src1[i] != (unsigned char)src2[i])
			return ((unsigned char)src1[i] - (unsigned char)src2[i]);
		i++;
	}
	return (0);
}
