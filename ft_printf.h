/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nephtys <nephtys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:09:26 by lcamerly          #+#    #+#             */
/*   Updated: 2023/10/03 21:09:56 by nephtys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_print_digits(int arg);
int	ft_print_str(char *arg);
int	ft_print_char(int arg);
int	ft_print_hexa_digits_lower(int arg);
int	ft_print_hexa_digits_upper(int arg);
int	ft_print_pointer(int arg);
int	ft_print_int(int arg);
int	ft_print_unsigned(int arg);
int	ft_printf(const char *format, ...);
void ft_putnbr_fd(int n, int fd);

#endif