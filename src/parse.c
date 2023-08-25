/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:41:14 by atsug0            #+#    #+#             */
/*   Updated: 2023/08/25 12:46:21 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_correct(int str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int	use_correct(char **spl, int str)
{
	if (str)
	{
		if (!is_correct(str))
		{
			ft_bigfree(spl);
			return (0);
		}
		return (1);
	}
	else
	{
		ft_bigfree(spl);
		return (0);
	}
}

char	**is_all_digits(char *str)
{
	char	**spl;
	int		i;
	int		j;

	spl = ft_split(str, ' ');
	if (!spl || spl[0] == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (spl[i])
	{
		while (spl[i][j])
		{
			if (spl[i][j] == '-' && !use_correct(spl, spl[i][j + 1]))
				return (NULL);
			else
				if (!is_correct(spl[i][j]))
					return (ft_bigfree(spl));
			j++;
		}
		j = 0;
		i++;
	}
	return (spl);
}

int	is_all_digits2(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (str[i][j] == '-')
			{
				if (!is_correct(str[i][j + 1]))
					return (0);
			}
			else
				if (!is_correct(str[i][j]))
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
