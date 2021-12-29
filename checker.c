/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:44:46 by prranges          #+#    #+#             */
/*   Updated: 2021/08/18 09:43:50 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	get_commands(char *line, t_list *lst_a, t_list *lst_b)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate(lst_a, 3);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(lst_b, 3);
	else if (ft_strcmp(line, "sa") == 0)
		swap(lst_a, 3);
	else if (ft_strcmp(line, "sb") == 0)
		swap(lst_b, 3);
	else if (ft_strcmp(line, "rra") == 0)
		reverse(lst_a, 3);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse(lst_b, 3);
	else if (ft_strcmp(line, "ss") == 0)
		swap_2(lst_a, lst_b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_2(lst_a, lst_b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_2(lst_a, lst_b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		push(lst_a, pop(lst_b), 3);
	else if (ft_strcmp(line, "pb") == 0)
		push(lst_b, pop(lst_a), 3);
	else
		err_print();
}

void	read_input(t_list *lst_a, t_list *lst_b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		get_commands(line, lst_a, lst_b);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
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
	read_input(lst_a, lst_b);
	if ((is_sorted(lst_a)) == 0 && lst_b->count == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(lst_a, lst_b);
	return (0);
}
