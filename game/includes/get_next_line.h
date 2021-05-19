#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

int					get_next_line(const int fd, char **line);
char				*ft_str_chr(char *str, int c);
char				*ft_str_join(char *s1, char *s2);
int					ft_free(char **buff);
#endif
