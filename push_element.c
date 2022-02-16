/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:42:55 by iharile           #+#    #+#             */
/*   Updated: 2022/02/16 13:51:17 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	the_top(t_list **g_stack_a, t_list **g_stack_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(g_stack_a);
		i++;
	}
	pb(g_stack_a, g_stack_b);
	return (1);
}

int	the_bottom(t_list **g_stack_a, t_list **g_stack_b, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		rra(g_stack_a);
		i++;
	}
	pb(g_stack_a, g_stack_b);
	return (1);
}
