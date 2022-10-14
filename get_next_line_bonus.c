/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:47:32 by revieira          #+#    #+#             */
/*   Updated: 2022/10/14 11:52:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_line_break(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}

char	*extract_new_line(char *rest)
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
		return (0);
	i = -1;
	while (rest[++i] && rest[i] != '\n')
		new_line[i] = rest[i];
	if (rest[i] == '\n')
	{
		new_line[i] = rest[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*extract_new_rest(char *rest)
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
		return (0);
	j = 0;
	while (rest[++i] != '\0')
		new_rest[j++] = rest[i];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

char	*fd_read(int fd, char *rest)
{
	char	*buf;
	int		chars_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	chars_read = 1;
	while (!(check_line_break(rest)))
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

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	rest[fd] = fd_read(fd, rest[fd]);
	if (!(ft_strlen(rest[fd])))
	{
		free(rest[fd]);
		return (NULL);
	}
	line = extract_new_line(rest[fd]);
	rest[fd] = extract_new_rest(rest[fd]);
	return (line);
}
