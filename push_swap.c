/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:32 by iharile           #+#    #+#             */
/*   Updated: 2022/02/09 13:16:10 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	content_to_index(t_list *head, int *arr)
{
	int		i;
	t_list	*new;
	int		size;

	size = ft_lstsize(head);
	printf("the length is %d\n", size);
	new = head;
	while (new)
	{
		//printf ("first elem of node is %d\n", new->content);
		i = 0;
		while (i < size)
		{
			//printf ("first elem of array is %d\n", arr[i]);
			if (new->content == arr[i])
			{
				new->content = i;
				break ;
			}
			i++;
		}
		new = new->next;
	}
	new = head;
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
	sort_tab(tab, 0, ac - 2);
	i = 0;
	while (i < ac - 1)
	{
		printf ("%d\n", tab[i]);
		i++;
	}
	first = ft_lstnew(ft_atoi(av[--ac]));
	while (ac > 1)
		ft_lstadd_front(&first, ft_lstnew(ft_atoi(av[--ac])));
	content_to_index(first, tab);
	printf ("----------------\n");
	while (first)
	{
		printf ("%d\n", first->content);
		first = first->next;
	}
	return (0);
}
