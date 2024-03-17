/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:34:43 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/09 13:34:15 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (result - len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*result;
	char	*tmp_str;

	tmp_str = (char *)str;
	result = (char *)malloc(ft_strlen(str) + 1);
	if (!result)
		return (0);
	while (*tmp_str)
		*result++ = *tmp_str++;
	*result = '\0';
	return (result - ft_strlen(str));
}

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!len || ft_strlen(src) <= start)
		return (ft_strdup(""));
	if (ft_strlen(src) < start + len)
		len = ft_strlen(src) - start + 1;
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	src = src + start;
	while (i < len && src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
