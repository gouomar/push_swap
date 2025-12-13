/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:33:47 by gomar             #+#    #+#             */
/*   Updated: 2025/10/27 01:31:22 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*p;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start_index = 0;
	while (s1[start_index] && is_in_set(s1[start_index], set))
		start_index++;
	end_index = ft_strlen(s1);
	while (end_index > start_index
		&& is_in_set(s1[end_index - 1], set))
		end_index--;
	p = malloc(end_index - start_index + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1 + start_index, end_index - start_index + 1);
	return (p);
}
