/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:03:33 by prranges          #+#    #+#             */
/*   Updated: 2021/08/03 10:03:37 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	swap(t_list *lst, int x)
{
	t_list	*p;
	t_list	*p_n;
	t_list	*p_nn;
	t_list	*p_head;

	if (lst->count > 1)
	{
		p = lst->next;
		p_n = p->next;
		p_nn = p_n->next;
		p_head = lst;
		p_head->next = p_n;
		p_nn->prev = p;
		p->next = p_nn;
		p->prev = p_n;
		p_n->next = p;
		p_n->prev = p_head;
	}
	if (x == 0)
		write(1, "sa\n", 3);
	if (x == 1)
		write(1, "sb\n", 3);
}

void	swap_2(t_list *lst_a, t_list *lst_b, int x)
{
	swap(lst_a, 3);
	swap(lst_b, 3);
	if (x == 1)
		write(1, "ss\n", 3);
}

void	rotate(t_list *lst, int x)
{
	t_list	*p;
	t_list	*p_n;
	t_list	*p_nn;
	t_list	*p_p;

	if (lst->count > 1)
	{
		p = lst;
		p_n = lst->next;
		p_nn = p_n->next;
		p_p = lst->prev;
		p->next = p_n->next;
		p->prev = p_n;
		p_n->next = p;
		p_n->prev = p_p;
		p_p->next = p_n;
		p_nn->prev = p;
	}
	if (x == 0)
		write(1, "ra\n", 3);
	if (x == 1)
		write(1, "rb\n", 3);
}

void	rotate_2(t_list *lst_a, t_list *lst_b, int x)
{
	rotate(lst_a, 3);
	rotate(lst_b, 3);
	if (x == 1)
		write(1, "rr\n", 3);
}
