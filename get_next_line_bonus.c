/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:47:32 by revieira          #+#    #+#             */
/*   Updated: 2022/10/06 23:31:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_newline(char *rest)
{
	char	*new_line;
	int		i;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		new_line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		new_line[i] = rest[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*save_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if ((rest[i] == '\n' && rest[i + 1] == '\0') || !rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = (char *)malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!new_rest)
		return (NULL);
	j = 0;
	while (rest[++i] != '\0')
		new_rest[j++] = rest[i];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

static char	*fd_read(int fd, char *rest)
{
	char	*buf;
	int		chars_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	chars_read = 1;
	while (!(ft_strchr_mod(rest)))
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (chars_read <= 0)
			break ;
		buf[chars_read] = '\0';
		rest = ft_strjoin(rest, buf);
		if (!rest)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (chars_read == -1)
		return (0);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = fd_read(fd, rest[fd]);
	if (!(ft_strlen(rest[fd])))
	{
		free(rest[fd]);
		return (NULL);
	}
	else
	{
		line = extract_newline(rest[fd]);
		rest[fd] = save_rest(rest[fd]);
	}
	return (line);
}
