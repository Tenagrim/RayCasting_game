#include <cub3d.h>

t_player	*ft_new_player(void)
{
	t_player *res;

	res = (t_player*)malloc(sizeof(t_player));
	res->pos = ft_new_floatpair(30.0, 30.0);
	res->move = ft_new_floatpair(0.0, 0.0);
	res->move_speed = 5.0;
	res->rot_speed = 5.0;
	return (res);
}
