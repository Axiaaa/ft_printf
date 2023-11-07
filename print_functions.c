/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 09:57:38 by lcamerly          #+#    #+#             */
/*   Updated: 2023/11/07 17:25:33 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(int arg)
{
	return (ft_putnbr(arg));
}

int	ft_print_int(int arg)
{
	return (ft_print_digits(arg));
}

unsigned int ft_print_uint(unsigned int arg)
{
	unsigned int	nb;
	unsigned int				temp;
	unsigned int				res;

	res = 0;
	if (arg < 0)
	{
		write(1, "-", 1);
		res++;
		nb = -arg;
	}
	else
		nb = arg;
	if (nb > 9)
	{
		res += ft_putnbr(nb / 10);
	}
	temp = nb % 10 + '0';
	res += write(1, &temp, 1);
	return (res);
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
	return (count++);
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
	return (count++);
}
