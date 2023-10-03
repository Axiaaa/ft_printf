/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephtys <nephtys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:05:25 by lcamerly          #+#    #+#             */
/*   Updated: 2023/10/03 21:13:55 by nephtys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(int arg)
{
	ft_putnbr_fd(arg, 1);
	return (sizeof(arg) / sizeof(int));
}

int	ft_print_str(char *arg)
{
	int	count;

	count = 0;
	while (*arg)
	{
		count += ft_print_char((int)*arg);
		arg++;
	}
	return (--count);
}

int	ft_print_char(int arg)
{
	return (write(1, &arg, 1));
}

int	ft_print_hexa_digits_lower(int arg)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (arg < 0)
	{
		ft_print_char('-');
		arg = -arg;
		count++;
	}
	if (arg >= 16)
	{
		count += ft_print_hexa_digits_lower(arg / 16);
		count += ft_print_hexa_digits_lower(arg % 16);
	}
	else
	{
		ft_print_char(base[arg]);
		count++;
	}
	return (count);
}

int	ft_print_hexa_digits_upper(int arg)
{
	int		count;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	if (arg < 0)
	{
		ft_print_char('-');
		arg = -arg;
		count++;
	}
	if (arg >= 16)
	{
		count += ft_print_hexa_digits_upper(arg / 16);
		count += ft_print_hexa_digits_upper(arg % 16);
	}
	else
	{
		ft_print_char(base[arg]);
		count++;
	}
	return (count);
}

int	ft_print_int(int arg)
{
	int	count;

	count = 0;
	if (arg < 0)
	{
		ft_print_char('-');
		arg = -arg;
		count++;
	}
	count += ft_print_digits(arg);
	return (count);
}

int	ft_print_uint(unsigned int arg)
{
	int	count;

	count = 0;
	count += ft_print_digits(arg);
	return (count);
}

int	ft_args_process(char c, va_list args)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int));
	else if (c == 'd')
		return (ft_print_digits(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'x')
		return (ft_print_hexa_digits_lower(va_arg(args, int)) - 1);
	else if (c == 'X')
		return (ft_print_hexa_digits_upper(va_arg(args, int)) - 1);
	// else if (c == 'p')
	//     return (ft_print_ptr(&va_arg(args, int)));
	else if (c == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_uint(va_arg(args, int)));
	else if (c == '%')
		write(1, "%", 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
    va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += ft_args_process(*++format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	count++;
	va_end(args);
	return (count);
}

int	main(void)
{
	int a;
	a = 0;
	int count;
	count = 0;
	int count2 = 0;
#include <stdio.h>

	count = ft_printf("Test 1 : %c\n", 'a');
	count2 = printf("Test 1 : %c\n", 'a');
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 2 : %d\n", 42);
	count2 = printf("Test 2 : %d\n", 42);
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 3 : %s\n", "test");
	count2 = printf("Test 3 : %s\n", "test");
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 4 : %x\n", 42);
	count2 = printf("Test 4 : %x\n", 42);
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 5 : %X\n", 42);
	count2 = printf("Test 5 : %X\n", 42);
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 7 : %i\n", 42);
	count2 = printf("Test 7 : %i\n", 42);
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 8 : %u\n", 42);
	count2 = printf("Test 8 : %u\n", 42);
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
	count = ft_printf("Test 9 : %%\n");
	count2 = printf("Test 9 : %%\n");
	printf("count ft_printf : %d\n count printf : %d\n", count, count2);
}