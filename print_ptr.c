/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:49:18 by lcamerly          #+#    #+#             */
/*   Updated: 2023/10/06 13:44:31 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_adress(unsigned long long num, char *hex_base)
{
	int	count;

	if (num > 15)
		count = ft_print_hex_adress(num / 16, hex_base);
	else
		count = 0;
	return (count + ft_print_char(hex_base[num % 16]));
}

int	ft_print_ptr(void *ptr)
{
	char				*hex_base;
	unsigned long long	num;
	int					count;

	hex_base = "0123456789abcdef";
	num = (unsigned long long)ptr;
	if (num == 0)
	{
		ft_print_str("(nil)");
		return (4);
	}
	ft_print_str("0x");
	count = ft_print_hex_adress(num, hex_base);
	return (count + 1);
}
