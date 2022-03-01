/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:57:06 by iharile           #+#    #+#             */
/*   Updated: 2022/02/27 11:22:47 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	merge(int *arr, int lb, int mid, int ub)
{
	int			i;
	int			j;
	int			k;
	int			*newtab;

	i = lb;
	j = mid + 1;
	k = 0;
	newtab = malloc(sizeof(int) * (ub - lb) + 1);
	while (i <= mid && j <= ub)
	{
		if (arr[i] < arr[j])
			newtab[k++] = arr[i++];
		else
			newtab[k++] = arr[j++];
	}
	while (i > mid && j <= ub)
		newtab[k++] = arr[j++];
	while (i <= mid)
			newtab[k++] = arr[i++];
	i = 0;
	while (lb <= ub)
		arr[lb++] = newtab[i++];
	free (newtab);
}

void	sort_tab(int *arr, int lb, int ub)
{
	int	mid;

	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		sort_tab(arr, lb, mid);
		sort_tab(arr, mid + 1, ub);
		merge(arr, lb, mid, ub);
	}
}

int	check_is_sorted(t_list **g_stack_a)
{
	t_list	*head;
	t_list	*consecutive;
	int		i;

	i = 1;
	head = (*g_stack_a);
	consecutive = (*g_stack_a)->next;
	while (consecutive)
	{
		if (head->content < consecutive->content)
			i++;
		head = head->next;
		consecutive = consecutive->next;
	}
	if (i == ft_lstsize((*g_stack_a)))
		return (0);
	return (1);
}

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
/*
int	main(int ac, char **av)
{
	int	i;
	int	*arr;
	int	j;

	j = 0;
	printf ("the number is : %d\n", ac);
	arr = malloc (sizeof(int) * (ac - 1));
	i = 1;
	while (i < ac)
	{
		arr[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	printf ("Before SORT\n");
	i = 0;
	while (i < ac - 1)
	{
		printf ("%d ",arr[i]);
		i++;
	}
	printf ("\nAfter SORT\n");
	sort_tab(arr, 0, ac - 2);
	i = 0;
	while (i < ac - 1)
	{
		printf ("%d ", arr[i]);
		i++;
	}
	return (0);
}
*/