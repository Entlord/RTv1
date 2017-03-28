/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 13:19:56 by mlaize            #+#    #+#             */
/*   Updated: 2014/01/24 11:41:25 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_append_buffer(int fd, char **buffer)
{
	char	*tmp;
	int		len;

	tmp = ft_strnew(BUFF_SIZE + 1);
	ft_bzero(tmp, BUFF_SIZE + 1);
	len = read(fd, tmp, BUFF_SIZE);
	if (len == -1)
		return (len);
	ft_strealloc(buffer, BUFF_SIZE);
	ft_strcat(*buffer, tmp);
	free(tmp);
	return (len);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer = NULL;
	char		*str;
	int			len;

	len = BUFF_SIZE;
	while (ft_strchri(buffer, '\n') == -1 && len == BUFF_SIZE)
		len = ft_append_buffer(fd, &buffer);
	if (len == -1)
		return (-1);
	if (ft_strchri(buffer, '\n' != -1))
	{
		str = ft_strnew(ft_strchri(buffer, '\n'));
		ft_cutstr(str, buffer, '\n');
	}
	else
	{
		str = ft_strdup(buffer);
		ft_strclr(buffer);
	}
	*line = str;
	if (*buffer == 0 && len == 0)
		return (0);
	return (1);
}
