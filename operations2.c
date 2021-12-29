/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:03:45 by prranges          #+#    #+#             */
/*   Updated: 2021/08/03 10:03:45 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	reverse(t_list *lst, int x)
{
	t_list	*p;
	t_list	*p_n;
	t_list	*p_p;
	t_list	*p_pp;

	if (lst->count > 1)
	{
		p = lst;
		p_n = lst->next;
		p_p = lst->prev;
		p_pp = p_p->prev;
		p_n->prev = p_p;
		p->prev = p_pp;
		p_p->next = p_n;
		p_p->prev = p;
		p->next = p_p;
		p_pp->next = p;
	}
	if (x == 0)
		write(1, "rra\n", 4);
	if (x == 1)
		write(1, "rrb\n", 4);
}

void	reverse_2(t_list *lst_a, t_list *lst_b, int x)
{
	reverse(lst_a, 3);
	reverse(lst_b, 3);
	if (x == 1)
		write(1, "rrr\n", 4);
}
