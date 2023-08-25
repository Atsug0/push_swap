/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:13:19 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 16:25:03 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_chunk(t_list *head, int size)
{
	int		*arr;
	int		fin;
	int		i;
	t_list	*curr;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	curr = head;
	while (curr != NULL && i < size)
	{
		arr[i] = curr->data;
		curr = curr->next;
		i++;
	}
	arr = tri_rap(arr, size);
	fin = arr[size - 1];
	free(arr);
	return (fin);
}

int	prefered_size(int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i * i < size)
	{
		j = i;
		i++;
	}
	return (j);
}

int	list_to_array(t_list *head, int size)
{
	int		*arr;
	int		fin;
	int		i;
	t_list	*curr;

	if (size == 0)
		return (0);
	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	curr = head;
	while (curr != NULL && i < size)
	{
		arr[i] = curr->data;
		curr = curr->next;
		i++;
	}
	arr = tri_rap(arr, size);
	fin = arr[size / 2];
	free(arr);
	return (fin);
}

int	list_to_array_chunk(t_list *head, int size)
{
	int		*arr;
	int		fin;
	int		i;
	t_list	*curr;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	curr = head;
	while (curr != NULL && i < size)
	{
		arr[i] = curr->data;
		curr = curr->next;
		i++;
	}
	arr = tri_rap(arr, size);
	fin = arr[size / (size / prefered_size(size))];
	if (size >= 100)
		fin = arr[size / 6];
	free(arr);
	return (fin);
}

int	*create_tab(t_list *head, int size)
{
	int		*arr;
	int		i;
	t_list	*curr;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		return (0);
	i = 0;
	curr = head;
	while (curr != NULL && i < size)
	{
		arr[i] = curr->data;
		curr = curr->next;
		i++;
	}
	return (arr);
}
