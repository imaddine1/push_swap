/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:32 by iharile           #+#    #+#             */
/*   Updated: 2022/02/08 18:57:44 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_list	*first;
	int		*tab;

	i = 1;
	j = 0;
	if (!av)
		return (0);
	if (ac == 1 || !check_int(av) || !check_double(av))
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	tab = array_of_int(av, ac);
	sort_tab(tab, 0, ac - 1);
	first = ft_lstnew(ft_atoi(av[--ac]));
	while (ac > 1)
		ft_lstadd_front(&first, ft_lstnew(ft_atoi(av[--ac])));
	while (first)
	{
		printf ("%d\n", first->content);
		first = first->next;
	}
	return (0);
}
