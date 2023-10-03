/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:32:31 by lcamerly          #+#    #+#             */
/*   Updated: 2023/09/13 18:49:58 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

void	f(unsigned int i, char *c)
{
	(void)i;
	*c += 1;
}
/*
int	main(void)
{
	char str1[] = "abc";
    ft_striteri(str1, *f);
	printf("%s\n", str1);
}*/