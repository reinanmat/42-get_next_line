/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:58:39 by coder             #+#    #+#             */
/*   Updated: 2022/10/03 23:29:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static int	check_strstatic(char *str_static)
{
	int	i;

	i = 0;
	while (str_static[i] != '\n')
		i++;
	if (str_static[i + 1] == '\0')
		return (0);
	else
		return (1);
}*/

static size_t	strlen_n(char *buf)
{
	size_t	count;

	count = 0;
	while (buf[count] != '\n')
		count++;
	return (count);
}

static char	*strjoin_n(char *line, char *buf)
{
	char	*new_str;
	size_t	size;
	int		i;
	int		j;

	size = strlen_n(buf) + ft_strlen(line) + 2;
	new_str = (char *)malloc(sizeof(char) * size);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i] != '\0')
		new_str[j++] = line[i++];
	i = 0;
	while (buf[i] != '\n')
		new_str[j++] = buf[i++];
	new_str[j++] = '\n'; 
	new_str[j] = '\0';
	return (new_str);
}

static char *save_rest(char *rest, char *buf)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	free(rest);
	while (buf[i] != '\n')
		i++;
	if (buf[i + 1] == '\0')
		return (ft_strdup(""));
	rest = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	while (buf[++i] != '\0')
		rest[j++] = buf[i];
	rest[j] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char *rest;
	char		*buf;
	char		*line;
	int			chars_read;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (0);
	if (!rest)
		rest = ft_strdup("");	
	line = ft_strdup(rest);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	chars_read = 1;

	while (chars_read != 0)
	{
		chars_read = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n'))
		{
			line = strjoin_n(line, buf);
			rest = save_rest(rest, buf);
			return (line);
		}
		line = ft_strjoin(line, buf);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = "";
	while ((line = get_next_line(fd)))
		printf("%s", line);
	/*line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);*/
	close(fd);
	return (0);
}
