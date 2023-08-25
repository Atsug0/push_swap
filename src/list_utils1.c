/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:32:32 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:45 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*add_node(int data, t_list *current)
{
	t_list	*new;

	new = create_node(data);
	if (!new)
		return (NULL);
	if (!current)
		return (new);
	new->next = current;
	return (new);
}

void	swap_a(t_list **current)
{
	t_list	*temp;

	if (!current)
		return ;
	if (!(*current)->next)
		return ;
	temp = (*current)->next->next;
	(*current)->next->next = *current;
	(*current) = (*current)->next;
	(*current)->next->next = temp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **current)
{
	t_list	*temp;

	if (!current)
		return ;
	if (!(*current)->next)
		return ;
	temp = (*current)->next->next;
	(*current)->next->next = *current;
	(*current) = (*current)->next;
	(*current)->next->next = temp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_all(t_list **a, t_list **b)
{
	swap_a(a);
	swap_b(b);
	ft_putstr_fd("ss\n", 1);
}
