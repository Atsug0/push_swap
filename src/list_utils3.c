/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:36:04 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:48 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*deletelast(t_list **head)
{
	t_list	*temp;
	t_list	*renvoi;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		*head = NULL;
		return (*head);
	}
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	renvoi = temp->next;
	temp->next = NULL;
	return (renvoi);
}

void	rrotate_a(t_list **a)
{
	t_list	*temp;

	temp = deletelast(a);
	temp->next = *a;
	*a = temp;
	ft_putstr_fd("rra\n", 1);
}

void	rrotate_b(t_list **b)
{
	t_list	*temp;

	temp = deletelast(b);
	temp->next = *b;
	*b = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	rr_all(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	temp = deletelast(a);
	temp->next = *a;
	*a = temp;
	temp2 = deletelast(b);
	temp2->next = *b;
	*b = temp2;
	ft_putstr_fd("rrr\n", 1);
}

void	do_rrr_xtime(t_list	**a, t_list **b, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rr_all(a, b);
		i++;
	}
}
