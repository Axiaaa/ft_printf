#include "ft_printf.h"

int	main(void)
{
	int a = 10;
	printf("ft_printf : %d\n", ft_printf("Hello, my name is %s\n", "Lucie"));
	printf("printf : %d\n", printf("Hello, my name is %s\n", "Lucie"));

	printf("ft_printf : %d\n", ft_printf("%p\n", &a));
	printf("printf : %d\n", printf("%p\n", &a));

	printf("ft_printf : %d\n", ft_printf("%X\n", 100));
	printf("printf : %d\n", printf("%X\n", 100));

	printf("ft_printf : %d\n", ft_printf("%x\n", 100));
	printf("printf : %d\n", printf("%x\n", 100));

	printf("ft_printf : %d\n", ft_printf("%u\n", 25));
	printf("printf : %d\n", printf("%u\n", 25));

	printf("ft_printf : %d\n", ft_printf("%%\n"));
	printf("printf : %d\n", printf("%%\n"));

	printf("ft_printf : %d\n", ft_printf("%i\n", 15));
	printf("printf : %d\n", printf("%i\n", 15));

	printf("ft_printf : %d\n", ft_printf("%c\n", "q"));
	printf("printf : %d\n", printf("%c\n", "q"));
}