/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:09:26 by lcamerly          #+#    #+#             */
/*   Updated: 2023/10/05 10:56:37 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_print_digits(int arg);
int		ft_print_str(char *arg);
int		ft_print_char(int arg);
int		ft_print_hexa_digits_lower(int arg);
int		ft_print_hexa_digits_upper(int arg);
int		ft_print_int(int arg);
int		ft_print_uint(unsigned int arg);
int		ft_printf(const char *format, ...);
int		ft_print_ptr(void *ptr);
int		ft_print_hex_adress(unsigned long long num, char *hex_base);
void	ft_putnbr_fd(int n, int fd);

#endif