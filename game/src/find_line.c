#include <cub3d.h>

char		*find_line(t_list *file, char *key)
{
	t_list	*p;
	char	*res;
	char	*susp;

	p = file;
	res = NULL;
	while (p)
	{
		susp = (char *)(p->content);
		if (!ft_strncmp(susp, key, ft_strlen(key)))
			return (susp);
		p = p->next;
	}
	return (res);
}
