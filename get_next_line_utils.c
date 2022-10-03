/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:30:27 by coder             #+#    #+#             */
/*   Updated: 2022/10/03 23:26:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	str[j] = '\0';
	ft_strlcat(str, s2, len);
	free((char *)s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (0);
	if (c == '\0')
		return (&((char *)s)[len]);
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return (&(((char *)s)[i]));
		i++;
	}
	return (0);
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
