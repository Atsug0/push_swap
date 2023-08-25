/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:01:30 by hmoulard          #+#    #+#             */
/*   Updated: 2023/08/25 14:49:21 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct t_list
{
	struct t_list	*next;
	int				data;
	int				chunk;
}t_list;

void	ft_putstr_fd(char *s, int fd);
void	ft_lstadd_back(t_list **lst, t_list *news);
void	algo_part5(t_list **a, t_list **b, int temp);
void	do_pa_xtime(t_list	**a, t_list **b, int x);
void	algo_part4(t_list **a, t_list **b);
void	algo_part2(t_list **a, int temp);
void	algo_part1(t_list **a, t_list **b);
void	algo_part3(t_list **a, t_list **b, int temp, int back);
void	modif_chunk(t_list **a);
void	combo1(t_list **a, t_list **b);
void	combo2(t_list **a, t_list **b);
void	combo3(t_list **a, t_list **b);
void	combo4(t_list **a, t_list **b);
t_list	*create_node(int data);
void	swap_a(t_list **current);
void	swap_b(t_list **current);
void	swap_all(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_all(t_list **a, t_list **b);
void	rrotate_a(t_list **a);
void	rrotate_b(t_list **b);
void	rr_all(t_list **a, t_list **b);
void	do_rrr_xtime(t_list	**a, t_list **b, int x);
void	do_ra_xtime(t_list	**a, int x);
void	do_rb_xtime(t_list	**b, int x);
void	do_rra_xtime(t_list	**a, int x);
void	do_rrb_xtime(t_list	**b, int x);
void	ft_lstclear2(t_list **lst);
void	do_rr_xtime(t_list	**a, t_list **b, int x);
char	**ft_split(char *str, char charset);
char	**ft_bigfree(char **tab);
int		call_it(char **str, char *find, int index);
int		ft_error(void);
int		max_chunk(t_list *head, int size);
int		prefered_size(int size);
int		insert_in_a(t_list **a, t_list **b, int temp, int back);
int		do_rrr_as_possible(t_list **a, t_list **b, int rra, int rrb);
int		atoi(const char *str);
int		*create_tab(t_list *head, int size);
int		list_to_array(t_list *head, int size);
int		is_all_digits2(char **str);
int		list_to_array_chunk(t_list *head, int size);
int		array_size(int *arr);
int		exist(t_list *l, int nb);
int		list_to_array2(t_list *head, int size, int mediane);
int		list_size_chunk(t_list *head);
int		list_size(t_list *head);
int		already_good(t_list **a);
int		*tri_rap(int *arr, int size);
int		exist2(t_list *l, int nb);
void	modif_chunk(t_list **a);
char	**is_all_digits(char *str);
size_t	ft_strlen(char *str);
t_list	*init_pile(char **str);
int		algo(char **lst);
int		list_to_array(t_list *head, int size);
t_list	*ft_find_end(t_list *begin);
int		list_size(t_list *head);
int		list_size_chunk(t_list *head);

#endif