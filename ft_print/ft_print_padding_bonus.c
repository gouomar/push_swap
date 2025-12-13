/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 01:25:59 by gomar             #+#    #+#             */
/*   Updated: 2025/11/03 18:37:02 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	ft_print_padding(int times, char c)
{
	int	count;

	count = 0;
	while (count < times)
	{
		ft_putchar(c, 1);
		count++;
	}
	return (count);
}
