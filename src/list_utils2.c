/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:34:44 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:54 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = *b;
		*b = (*b)->next;
		temp->next = *a;
		*a = temp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		temp = *a;
		*a = (*a)->next;
		temp->next = *b;
		*b = temp;
		ft_putstr_fd("pb\n", 1);
	}
}

void	rotate_a(t_list **a)
{
	t_list	*temp;

	if (*a)
	{
		temp = *a;
		ft_lstadd_back(a, temp);
		*a = (*a)->next;
		temp->next = NULL;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = *b;
		ft_lstadd_back(b, temp);
		*b = (*b)->next;
		temp->next = NULL;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_all(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
	{
		temp = *b;
		ft_lstadd_back(b, temp);
		*b = (*b)->next;
		temp->next = NULL;
	}
	if (*a)
	{
		temp = *a;
		ft_lstadd_back(a, temp);
		*a = (*a)->next;
		temp->next = NULL;
	}
	ft_putstr_fd("rr\n", 1);
}
