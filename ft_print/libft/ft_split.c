/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:37:53 by gomar             #+#    #+#             */
/*   Updated: 2025/11/02 13:05:17 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **p, size_t j)
{
	while (j > 0)
	{
		j--;
		free(p[j]);
	}
	free(p);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (words);
}

static char	**do_split(char **p, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		p[j] = ft_substr(s, start, i - start);
		if (!p[j])
		{
			free_all(p, j);
			return (NULL);
		}
		j++;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	p = malloc(sizeof(char *) * (words + 1));
	if (!p)
		return (NULL);
	return (do_split(p, s, c, words));
}
