#include "libft.h"

size_t				ft_lstsize(t_list *list)
{
	size_t	res;

	res = 0;
	while (list)
	{
		list = list->next;
		res++;
	}
	return (res);
}
