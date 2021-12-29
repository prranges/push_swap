/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:01:12 by prranges          #+#    #+#             */
/*   Updated: 2021/08/23 17:57:23 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	A_to_B(t_list *lst_a, t_list *lst_b, int v, int i)
{
	find_pivot(lst_a, lst_a);
	while (i <= lst_a->count && v == 1)
	{
		while (lst_a->prev->index <= lst_a->pivot->index)
			reverse(lst_a, 0);
		if (lst_a->next->index <= lst_a->pivot->index)
		{
			push(lst_b, pop(lst_a), 0);
			i++;
		}
		else if (lst_b->next->data < lst_a->pivot->data / 2 && lst_b->count > 1)
			rotate_2(lst_a, lst_b, 1);
		else
			rotate(lst_a, 0);
	}
	while (lst_a->next->was_in_b == 0 && v == 2)
	{
		if (lst_a->next->data <= lst_a->pivot->data)
			push(lst_b, pop(lst_a), 0);
		else if (lst_b->next->data < lst_a->pivot->data / 2 && lst_b->count > 1)
			rotate_2(lst_a, lst_b, 1);
		else
			rotate(lst_a, 0);
	}
}

void	B_to_A(t_list *lst_a, t_list *lst_b)
{
	int		i;

	while (lst_b->count > 0)
	{
		i = 0;
		find_pivot(lst_b, lst_b);
		lst_a->flag++;
		while (i < lst_b->count)
		{
			while (lst_a->next->index == lst_a->next_sort)
			{
				rotate(lst_a, 0);
				lst_a->next_sort++;
			}
			if (lst_b->next->index >= lst_b->pivot->index)
			{
				lst_b->next->was_in_b += lst_a->flag;
				push(lst_a, pop(lst_b), 1);
				i++;
			}
			else
				rotate(lst_b, 1);
		}
	}
}

void	second_A_to_B(t_list *lst_a, t_list *lst_b)
{
	int		was_in_b_stored;

	was_in_b_stored = lst_a->next->was_in_b;
	while (was_in_b_stored == lst_a->next->was_in_b)
	{
		if (lst_a->next->next->index == lst_a->next_sort)
			swap(lst_a, 0);
		solve_A_1(lst_a, lst_b);
		solve_A_2(lst_a, lst_b);
		if (lst_b->next->index == lst_a->next_sort)
			push(lst_a, pop(lst_b), 1);
		if (lst_a->next->index == lst_a->next_sort)
		{
			rotate(lst_a, 0);
			lst_a->next_sort++;
		}
		else
			push(lst_b, pop(lst_a), 0);
	}
}

void	sort_100(t_list *lst_a, t_list *lst_b)
{
	A_to_B(lst_a, lst_b, 1, 0);
	B_to_A(lst_a, lst_b);
	while (lst_a->next->was_in_b > 0)
	{
		second_A_to_B(lst_a, lst_b);
		B_to_A(lst_a, lst_b);
	}
	A_to_B(lst_a, lst_b, 2, 0);
	while (lst_a->prev->index > lst_a->next_sort - 1)
	{
		if (lst_b->prev->index == lst_a->next_sort)
			reverse(lst_a, 0);
		else
			reverse_2(lst_a, lst_b, 1);
	}
	B_to_A(lst_a, lst_b);
	while (is_sorted(lst_a))
	{
		second_A_to_B(lst_a, lst_b);
		B_to_A(lst_a, lst_b);
	}
}
