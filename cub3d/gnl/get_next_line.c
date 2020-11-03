/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:46:44 by gshona            #+#    #+#             */
/*   Updated: 2020/11/03 12:09:54 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strchr(const char *str, int c)
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
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

static char		*ft_strextract(const char *str, size_t start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(str);
	if (!str || len > len_s)
		return (NULL);
	res = ft_stralloc(len);
	if (!res)
		return (NULL);
	i = start;
	while (i < start + len && str[i] != '\0')
	{
		res[i - start] = str[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}

static t_list_fd	*get_curr_rem(int fd, t_list_fd **remains)
{
	t_list_fd	*p;

	p = *remains;
	while (p)
	{
		if ((int)p->fd == fd)
			return (p);
		p = p->next;
	}
	p = (t_list_fd*)malloc(sizeof(t_list_fd));
	if (!p)
		return (NULL);
	p->content = (void*)ft_strdup("\0");
	p->fd = fd;
	p->next = (*remains) ? *remains : NULL;
	*remains = p;
	return (p);
}

static int		get_remained_line(t_list_fd *remain, char **line, int trunc)
{
	int		end_pos;
	size_t	rem_len;
	char	*tmp;
	char	*res;

	tmp = ft_strchr((char *)remain->content, '\n');
	end_pos = (!tmp) ? -1 : tmp - ((char *)remain->content);
	if (end_pos == -1)
	{
		if (trunc)
		{
			*line = (char *)remain->content;
			remain->content = (void *)ft_strdup("\0");
			return (1);
		}
		else
			return (0);
	}
	tmp = (char *)remain->content;
	rem_len = ft_strlen(tmp);
	res = ft_strextract(tmp, 0, end_pos);
	remain->content = ft_strdup(tmp + end_pos + 1);
	free(tmp);
	*line = res;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static t_list_fd	*remains;
	t_list_fd			*curr_rem;
	int				readed;
	int				f;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	curr_rem = get_curr_rem(fd, &remains);
	while ((readed = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readed] = '\0';
		ft_strappend((char **)&(curr_rem->content), buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (get_remained_line(curr_rem, line, 0))
		return (1);
	f = get_remained_line(curr_rem, line, 1);
	return ((readed < BUFFER_SIZE || !f) ? 0 : 1);
}
