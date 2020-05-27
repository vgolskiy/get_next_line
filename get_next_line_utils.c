/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 14:57:36 by mskinner          #+#    #+#             */
/*   Updated: 2020/05/25 18:19:17 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (00);
}

static void		*ft_calloc(size_t num, size_t size)
{
	void	*res;
	char	*str;
	size_t	i;

	res = malloc(num * size);
	if (!res)
		return (00);
	i = 0;
	str = (char *)res;
	while (i < (num * size))
		str[i++] = '\0';
	return (res);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*dest;

	len = ft_strlen(src) + 1;
	dest = (char *)ft_calloc(len, sizeof(char));
	if (dest == 00)
		return (00);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if ((!s1) && (!s2))
		return (00);
	if ((!s1) && (s2))
		return (ft_strdup(s2));
	if (!(res = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char))))
		return (00);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}
