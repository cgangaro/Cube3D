/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suppr_char_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:31:31 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/15 16:35:27 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_suppr_char_tab_2(char **tab, char **new_tab, int sens)
{
	int i;

	i = 0;
	if (sens == 0)
	{
		while (tab[i + 1] != NULL)
		{
			if (!(new_tab[i] = ft_substr(tab[i + 1], 0, ft_strlen(tab[i + 1]))))
				return (NULL);
			i++;
		}
		new_tab[i] = NULL;
	}
	else if (sens == 1)
	{
		while (tab[i + 1] != NULL)
		{
			if (!(new_tab[i] = ft_substr(tab[i], 0, ft_strlen(tab[i + 1]))))
				return (NULL);
			i++;
		}
		new_tab[i] = NULL;
	}
	return (new_tab);
}

char	**ft_suppr_char_tab(char **tab, int sens)
{
	int y;
	int i;
	char **new_tab;

	i = 0;
	y = 0;
	while (tab[i] != NULL)
		i++;
	if (i < 2 || sens < 0 || sens > 1)
		return (NULL);
	if (!( new_tab = malloc(sizeof(char *) * i)))
		return (NULL);
	if (!(new_tab = ft_suppr_char_tab_2(tab, new_tab, sens)))
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (new_tab);
}