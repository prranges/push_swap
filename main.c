/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 10:04:41 by prranges          #+#    #+#             */
/*   Updated: 2021/08/03 10:04:45 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_case(t_list *lst_a, t_list *lst_b)
{
	if (lst_a->count <= 3 && lst_a->count > 1)
		sort_3(lst_a, 0);
	if (lst_a->count > 3 && lst_a->count <= 5)
		sort_5(lst_a, lst_b);
	if (lst_a->count > 5)
		sort_100(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (argc < 2)
		exit(1);
	lst_a = (t_list *)malloc(sizeof(t_list));
	lst_b = (t_list *)malloc(sizeof(t_list));
	if (!lst_a || !lst_b)
		exit (1);
	init_stacks(lst_a, lst_b);
	if (argc == 2)
		process_str(lst_a, argv[1]);
	else
		process_array(lst_a, argc, argv);
	index_lst(lst_a);
	if (is_sorted(lst_a) == 0)
	{
		free_stacks(lst_a, lst_b);
		return (0);
	}
	sort_case(lst_a, lst_b);
	free_stacks(lst_a, lst_b);
	return (0);
}
