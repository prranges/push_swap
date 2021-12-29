/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:57:11 by prranges          #+#    #+#             */
/*   Updated: 2021/08/19 16:58:29 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_max_int(int result, char str, int sign)
{
	int	max_int;

	max_int = 214748364;
	if (((result > max_int || (result == max_int && (str - '0') > 7))
			&& sign == 1)
		|| ((result > max_int || (result == max_int && (str - '0') > 8))
			&& sign == -1))
		err_print();
	result = result * 10 + (str - '0');
	return (result);
}

void	check_argv(char *str, int i)
{
	int	result;
	int	sign;
	int	num;

	result = 0;
	sign = 1;
	num = 0;
	while (str[i] == '0' && str[i] == '\t')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num++;
			result = check_max_int(result, str[i++], sign);
		}
		else
			err_print();
	}
	if (num == 0)
		err_print();
}

void	process_str(t_list *lst, char *str)
{
	char	**nums;
	size_t	i;

	nums = ft_split(str, ' ');
	i = 0;
	while (nums[i])
		check_argv(nums[i++], 0);
	i = 0;
	while (nums[i])
		add(lst, ft_atoi(nums[i++]));
	free (nums);
}

void	process_array(t_list *lst, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
		check_argv(argv[i++], 0);
	i = 1;
	while (i < argc)
		add(lst, ft_atoi(argv[i++]));
}
