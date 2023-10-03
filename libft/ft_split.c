/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:55:39 by lcamerly          #+#    #+#             */
/*   Updated: 2023/09/15 09:37:33 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			words++;
		while (str[i] && (!(str[i] == c)))
			i++;
	}
	return (words);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
}

static int	ft_add_words(char **strs, char const *s, char c, int word)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (j < word)
	{
		while (s[i] && s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = malloc(sizeof(char) * (size + 1));
		if (!strs[j])
		{
			ft_free(strs, j);
			return (0);
		}
		ft_strlcpy(strs[j], &s[i], size + 1);
		i += size;
		j++;
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		word;
	int		check;

	if (!s)
		return (NULL);
	word = ft_count_word(s, c);
	strs = malloc(sizeof(char *) * (word + 1));
	if (!strs)
		return (NULL);
	check = ft_add_words(strs, s, c, word);
	if (!check)
		return (NULL);
	return (strs);
}
