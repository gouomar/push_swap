/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomar <gomar@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:49:44 by gomar             #+#    #+#             */
/*   Updated: 2025/10/29 12:16:03 by gomar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_new_node(t_list *lst, void *(*f)(void *))
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = f(lst->content);
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = create_new_node(lst, f);
	if (!new_lst)
		return (NULL);
	tmp = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = create_new_node(lst, f);
		if (!tmp->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (new_lst);
}
