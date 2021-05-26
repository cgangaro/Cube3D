/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:46:57 by cgangaro          #+#    #+#             */
/*   Updated: 2020/12/09 14:39:50 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	int				i;

	a = b;
	i = 0;
	while (len > 0)
	{
		a[i] = c;
		i++;
		len--;
	}
	return (a);
}
