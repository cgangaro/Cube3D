/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:22:02 by cgangaro          #+#    #+#             */
/*   Updated: 2020/11/26 16:00:57 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*retour;

	if (!(retour = malloc(size * count)))
		return (0);
	ft_bzero(retour, count * size);
	return (retour);
}
