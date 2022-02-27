/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:04:13 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 16:57:42 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

void	valid_instruction(char *old, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(old, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(old, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(old, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(old, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(old, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(old, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(old, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(old, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(old, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(old, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(old, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		error();
}

void	check_is_ok(t_list **stack_a)
{
	if (check_is_sorted(stack_a) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int			*tab;
	t_list		*stack_b;
	t_list		*stack_a;
	char		*str;

	if (!check_int(av) || !check_double(av))
		error();
	if (ac >= 2)
	{
		tab = array_of_int(av, ac);
		sort_tab(tab, 0, ac - 2);
		stack_a = ft_lstnew(ft_atoi(av[--ac]));
		while (ac > 1)
			ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(av[--ac])));
		content_to_index(stack_a, tab);
		str = get_next_line(0);
		while (str)
		{
			valid_instruction(str, &stack_a, &stack_b);
			free (str);
			str = get_next_line(0);
		}
		free (str);
		check_is_ok(&stack_a);
	}
}
