/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:46:40 by gshona            #+#    #+#             */
/*   Updated: 2020/11/03 12:08:48 by gshona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list_fd
{
	struct s_list	*next;
	void			*content;
	int				fd;
}					t_list_fd;

int					get_next_line(const int fd, char **line);
char				*ft_stralloc(size_t size);
size_t				ft_strlen(const char *str);
void				ft_strappend(char **str, char *append);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
#endif
