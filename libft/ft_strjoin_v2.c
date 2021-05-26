/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:00:54 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/02 10:01:03 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_v2(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*retour;
	int		taille;

	taille = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	y = 0;
	if (!(retour = malloc(sizeof(char) * (taille + 1))))
		return (0);
	while (s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	while (s2[y] && s2 != NULL)
	{
		retour[i] = s2[y];
		i++;
		y++;
	}
	retour[i] = '\0';
	free(s1);
	return (retour);
}