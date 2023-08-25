/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:04:00 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/16 11:39:53 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd > 0 && s != NULL)
		write(fd, s, ft_strlen(s));
}

t_list	*ft_find_end(t_list *begin)
{
	t_list	*temp;

	temp = begin;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *news)
{
	t_list	*temp;

	if (!news)
		return ;
	if (!*lst)
		*lst = news;
	else
	{
		temp = ft_find_end(*lst);
		temp->next = news;
	}
}

t_list	*create_node(int data)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->data = data;
	res->chunk = 0;
	return (res);
}
