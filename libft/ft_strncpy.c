/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 09:40:17 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/22 13:51:08 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, char c)
{
	int		i;
	char	*retour;

	i = 0;
	printf("s1 = |%s|\n", s1);
	printf("11\n");
	while (s1[i] != c && s1[i])
		i++;
	printf("12\n");
	printf("i = %d\n", i);
	if (!(retour = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	printf("13\n");
	printf("14\n");
	i = 0;
	printf("15\n");
	while (s1[i] != c && s1[i])
	{
		retour[i] = s1[i];
		i++;
	}
	printf("16\n");
	retour[i] = '\0';
	printf("16.5\n");
	return (retour);
}