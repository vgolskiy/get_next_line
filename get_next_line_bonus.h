/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 14:55:37 by mskinner          #+#    #+#             */
/*   Updated: 2020/05/25 18:17:58 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# define MAX_OPEN_FILES 16400

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
int		get_next_line(int fd, char **line);

#endif
