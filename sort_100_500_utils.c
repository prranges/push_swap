/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:01:12 by prranges          #+#    #+#             */
/*   Updated: 2021/08/23 17:57:23 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	find_pivot(t_list *lst, t_list *end)
{
	t_list	*p;
	int		min_index;
	int		counter;
	int		was_in_b_stored;

	p = lst->next;
	was_in_b_stored = lst->next->was_in_b;
	counter = 0;
	min_index = lst->next->index;
	while (p != end && p->was_in_b == was_in_b_stored)
	{
		if (p->index < min_index)
			min_index = p->index;
		p = p->next;
		counter++;
	}
	lst->pivot = NULL;
	while (lst->pivot == NULL)
	{
		if (p->index == ((counter / 2) + min_index))
			lst->pivot = p;
		p = p->next;
	}
}

void	solve_A_1(t_list *lst_a, t_list *lst_b)
{
	if (lst_b->next->next->index == lst_a->next_sort && lst_b->count >= 2)
		rotate(lst_b, 1);
	if (lst_b->next->next->next->index == lst_a->next_sort && lst_b->count >= 4)
	{
		rotate(lst_b, 1);
		rotate(lst_b, 1);
	}
	if (lst_b->next->next->next->next->index == lst_a->next_sort
		&& lst_b->count >= 6)
	{
		rotate(lst_b, 1);
		rotate(lst_b, 1);
		rotate(lst_b, 1);
	}
	if (lst_b->next->next->next->next->next->index == lst_a->next_sort
		&& lst_b->count >= 8)
	{
		rotate(lst_b, 1);
		rotate(lst_b, 1);
		rotate(lst_b, 1);
		rotate(lst_b, 1);
	}
}

void	solve_A_2(t_list *lst_a, t_list *lst_b)
{
	if (lst_b->prev->index == lst_a->next_sort && lst_b->count >= 3)
		reverse(lst_b, 1);
	if (lst_b->prev->prev->index == lst_a->next_sort && lst_b->count >= 5)
	{
		reverse(lst_b, 1);
		reverse(lst_b, 1);
	}
	if (lst_b->prev->prev->prev->index == lst_a->next_sort
		&& lst_b->count >= 7)
	{
		reverse(lst_b, 1);
		reverse(lst_b, 1);
		reverse(lst_b, 1);
	}
	if (lst_b->prev->prev->prev->index == lst_a->next_sort
		&& lst_b->count >= 9)
	{
		reverse(lst_b, 1);
		reverse(lst_b, 1);
		reverse(lst_b, 1);
		reverse(lst_b, 1);
	}
}
