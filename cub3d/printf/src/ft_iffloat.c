#include <ft_printf.h>

int	ft_iffloat(t_attr *attr, va_list arg)
{
	char	*str;
	double	num;
	int		len;
	int		pres;

	pres = (attr->precision == -1) ? 6 : attr->precision;
	num = va_arg(arg, double);
	str = ft_dtoa(num, pres);
	len = ft_format_output_float(attr, str);
	free(str);
	return (len);
}
