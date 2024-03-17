/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:36:41 by suhwpark          #+#    #+#             */
/*   Updated: 2022/12/12 20:50:11 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*remove_fd(t_list *list)
{
	free(list->curr->back_up);
	list->before->next = list->curr->next;
	if (list->tail == list->curr)
		list->tail = list->before;
	free(list->curr);
	(list->nod_count)--;
	if (!list->nod_count)
		list->tail = NULL;
	else
		list->curr = list->before->next;
	return (NULL);
}

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

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!len || ft_strlen(src) <= start)
	{
		res = (char *)malloc(1);
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
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
