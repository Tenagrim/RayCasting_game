#include "libft.h"

t_list			*ft_lstnew(void const *content)
{
	t_list	*res;

	res = (t_list*)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = (void*)content;
	res->next = NULL;
	return (res);
}
