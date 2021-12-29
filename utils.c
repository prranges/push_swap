/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:10:49 by prranges          #+#    #+#             */
/*   Updated: 2021/08/03 10:04:45 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_stacks(t_list *lst_a, t_list *lst_b)
{
	int		i;
	t_list	*p;
	t_list	*temp;

	i = 0;
	p = lst_a->next;
	while (i < lst_a->count)
	{
		temp = p;
		p = p->next;
		free(temp);
		i++;
	}
	i = 0;
	p = lst_b->next;
	while (i < lst_b->count)
	{
		temp = p;
		p = p->next;
		free(temp);
		i++;
	}
	free(lst_a);
	free(lst_b);
}

int	err_print(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_list *lst)
{
	t_list	*p;

	p = lst->next;
	while (p != lst->prev)
	{
		if (p->index > p->next->index)
			return (1);
		p = p->next;
	}
	return (0);
}
