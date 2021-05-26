/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:21:38 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/24 15:57:00 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] != s2[i] && i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
