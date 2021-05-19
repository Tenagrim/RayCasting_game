#include <ft_printf.h>

t_attr	*ft_new_attr(void)
{
	t_attr	*res;

	res = (t_attr*)malloc(sizeof(t_attr));
	res->width = -1;
	res->flags = 0;
	res->precision = -1;
	res->conv = 0;
	return (res);
}
