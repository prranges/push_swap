/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:00:42 by prranges          #+#    #+#             */
/*   Updated: 2021/07/13 11:00:53 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"

typedef struct list
{
	int			data;
	int			count;
	int			index;
	int			was_in_b;
	int			next_sort;
	int			flag;
	struct list	*next;
	struct list	*prev;
	struct list	*pivot;
}t_list;

void			init_stacks(t_list *lst_a, t_list *lst_b);
void			add(struct list *lst, int number);
t_list			*pop(t_list *lst);
void			push(t_list *lst, t_list *pop_list, int x);
int				is_sorted(t_list *lst);
void			process_str(t_list *lst, char *str);
void			process_array(t_list *lst, int argc, char **argv);
void			swap(t_list *lst, int x);
void			swap_2(t_list *lst, t_list *lst_b, int x);
void			rotate(t_list *lst, int x);
void			rotate_2(t_list *lst, t_list *lst_b, int x);
void			reverse(t_list *lst, int x);
void			reverse_2(t_list *lst, t_list *lst_b, int x);
void			sort_3(t_list *lst, int i);
void			sort_5(t_list *lst, t_list *lst_b);
void			sort_100(t_list *lst, t_list *lst_b);
void			solve_A_1(t_list *lst_a, t_list *lst_b);
void			solve_A_2(t_list *lst_a, t_list *lst_b);
t_list			*find_min(t_list *lst);
t_list			*find_max(t_list *lst);
void			find_pivot(t_list *lst, t_list *end);
int				index_lst(t_list *lst);
void			free_stacks(t_list *lst_a, t_list *lst_b);
int				err_print(void);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
int				ft_strcmp(const char *s1, const char *s2);

#endif
