/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:05:37 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 15:43:23 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	i = 0;
	if (!s)
		return (0);
	if (!(s2 = ft_strdup(s)))
		return (0);
	while (s2[i])
	{
		s2[i] = (*f)(i, s2[i]);
		i++;
	}
	return (s2);
}
