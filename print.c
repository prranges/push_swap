/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:04:41 by prranges          #+#    #+#             */
/*   Updated: 2021/08/03 10:04:45 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	print(t_list *lst)
{
	t_list	*p;

	p = lst->next;
	while (p != lst)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void	rev_print(t_list *lst)
{
	t_list	*p;

	p = lst->prev;
	while (p != lst)
	{
		printf("%d ", p->data);
		p = p->prev;
	}
	printf("\n");
}
