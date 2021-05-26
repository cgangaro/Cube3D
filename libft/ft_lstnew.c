/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:10:06 by cgangaro          #+#    #+#             */
/*   Updated: 2020/12/01 17:04:28 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	if (!(element = malloc((sizeof(t_list)))))
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
