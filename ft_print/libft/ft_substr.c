/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:18:15 by gomar             #+#    #+#             */
/*   Updated: 2025/10/27 01:45:26 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_empty(void)
{
	char	*p;

	p = malloc(1);
	if (!p)
		return (NULL);
	*p = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_create_empty());
	if (len > s_len - start)
		len = s_len - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
