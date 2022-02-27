/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:32 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 13:36:52 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	const int	i = ac;
	int			*tab;
	t_list		*stack_b;
	t_list		*stack_a;

	if (!check_int(av) || !check_double(av))
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	tab = array_of_int(av, ac);
	sort_tab(tab, 0, ac - 2);
	stack_a = ft_lstnew(ft_atoi(av[--ac]));
	while (ac > 1)
		ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(av[--ac])));
	content_to_index(stack_a, tab);
	if ((i == 4 || i == 3) && check_is_sorted(&stack_a))
		three_sort(&stack_a, i);
	else if (i == 5 && check_is_sorted(&stack_a))
		four_sort(&stack_a, &stack_b);
	else if (i == 6 && check_is_sorted(&stack_a))
		five_sort(&stack_a, &stack_b, -1);
	if (i > 6)
		above_five(&stack_a, &stack_b);
	return (0);
}
