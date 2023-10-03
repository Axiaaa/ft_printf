/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:30 by lcamerly          #+#    #+#             */
/*   Updated: 2023/09/13 12:17:14 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	while (i < size && dest[i] != '\0')
	{
		i++;
	}
	j = ft_strlen(src);
	k = 0;
	if (size == 0 || i == size)
		return (j + i);
	while (src[k] && i + 1 + k < size)
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + j);
}

/*
int	main(void)
{	
	char s1[] = "Prout";
	char s2[] = "Crout";
	ft_strlcat(s1, s2, 11);
	printf("%s\n", s1);
}*/