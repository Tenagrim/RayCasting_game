#include <cub3d.h>

void	ft_sprtadd_front(t_sprite **list, t_sprite *new)
{
	if (*list)
	{
		new->next = *list;
		*list = new;
	}
	else
		*list = new;
}
