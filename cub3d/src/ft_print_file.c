#include <cub3d.h>

void		ft_print_file(t_list *file)
{
	t_list *p;

	p = file;
	while (p)
	{
		ft_putendl_fd((char*)(p->content), 1);
		p = p->next;
	}
}
