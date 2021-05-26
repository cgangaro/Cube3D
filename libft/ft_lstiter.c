/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:17:45 by cgangaro          #+#    #+#             */
/*   Updated: 2020/12/01 13:20:38 by cgangaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst->next)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
		(*f)(lst->content);
	}
}
