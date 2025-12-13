/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:20:53 by gomar             #+#    #+#             */
/*   Updated: 2025/10/27 01:07:10 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i <= len)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
