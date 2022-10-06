/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 01:07:07 by revieira          #+#    #+#             */
/*   Updated: 2022/10/06 23:32:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		i;

	if (!s)
		return (0);
	cpy = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!cpy)
		return (0);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	start;
	size_t	len;
	size_t	i;

	i = ft_strlen(dest);
	if (size < i || (dest[0] == '\0' && size == 0))
		return (ft_strlen(src) + size);
	len = i + ft_strlen(src);
	start = 0;
	while (i < size - 1 && src[start] != '\0')
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[i] = '\0';
	ft_strlcat(str, s2, len);
	free((char *)s1);
	return (str);
}

int	ft_strchr_mod(char *s)
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
