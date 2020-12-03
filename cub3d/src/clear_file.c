#include <cub3d.h>

void	clear_file(t_list *file)
{
	t_list *p;
	t_list *p2;

	p = file;
	while (p)
	{
		p2 = p;
		p = p->next;
		//ft_printf("clear: %s\n", (char*)(p2->content));
		free((char*)(p2->content));
		free(p2);
	}
}
