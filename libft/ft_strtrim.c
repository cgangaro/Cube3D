/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:44:28 by cgangaro          #+#    #+#             */
/*   Updated: 2020/12/02 12:57:03 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_present(char const *set, char const s1)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (0);
		i++;
	}
	return (1);
}

static char	*chaine(int i, int y, char *str, char const *s1)
{
	int	k;

	k = 0;
	while (i <= y)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = 0;
	if (!s1)
		return (0);
	while (!ft_present(set, s1[i]))
		i++;
	y = ft_strlen((char *)s1) - 1;
	while (y > 0 && ft_present(set, s1[y]) == 0)
		y--;
	if (y <= i)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (0);
	}
	else if (!(str = malloc(sizeof(char) * (y - i + 2))))
		return (0);
	return (chaine(i, y, str, s1));
}
