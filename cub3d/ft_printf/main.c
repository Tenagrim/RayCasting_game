#include <ft_printf.h>
#include <stdio.h>

int main()
{
	//printf("flags: %d\n", attr->flags);
	//printf("width: %d\n", attr->width);
	//printf("pres : %d\n", attr->precision);
	//printf("conv : %c\n", attr->conv);
	//printf(">>%d<<", attr->flags & SIZE_UP_L);
	//char *tmp = ft_dtoa(1.9999, 3);
	//ft_printf("|%03.7d|\n", -2375);
	//int *tmp = malloc(sizeof(int));
	//*tmp = 255;
	//unsigned long int n_tmp = (unsigned long int)tmp;

	printf("|%-*.*s|\n", -1 , 0 , "123");
	ft_printf("|%-*.*s|\n", -1 , 0 , "123");

	//printf("%.5p\n", NULL);
//	int i = 0x71727374;
//	printf("%c %c %c %c", i);
	//printf("%.5p\n", 0);

	return (0);
}
