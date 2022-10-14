/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:16:20 by revieira          #+#    #+#             */
/*   Updated: 2022/10/14 12:35:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = "";
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = "";
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
