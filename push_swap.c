/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iharile <iharile@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:44:32 by iharile           #+#    #+#             */
/*   Updated: 2022/02/06 11:53:12 by iharile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_inputs.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!av)
		return (0);
	if (ac == 1 || !check_int(av) || !check_double(av))
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	
	return (0);
}
