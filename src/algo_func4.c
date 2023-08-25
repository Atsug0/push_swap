/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_func4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:01:32 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 16:10:41 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_part1(t_list **a, t_list **b)
{
	int	temp;

	while (list_size(*a) > 3)
	{
		temp = list_to_array_chunk(*a, list_size(*a));
		while (exist(*a, temp) && list_size(*a) > 3)
		{
			if (list_to_array2(*a, list_size(*a), temp) == 0)
			{
				if ((*a)->data <= temp)
					push_b(a, b);
				else if ((*a)->next->data <= temp)
				{
					swap_a(a);
					push_b(a, b);
				}
				else
					rotate_a(a);
			}
			else
				rrotate_a(a);
		}
		modif_chunk(a);
	}
}

void	algo_part2(t_list **a, int temp)
{
	if (list_size(*a) == 2)
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	if (list_size(*a) == 3)
	{
		if ((*a)->data == temp && (*a)->next->data > temp)
			rrotate_a(a);
		else if ((*a)->data < temp && (*a)->next->data > temp)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if ((*a)->data > temp && (*a)->next->data == temp)
		{
			rrotate_a(a);
			rrotate_a(a);
			swap_a(a);
		}
		else if ((*a)->data > temp && (*a)->next->data < temp)
			rotate_a(a);
		else if ((*a)->data == temp && (*a)->next->data < temp)
			swap_a(a);
	}
}

void	algo_part3(t_list **a, t_list **b, int temp, int back)
{
	while (exist2(*b, temp))
	{
		if ((*b)->data >= temp)
			back = insert_in_a(a, b, temp, back);
		else if ((*b)->next->data >= temp)
		{
			swap_b(b);
			back = insert_in_a(a, b, temp, back);
		}
		else
		{
			rotate_b(b);
			back++;
		}
	}
	while (back > 0)
	{
		rrotate_b(b);
		back--;
	}
}

void	algo_part4(t_list **a, t_list **b)
{
	if (list_size_chunk(*b) == 1)
	{
		push_a(a, b);
		if ((*a)->data > (*a)->next->data)
			swap_a(a);
	}
	if (list_size_chunk(*b) == 2)
	{
		if ((*b)->data > (*b)->next->data)
		{
			push_a(a, b);
			if ((*a)->data > (*a)->next->data)
				swap_a(a);
		}
		else
		{
			swap_b(b);
			push_a(a, b);
			if ((*a)->data > (*a)->next->data)
				swap_a(a);
		}
	}
}

void	algo_part5(t_list **a, t_list **b, int temp)
{
	if (list_size_chunk(*b) == 3)
	{
		if ((*b)->data == temp && (*b)->next->data > temp)
			combo1(a, b);
		else if ((*b)->data < temp && (*b)->next->data == temp)
			combo2(a, b);
		else if ((*b)->data < temp && (*b)->next->data > temp)
			combo3(a, b);
		else if ((*b)->data > temp && (*b)->next->data == temp)
			do_pa_xtime(a, b, 3);
		else if ((*b)->data > temp && (*b)->next->data < temp)
		{
			push_a(a, b);
			swap_b(b);
			do_pa_xtime(a, b, 2);
		}
		else if ((*b)->data == temp && (*b)->next->data < temp)
			combo4(a, b);
	}
}
