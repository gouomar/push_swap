/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:00:00 by gomar             #+#    #+#             */
/*   Updated: 2025/12/20 15:09:22 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static char	*get_next_line_simple(int fd)
{
	char	*line;
	char	buf;
	int		i;
	int		ret;

	line = malloc(4096);
	if (!line)
		return (NULL);
	i = 0;
	ret = read(fd, &buf, 1);
	while (ret > 0 && buf != '\n' && i < 4095)
	{
		line[i++] = buf;
		ret = read(fd, &buf, 1);
	}
	if (ret <= 0 && i == 0)
		return (free(line), NULL);
	line[i] = '\0';
	return (line);
}

static int	read_and_execute(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line_simple(0);
	while (line)
	{
		if (!execute_instruction(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line_simple(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
		return (error_exit(a, b), 1);
	if (!parse_args(argc, argv, a))
		return (error_exit(a, b), 1);
	if (!read_and_execute(a, b))
		return (error_exit(a, b), 1);
	if (is_sorted(a) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
