/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:24:55 by gshona            #+#    #+#             */
/*   Updated: 2020/11/20 00:23:42 by tenagrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_free(char **buff)
{
	if (*buff)
		free(*buff);
	*buff = NULL;
	return (-1);
}
/*
size_t				ft_strlen(const char *str)
{
	size_t len;

	if (!str)
		return (0);
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
*/
char				*ft_str_join(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*res;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	res[len1 + len2] = 0;
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	ft_free(&s1);
	while (i < len2)
	{
		res[i + len1] = s2[i];
		i++;
	}
	return (res);
}
/*
char				*ft_strdup(const char *str)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = 0;
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
*/
char				*ft_str_chr(char *str, int c)
{
	size_t		i;
	size_t		len;
	char		value;

	value = (char)c;
	len = ft_strlen(str);
	i = 0;
	while (i < len + 1)
	{
		if (str[i] == value)
		{
			str[i] = 0;
			return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
