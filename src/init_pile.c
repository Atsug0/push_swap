/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:41:09 by atsug0            #+#    #+#             */
/*   Updated: 2023/08/25 12:52:33 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

t_list	*init_pile(char **str)
{
	t_list	*first;
	int		i;

	first = NULL;
	i = 0;
	while (str[i])
	{
		if (call_it(str, str[i], i) == 0)
		{
			ft_lstclear(first);
			ft_error();
			return (NULL);
		}
		ft_lstadd_back(&first, create_node(atoi(str[i])));
		i++;
	}
	return (first);
}
