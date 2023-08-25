/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:07:25 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/25 14:49:28 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	array_size(int *arr)
{
	int	size;

	size = 0;
	while (arr[size] != '\0')
	{
		size++;
	}
	return (size);
}

int	already_good(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	ft_lstclear2(a);
	return (1);
}

int	exist(t_list *l, int nb)
{
	t_list	*lst;

	lst = l;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->data < nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	exist2(t_list *l, int nb)
{
	t_list	*lst;

	lst = l;
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->data > nb)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	*tri_rap(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 1;
	(void) temp;
	temp = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (arr);
}
