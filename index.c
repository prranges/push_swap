/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:43:41 by prranges          #+#    #+#             */
/*   Updated: 2021/08/18 09:43:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static t_list	*find_next_min(t_list *lst)
{
	t_list	*min;
	t_list	*p;
	int		min_flag;

	p = lst->next;
	min_flag = 0;
	min = NULL;
	while (p != lst)
	{
		if ((p->index == 0) && (min_flag == 0 || p->data < min->data))
		{
			min_flag = 1;
			min = p;
		}
		p = p->next;
	}
	return (min);
}

int	index_lst(t_list *lst)
{
	int		index;
	t_list	*p;
	t_list	*save;

	p = find_next_min(lst);
	save = p;
	index = 1;
	while (p)
	{
		p->index = index++;
		p = find_next_min(lst);
		if (p && p->data == save->data)
			err_print();
		save = p;
	}
	return (0);
}
