/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsug0 <atsug0@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:00:21 by atsug0            #+#    #+#             */
/*   Updated: 2023/08/27 04:28:32 by atsug0           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	ft_lstclear2(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	do_rrr_as_possible(t_list **a, t_list **b, int rra, int rrb)
{
	if (rra > rrb)
	{
		do_rrr_xtime(a, b, rrb);
		do_rra_xtime(a, rra - rrb);
	}
	else if (rra < rrb)
	{
		do_rrr_xtime(a, b, rra);
		do_rrb_xtime(b, rrb - rra);
	}
	else
	{
		do_rrr_xtime(a, b, rra);
	}
	return (0);
}

int	algo(char **lst)
{
	t_list	*a;
	t_list	*b;

	a = init_pile(lst);
	b = NULL;
	if (a == NULL)
		return (0);
	if (already_good(&a))
		return (1);
	algo_part1(&a, &b);
	algo_part2(&a, list_to_array(a, list_size(a)));
	while (list_size(b) > 0)
	{
		while (list_size_chunk(b) > 3)
			algo_part3(&a, &b, list_to_array(b, list_size_chunk(b)), 0);
		algo_part4(&a, &b);
		algo_part5(&a, &b, list_to_array(b, list_size_chunk(b)));
	}
	ft_lstclear2(&a);
	ft_lstclear2(&b);
	return (1);
}
