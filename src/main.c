/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:15:27 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:40:56 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;
	int	index;

	signe = 1;
	result = 0;
	index = 0;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			signe *= -1;
		index++;
	}
	if (str[index] < '0' || str[index] > '9')
		return (ft_error());
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			result = result * 10 + (str[index] + '0');
		else
			return (ft_error());
		index++;
	}
	return (signe * result);
}

int	main(int argc, char *argv[])
{
	char	**list;

	if (argc == 1)
		return (ft_error());
	if (argc == 2)
	{
		list = is_all_digits(argv[1]);
		if (!list)
			return (ft_error());
		algo(list);
		ft_bigfree(list);
		return (1);
	}
	else
	{
		argv = argv + 1;
		list = argv;
		if (!is_all_digits2(list))
			return (ft_error());
		return (algo(list));
	}
}
