/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:01:12 by prranges          #+#    #+#             */
/*   Updated: 2021/08/23 17:56:35 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_3(t_list *lst, int i)
{
	t_list	*max;

	max = find_max(lst);
	if (lst->count == 1)
		return ;
	if (lst->count == 2)
	{
		if (lst->next->next->data < lst->next->data)
			swap(lst, i);
	}
	if (lst->count == 3)
	{
		if (lst->next == max)
			rotate(lst, 0);
		if (lst->next->next == max)
			reverse(lst, 0);
		if (lst->next->data > lst->next->next->data)
			swap(lst, i);
	}
}

t_list	*find_min(t_list *lst)
{
	t_list	*min;
	t_list	*p;

	p = lst->next;
	min = p;
	while (p != lst)
	{
		if (p->data < min->data)
			min = p;
		p = p->next;
	}
	return (min);
}

t_list	*find_max(t_list *lst)
{
	t_list	*max;
	t_list	*p;

	p = lst->next;
	max = p;
	while (p != lst)
	{
		if (p->data > max->data)
			max = p;
		p = p->next;
	}
	return (max);
}

void	sort_5(t_list *lst_a, t_list *lst_b)
{
	t_list	*min;
	t_list	*max;

	min = find_min(lst_a);
	max = find_max(lst_a);
	while (lst_a->count > 3 && is_sorted(lst_a))
	{
		if (lst_a->prev == max || lst_a->prev == min)
			reverse(lst_a, 0);
		if (lst_a->next == max || lst_a->next == min)
			push(lst_b, pop(lst_a), 0);
		else
			rotate(lst_a, 0);
	}
	sort_3(lst_a, 0);
	if (lst_b->count > 1)
		sort_3(lst_b, 1);
	while (lst_b->count > 0)
		push(lst_a, pop(lst_b), 1);
	if (lst_a->next == max)
		rotate(lst_a, 0);
}
