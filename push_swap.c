/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:04:06 by prranges          #+#    #+#             */
/*   Updated: 2021/08/03 10:04:09 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_stacks(t_list *lst_a, t_list *lst_b)
{
	lst_a->count = 0;
	lst_a->index = -1;
	lst_a->next_sort = 1;
	lst_a->flag = 0;
	lst_a->next = lst_a;
	lst_a->prev = lst_a;
	lst_b->count = 0;
	lst_b->index = -1;
	lst_b->next = lst_b;
	lst_b->prev = lst_b;
}

void	add(t_list *lst, int number)
{
	t_list	*temp;
	t_list	*p;

	temp = (t_list *)malloc(sizeof(t_list));
	p = lst->prev;
	temp->data = number;
	p->next = temp;
	temp->prev = p;
	lst->prev = temp;
	temp->next = lst;
	temp->index = 0;
	temp->was_in_b = 0;
	lst->count++;
}

t_list	*pop(t_list *lst)
{
	t_list	*pop_list;
	t_list	*p_nn;

	pop_list = NULL;
	if (lst->count > 0)
	{
		pop_list = lst->next;
		p_nn = pop_list->next;
		p_nn->prev = lst;
		lst->next = p_nn;
		lst->count--;
		return (pop_list);
	}
	err_print();
	return (pop_list);
}

void	push(t_list *lst, t_list *pop_list, int x)
{
	t_list	*p_n;

	p_n = lst->next;
	lst->next = pop_list;
	pop_list->prev = lst;
	pop_list->next = p_n;
	p_n->prev = pop_list;
	lst->count++;
	if (x == 0)
	{
		lst->next->was_in_b++;
		write(1, "pb\n", 3);
	}
	if (x == 1)
		write(1, "pa\n", 3);
}
