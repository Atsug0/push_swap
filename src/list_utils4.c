/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:15:45 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:47 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_ra_xtime(t_list	**a, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rotate_a(a);
		i++;
	}
}

void	do_rb_xtime(t_list	**b, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rotate_b(b);
		i++;
	}
}

void	do_rra_xtime(t_list	**a, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rrotate_a(a);
		i++;
	}
}

void	do_rrb_xtime(t_list	**b, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rrotate_b(b);
		i++;
	}
}

void	do_rr_xtime(t_list	**a, t_list **b, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rotate_all(a, b);
		i++;
	}
}
