/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgangaro <cgangaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:29:49 by cgangaro          #+#    #+#             */
/*   Updated: 2021/02/25 11:32:56 by cgangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_get1(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int		verif(char **line, char **buff_mem)
{
	char	*temp;

	if (BUFFER_SIZE <= 0)
		return (-1);
	if (*buff_mem && ft_strchr_get1(*buff_mem, 10) != NULL)
	{
		if (!(*line = ft_strncpy_get1(*buff_mem, '\n')))
			return (-1);
		if (!(temp = ft_substr_get1(*buff_mem, '\n')))
			return (-1);
		*buff_mem = temp;
		return (1);
	}
	else if (*buff_mem == NULL)
	{
		if (!(*buff_mem = ft_zero_get1(NULL, 1)))
			return (-1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buff_temp[BUFFER_SIZE + 1];
	static char	*buff_mem;
	int			retread;
	int			v;

	*line = NULL;
	if ((v = verif(line, &buff_mem)))
		return (v);
	if (v == -1)
		return (-1);
	while ((retread = read(fd, buff_temp, BUFFER_SIZE)) != 0)
	{
		if (retread == -1)
			return (-1);
		buff_temp[retread] = '\0';
		if (!(buff_mem = ft_strjoin_get1(buff_mem, buff_temp)))
			return (-1);
		if ((v = verif(line, &buff_mem)))
			return (1);
		if (v == -1)
			return (-1);
	}
	*line = buff_mem;
	buff_mem = NULL;
	return (0);
}
