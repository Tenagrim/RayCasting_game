/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:46:40 by gshona            #+#    #+#             */
/*   Updated: 2020/11/19 23:06:15 by tenagrim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);
char				*ft_strdup(const char *str);
char				*ft_str_chr(char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_str_join(char *s1, char *s2);
size_t				ft_strlen(const char *str);
int					ft_free(char **buff);
#endif
