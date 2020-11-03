/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:24:55 by gshona            #+#    #+#             */
/*   Updated: 2020/11/01 12:05:29 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

char			*ft_stralloc(size_t size)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * size + 1);
	res[size] = '\0';
	return (res);
}

static char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = ft_stralloc(len1 + len2);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		res[i + len1] = s2[i];
		i++;
	}
	return (res);
}

char			*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	res = ft_stralloc(len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

void			ft_strappend(char **str, char *append)
{
	char *res;

	if (!*str)
	{
		*str = ft_strdup(append);
		return ;
	}
	res = ft_strjoin(*str, append);
	if (*str)
		free(*str);
	*str = res;
}
