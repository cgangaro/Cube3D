/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:50:56 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/25 11:32:45 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_get1(char *s1, char c)
{
	int		i;
	char	*retour;

	i = 0;
	while (s1[i] != c && s1[i])
		i++;
	if (!(retour = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != c && s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	retour[i] = '\0';
	return (retour);
}

char	*ft_substr_get1(char *s1, char c)
{
	int		i;
	int		y;
	char	*retour;

	i = 0;
	y = 0;
	while (s1[i] != c && s1[i])
		i++;
	if (s1[i] == c && s1[i])
		i++;
	if (!(retour = malloc(sizeof(char) * (ft_strlen_get1(s1 + i) + 1))))
		return (NULL);
	while (s1[i])
	{
		retour[y] = s1[i];
		i++;
		y++;
	}
	retour[y] = '\0';
	free(s1);
	return (retour);
}

char	*ft_zero_get1(char *s, int n)
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

char	*ft_strjoin_get1(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*retour;
	int		taille;

	taille = ft_strlen_get1(s1) + ft_strlen_get1(s2);
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

char	*ft_strchr_get1(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == 0 && s[i] == '\0')
		return ((char *)s + i);
	return (0);
}
