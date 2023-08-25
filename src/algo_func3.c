/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:15:53 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 16:10:52 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	list_to_array2(t_list *head, int size, int mediane)
{
	int		*arr;
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	arr = create_tab(head, size);
	while (i != j)
	{
		if (arr[i] < mediane)
		{
			free(arr);
			return (0);
		}
		if (arr[j] < mediane)
		{
			free(arr);
			return (1);
		}
		i++;
		j--;
	}
	free(arr);
	return (0);
}

int	list_size(t_list *head)
{
	int		size;
	t_list	*curr;

	size = 0;
	curr = head;
	if (!head)
		return (0);
	while (curr != NULL)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}

int	list_size_chunk(t_list *head)
{
	int		size;
	int		current;
	t_list	*curr;

	size = 0;
	if (!head)
		return (0);
	current = head->chunk;
	curr = head;
	while (curr)
	{
		if (curr->chunk == current)
			size++;
		curr = curr->next;
	}
	return (size);
}

void	modif_chunk(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp)
	{
		temp->chunk = temp->chunk + 1;
		temp = temp->next;
	}
}

int	insert_in_a(t_list **a, t_list **b, int temp, int back)
{
	int	i;

	i = 0;
	if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
	{
		push_a(a, b);
		swap_a(a);
		return (back);
	}
	while ((*b)->data > (*a)->data)
	{
		i++;
		rotate_a(a);
	}
	push_a(a, b);
	if (!exist2(*b, temp))
		return (do_rrr_as_possible(a, b, i, back));
	else
	{
		do_rra_xtime(a, i);
		return (back);
	}
}
