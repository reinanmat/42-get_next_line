/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:58:39 by coder             #+#    #+#             */
/*   Updated: 2022/10/08 01:29:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	ssize_t	chars_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	chars_read = 1;
	while (!(ft_strchr_n(rest)))
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
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	rest = fd_read(fd, rest);
	if (!(ft_strlen(rest)))
	{
		free(rest);
		return (NULL);
	}
	else
	{
		line = extract_newline(rest);
		rest = save_rest(rest);
	}
	return (line);
}
/*
int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		line = "";
	}
	//line = get_next_line(fd);
	//printf("%s", line);
	//line = get_next_line(fd);
	//printf("%s", line);
	close(fd);
	return (0);
}*/
