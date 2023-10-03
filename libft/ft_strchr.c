/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:39:45 by lcamerly          #+#    #+#             */
/*   Updated: 2023/09/14 19:27:07 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	car;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	car = (char)c;
	while (str[i])
	{
		if (str[i] == car)
			return (&str[i]);
		i++;
	}
	if (car == '\0')
		return (&str[i]);
	return (0);
}
