/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:32:26 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/25 14:41:02 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*retour;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(retour = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	retour[i] = '\0';
	return (retour);
}
