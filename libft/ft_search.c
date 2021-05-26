/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 09:38:21 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/04 13:11:03 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search(char *str, char c, int dir)
{
	int	i;

	if (dir == 0)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (i);
		return (-1);
	}
	else if (dir == 1)
	{
		i = ft_strlen(str) - 1;
		while (i >= 0 && str[i] != c)
			i--;
		if (str[i] == c)
			return (i);
		return (-1);
	}
	return (-1);
}
