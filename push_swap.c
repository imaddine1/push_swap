/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:32 by iharile           #+#    #+#             */
/*   Updated: 2022/02/11 18:15:03 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	content_to_index(t_list *new, int *arr)
{
	int		i;
	int		size;

	size = ft_lstsize(new);
	while (new)
	{
		i = 0;
		while (i < size)
		{
			if (new->content == arr[i])
			{
				new->content = i;
				break ;
			}
			i++;
		}
		new = new->next;
	}
}

int	*array_of_int(char **av, int ac)
{
	int	i;
	int	j;
	int	*tab;

	j = 0;
	i = 1;
	tab = malloc(sizeof(int) * (ac - 1));
	while (av[i])
	{
		tab[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	return (tab);
}

void	rr(t_list **g_stack_a, t_list **g_stack_b)
{
	ra(&(*g_stack_a));
	rb(&(*g_stack_b));
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	int		*tab;
	t_list	*g_stack_b;
	t_list	*g_stack_a;

	i = 1;
	j = 0;
	if (!av)
		return (0);
	if (ac == 1 || !check_int(av) || !check_double(av))
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	tab = array_of_int(av, ac);
	sort_tab(tab, 0, ac - 2);
	i = ac;
	g_stack_a = ft_lstnew(ft_atoi(av[--ac]));
	while (ac > 1)
		ft_lstadd_front(&g_stack_a, ft_lstnew(ft_atoi(av[--ac])));
	content_to_index(g_stack_a, tab);
	if (i == 4)
		three_sort(&g_stack_a);
	return (0);
}
