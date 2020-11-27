#include <cub3d.h>

t_player	*ft_new_player(void)
{
	t_player *res;

	res = (t_player*)malloc(sizeof(t_player));
	res->pos = ft_new_floatpair(75.0, 130.0);
	res->move = ft_new_floatpair(0.0, 0.0);
	res->walk_speed = 1.2;
	res->run_speed= res->walk_speed * 2;
	res->move_speed = 0.4;
	res->rot_speed = 0.033;
	res->angle = 0.0;
	res->move_flags = 0;
	return (res);
}
