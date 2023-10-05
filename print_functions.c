/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:57:38 by lcamerly          #+#    #+#             */
/*   Updated: 2023/10/05 10:52:08 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int	ft_print_digits(int arg)
{
	ft_putnbr_fd(arg, 1);
	return (sizeof(arg) / sizeof(int));
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
