/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suprr_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:51:08 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/02 10:56:21 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_suppr_char(char *str, int x)
{
	int		i;
	char	*first;
	char	*second;
	char	*retour;

	i = 0;
	if (x > (int)ft_strlen(str))
		return (NULL);
	if (!(first = malloc(sizeof(char) * (x + 1))))
		return (NULL);
	while (i < x)
	{
		first[i] = str[i];
		i++;
	}
	first[i] = '\0';
	if (!(second = ft_substr(str, x + 1, (int)ft_strlen(str) - x)))
		return (NULL);
	if (!(retour = ft_strjoin(first, second)))
		return (NULL);
	free(second);
	free(str);
	return (retour);
}
