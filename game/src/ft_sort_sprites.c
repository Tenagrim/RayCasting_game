#include <cub3d.h>

t_sprite	*ft_sort_sprites(t_game *game, t_sprite *sprites)
{
	t_sprite	*sorted;
	t_floatpair	p;

	sorted = NULL;
	p.x = game->player->pos->x;
	p.y = game->player->pos->y;
	while (sprites)
	{
		sprites->dist =
			sqrt((((p.x - sprites->pos->x) * (p.x - sprites->pos->x) +
							(p.y - sprites->pos->y) *
							(p.y - sprites->pos->y))));
		sprites->sorted = NULL;
		ft_sprtadd_sorted(&sorted, sprites);
		sprites = sprites->next;
	}
	return (sorted);
}
