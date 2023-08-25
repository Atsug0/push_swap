/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:47:17 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:46 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_pa_xtime(t_list	**a, t_list **b, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		push_a(a, b);
		i++;
	}
}

void	combo1(t_list **a, t_list **b)
{
	swap_b(b);
	do_pa_xtime(a, b, 3);
}

void	combo2(t_list **a, t_list **b)
{
	rotate_b(b);
	swap_b(b);
	do_pa_xtime(a, b, 2);
	if (list_size(*b) == 1)
		push_a(a, b);
	else
	{
		rrotate_b(b);
		push_a(a, b);
	}
}

void	combo3(t_list **a, t_list **b)
{
	swap_b(b);
	push_a(a, b);
	swap_b(b);
	do_pa_xtime(a, b, 2);
}

void	combo4(t_list **a, t_list **b)
{
	push_a(a, b);
	swap_b(b);
	push_a(a, b);
	swap_a(a);
	push_a(a, b);
}
