/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:05:25 by lcamerly          #+#    #+#             */
/*   Updated: 2023/10/05 10:56:20 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int arg)
{
	return (write(1, &arg, 1));
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
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
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
