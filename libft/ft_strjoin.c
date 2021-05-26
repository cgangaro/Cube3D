/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:41:31 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 16:01:47 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*retour;
	int		taille;

	if (!s1 || !s2)
		return (0);
	taille = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = 0;
	y = 0;
	if (!(retour = malloc(sizeof(char) * (taille + 1))))
		return (0);
	while (s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		retour[i] = s2[y];
		i++;
		y++;
	}
	retour[i] = '\0';
	return (retour);
}
