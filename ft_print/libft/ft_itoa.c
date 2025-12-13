/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:50:30 by gomar             #+#    #+#             */
/*   Updated: 2025/10/27 01:19:58 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;
	int	is_negative;

	is_negative = 0;
	count = 1;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count + is_negative);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	size;
	char	*p;

	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	size = ft_count(nb);
	p = malloc(sizeof(char) * (size + 1));
	if (!p)
		return (NULL);
	p[size] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		p[0] = '-';
	}
	while (nb > 0)
	{
		p[--size] = (nb % 10) + '0';
		nb /= 10;
	}
	return (p);
}
