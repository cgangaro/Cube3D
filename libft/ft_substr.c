/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:45:05 by cgangaro          #+#    #+#             */
/*   Updated: 2021/03/03 16:13:16 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_emptystring(void)
{
	char *retour;

	if (!(retour = malloc(sizeof(char) * 1)))
		return (NULL);
	retour[0] = '\0';
	return (retour);
}

char				*ft_annexe(void)
{
	char *retour;

	if (!(retour = malloc(sizeof(char))))
		return (NULL);
	retour[0] = 0;
	return (retour);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		y;
	char				*retour;

	if (!s)
		return (0);
	y = 0;
	i = 0;
	if (len == 0)
		return (ft_annexe());
	if (start >= ft_strlen((char *)s))
		return (ft_emptystring());
	while (i < start)
		i++;
	if (!(retour = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (y < len)
	{
		retour[y] = s[i];
		i++;
		y++;
	}
	retour[y] = '\0';
	return (retour);
}
