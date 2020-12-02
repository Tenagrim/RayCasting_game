#include <cub3d.h>

void		clear_sprites(t_sprite **sprites)
{
	t_sprite	*p;
	t_sprite	*p2;

	if (!(*sprites))
		return ;
	p = *sprites;
	while (p)
	{
		p = p->next;
		p2 = p;
		if (p2->pos)
			free(p2->pos);
		free(p2);
	}
	*sprites = NULL;
}

