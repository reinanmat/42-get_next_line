/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:16:20 by revieira          #+#    #+#             */
/*   Updated: 2022/10/10 20:19:06 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		line = "";
	}
	close(fd);
	return (0);
}
