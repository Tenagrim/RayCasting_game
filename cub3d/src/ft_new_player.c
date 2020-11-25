#include <cub3d.h>

t_player	*ft_new_player(void)
{
	t_player *res;

	res = (t_player*)malloc(sizeof(t_player));
	res->pos = ft_new_floatpair(30.0, 60.0);
	res->move = ft_new_floatpair(0.0, 0.0);
	res->move_speed = 0.15;
	res->rot_speed = 0.010;
	res->angle = 0.0;
	res->move_flags = 0;
	res->walk_speed = 0.15;
	res->run_speed= 0.3;
	return (res);
}
