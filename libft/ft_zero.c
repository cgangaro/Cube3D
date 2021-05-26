/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:58:11 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/02 09:58:29 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_zero(char *s, int n)
{
	int		i;
	char	*retour;

	i = 0;
	if (s == NULL)
	{
		if (!(retour = malloc(sizeof(char) * n)))
			return (NULL);
		while (i < n)
		{
			retour[i] = '\0';
			i++;
		}
		return (retour);
	}
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}