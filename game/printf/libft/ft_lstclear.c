#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p1;
	t_list	*p2;

	p1 = *lst;
	while (p1)
	{
		p2 = p1;
		p1 = p1->next;
		del(p2->content);
		free(p2);
	}
	*lst = 0;
}
