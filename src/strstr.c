/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:35:10 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/25 12:54:52 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	call_it(char **str, char *find, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_strcmp(str[i], find) == 0)
			return (0);
		i++;
	}
	return (1);
}
