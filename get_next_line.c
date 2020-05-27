/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 14:53:20 by mskinner          #+#    #+#             */
/*   Updated: 2020/05/27 11:46:21 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_free(char **str, char **line)
{
	if (str)
	{
		if (*str)
		{
			free(*str);
			*str = 00;
		}
	}
	if (line)
		if (*line)
			*line = 00;
	return (-1);
}

static int	ft_get_line_buff(char **str, char **line)
{
	char *tmp;

	tmp = ft_strchr(*str, 10);
	*tmp++ = '\0';
	*line = *str;
	*str = 00;
	if (!(*str = ft_strdup(tmp)))
		return (-1);
	return (1);
}

static int	ft_get_line_tail(char **str, char **line)
{
	if (*str)
	{
		if (ft_strchr(*str, 10))
			return (ft_get_line_buff(str, line));
		*line = *str;
		*str = 00;
		return (0);
	}
	if (!(*line = ft_strdup("")))
		return (ft_free(str, line));
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*str;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	ssize_t		readed_bytes;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (-1);
	if (read(fd, buff, 0) < 0)
		return (-1);
	readed_bytes = 0;
	while ((readed_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readed_bytes] = '\0';
		if (!(tmp = ft_strjoin(str, buff)))
			return (ft_free(&str, line));
		if (str)
			free(str);
		str = tmp;
		if (ft_strchr(str, 10))
			return (ft_get_line_buff(&str, line));
	}
	if (readed_bytes < 0)
		return (ft_free(&str, line));
	return (ft_get_line_tail(&str, line));
}
