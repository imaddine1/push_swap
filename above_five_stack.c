/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   above_five_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:42:30 by iharile           #+#    #+#             */
/*   Updated: 2022/02/18 19:13:29 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	check_stack_b(t_list **stack_b)
{
	int	size;
	int	moves;
	int	last_move;

	size = ft_lstsize(*stack_b);
	moves = size / 3;
	last_move = size - (moves * 3);
}
